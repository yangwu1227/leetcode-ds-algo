// k_node.cpp
#include "k_node.hpp"
#include "node.hpp"

ListNode::Ptr kthNode(const ListNode::Ptr &head, int k)
{
    // Pointers
    ListNode::Ptr fast = head;
    ListNode::Ptr slow = head;

    // Fast foward the fast pointer
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }

    // Move both pointers at the same pace until the end
    while (fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}
