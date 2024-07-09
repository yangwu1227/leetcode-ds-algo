// remove_duplicates_II.cpp
#include "remove_duplicates_II.hpp"
#include "node.hpp"

ListNode::Ptr removeDuplicates(const ListNode::Ptr &head)
{
    // Empty or single node
    if (head->next == nullptr)
    {
        return head;
    }
    if (head->next->next == nullptr)
    {
        return head;
    }

    // Pointers
    ListNode::Ptr slow = head;
    ListNode::Ptr fast = head->next;

    while (fast != nullptr)
    {
        // As long as there are duplicates, keep moving the fast pointer forward
        while (fast->next != nullptr && fast->data == fast->next->data)
        {
            fast = fast->next;
        }

        // Check if next pointer of slow and fast are pointing to the same node
        if (slow->next == fast)
        {
            // If so, fast is still one step ahead of slow, no duplicates detected
            slow = slow->next;
        }
        else
        {
            // If fast is pointing to a node not pointed to by slow->next, duplicates were detected, skip the slow poitner to the next unique node
            slow->next = fast->next;
        }

        // Move the fast pointer
        fast = fast->next;
    }

    return head;
}
