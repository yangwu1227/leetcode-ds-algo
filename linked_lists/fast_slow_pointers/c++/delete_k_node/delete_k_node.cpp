// delete_k_node.cpp
#include "delete_k_node.hpp"
#include "node.hpp"

ListNode::Ptr deleteKthNode(const ListNode::Ptr &head, int k)
{
    // Single node after sentinel head
    if (head->next->next == nullptr)
    {
        // Remove the single node as it is considered the middle node
        head->next = nullptr;
        return head;
    }

    // Shared pointers instead of raw pointers
    ListNode::Ptr fast = head;
    ListNode::Ptr slow = head;
    ListNode::Ptr prev = head;

    // Move the fast pointer k steps ahead of slow
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }

    // Move fast and slow pointers at the same speed and use prev to track the (k - 1)th node
    while (fast != nullptr)
    {
        fast = fast->next;
        // Set prev to slow before iterating slow to the next node
        prev = slow;
        slow = slow->next;
    }

    // Remove the node pointed to by the slow pointer
    prev->next = slow->next;

    return head;
}
