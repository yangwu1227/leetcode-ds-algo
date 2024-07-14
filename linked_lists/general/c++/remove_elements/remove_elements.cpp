// remove_elements.cpp
#include "remove_elements.hpp"
#include "node.hpp"

ListNode::Ptr removeElements(ListNode::Ptr &head, int data)
{
    // Empty list
    if (head->next == nullptr)
    {
        return head;
    }
    // Initialize to sentinel head and first real node
    ListNode::Ptr prev = head;
    ListNode::Ptr current = head->next;
    while (current != nullptr)
    {
        if (current->data == data)
        {
            // If the data matches, perform a skip: prev -> [current] -> current->next
            prev->next = current->next;
        }
        else
        {
            // If no match, just move the previous pointer
            prev = prev->next;
        }
        // For both cases, move the current pointer for next iteration
        current = current->next;
    }

    return head;
}
