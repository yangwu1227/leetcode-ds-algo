// middle_node.cpp
#include "middle_node.hpp"
#include "node.hpp"

ListNode::Ptr middleNode(const ListNode::Ptr &head)
{
    // Pointers
    auto fast = head;
    auto slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
