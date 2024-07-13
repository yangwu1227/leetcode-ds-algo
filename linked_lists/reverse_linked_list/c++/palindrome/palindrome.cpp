// palindrome.cpp
#include "palindrome.hpp"
#include "node.hpp"

bool palindrome(const ListNode::Ptr &head)
{
    // Single node
    if (head->next->next == nullptr)
    {
        return true;
    }

    /* ----------------------------- Find the middle ---------------------------- */

    ListNode::Ptr fast = head;
    ListNode::Ptr slow = head;
    // Odd case: head -> 1 -> 2 -> 2 -> 3 -> 2 -> 2 -> 1 -> nullptr
    // Even case: head -> 1 -> 2 -> 2 -> 2 -> 2 -> 1 -> nullptr
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    /* --------------------------------- Reverse -------------------------------- */

    // Odd case: head -> 1 -> 2 -> (slow = 2) -> (current = 3) -> 2 -> 2 -> 1 -> nullptr
    // Even case: head -> 1 -> 2 -> (slow = 2) -> (current = 2) -> 2 -> 1 -> nullptr
    ListNode::Ptr prev = nullptr;
    ListNode::Ptr current = slow->next;
    while (current != nullptr)
    {
        ListNode::Ptr nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    // Odd case: head -> 1 -> 2 -> 2 -> (prev = firstNodeReversed = 1) -> 2 -> 2 -> 3 -> nullptr
    // Even case: head -> 1 -> 2 -> 2 -> (prev = firstNodeReversed = 2) -> 2 -> 1 -> nullptr

    /* ------------------------------ Compare nodes ----------------------------- */

    // Initialized to the first real node
    ListNode::Ptr firstHalfPointer = head->next;
    // Initialized to the first node of the reversed section
    ListNode::Ptr secondHalfPointer = prev;
    while (secondHalfPointer != nullptr)
    {
        if (firstHalfPointer->data != secondHalfPointer->data)
        {
            return false;
        }
        firstHalfPointer = firstHalfPointer->next;
        secondHalfPointer = secondHalfPointer->next;
    }

    return true;
}
