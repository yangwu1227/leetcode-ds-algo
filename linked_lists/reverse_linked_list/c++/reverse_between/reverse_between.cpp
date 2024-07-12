// reverse_between.cpp
#include "reverse_between.hpp"
#include "node.hpp"

ListNode::Ptr reverseBetween(const ListNode::Ptr &head, int left, int right)
{
    // Single node case
    if (head->next->next == nullptr)
    {
        return head;
    }
    // Special case where left == right
    if (left == right)
    {
        return head;
    }

    ListNode::Ptr current = head;
    // Let left = 3 and right = 5: head -> 1 -> 2 -> [3 -> 4 -> 5] -> 6 -> 7
    for (int i = 0; i < left - 1; i++)
    {
        current = current->next;
    }

    // At this point, current is 2, keep a reference of it
    ListNode::Ptr nodeBeforeLeft = current;
    // Set leftNode = current = 3
    current = current->next;
    ListNode::Ptr leftNode = current;
    ListNode::Ptr prev = nullptr;
    // Reverse from left to right
    for (int i = 0; i < right - left + 1; i++)
    {
        ListNode::Ptr nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    // At this point, prev points to 5, so set (nodeBeforeLeft = 2) -> (prev = 5) -> 4 -> (leftNode = 3) -> nullptr
    nodeBeforeLeft->next = prev;
    // In addition, current points to 6, so set (leftNode = 3) -> (current = 6) -> 7 -> nullptr
    leftNode->next = current;

    return head;
}
