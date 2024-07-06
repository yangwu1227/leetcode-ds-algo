// delete_middle_node.cpp
#include "delete_middle_node.hpp"
#include "node.hpp"

ListNode::Ptr deleteMiddleNode(const ListNode::Ptr &head)
{
    // Single node after sentinel head
    if (head->next->next == nullptr)
    {
        // Remove the single node as it is considered the middle node
        head->next = nullptr;
        return head;
    }

    // Shared pointers instead of raw pointers
    ListNode::Ptr fast = head->next;
    ListNode::Ptr slow = head->next;
    ListNode::Ptr prev = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        // Set prev to slow before iterating slow to the next node
        prev = slow;
        slow = slow->next;
    }

    // Remove the node pointed to by the slow pointer
    prev->next = slow->next;

    return head;
}
