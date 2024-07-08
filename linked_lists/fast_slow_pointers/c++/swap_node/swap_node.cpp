// swap_node.cpp
#include "swap_node.hpp"
#include "node.hpp"

ListNode::Ptr swapNode(const ListNode::Ptr &head, int k)
{
    // Single node case
    if (head->next->next == nullptr)
    {
        return head;
    }

    ListNode::Ptr fast = head;
    ListNode::Ptr slow = head;

    // Move the fast pointer k steps ahead
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }

    // Keep a reference to the kth node from the start
    ListNode::Ptr kthFromStart = fast;
    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Swap the data
    std::swap(slow->data, kthFromStart->data);

    return head;
}
