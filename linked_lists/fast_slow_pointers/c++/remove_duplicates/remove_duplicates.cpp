// remove_duplicates.cpp
#include "remove_duplicates.hpp"
#include "node.hpp"

ListNode::Ptr removeDuplicates(const ListNode::Ptr &head)
{
    // Dummy reference to head for traversal
    ListNode::Ptr current = head;
    while (current != nullptr && current->next != nullptr)
    {
        // If the current node and the next nodes are duplicated, remove the next node
        if (current->data == current->next->data)
        {
            // Skip the next (duplicated) node by setting the next pointer of the current node to node after the currently next node
            current->next = current->next->next;
        }
        else
        {
            // If the current node is not a duplicate of the next node, step to the next node
            current = current->next;
        }
    }

    return head;
}
