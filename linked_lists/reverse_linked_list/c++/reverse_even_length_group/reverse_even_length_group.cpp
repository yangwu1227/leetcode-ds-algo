// reverse_even_length_group.cpp
#include "reverse_even_length_group.hpp"
#include "reverse_group.hpp"
#include "node.hpp"

ListNode::Ptr reverseEvenLengthGroup(ListNode::Ptr &head)
{
    // Single or two nodes
    if (head->next->next == nullptr)
    {
        return head;
    }
    if (head->next->next->next == nullptr)
    {
        return head;
    }

    // Initialize to sentinel head and first real node
    ListNode::Ptr lastNodePrevGroup = head;
    ListNode::Ptr current = head->next;
    int expectedGroupLength = 1;
    while (current != nullptr)
    {
        // Determine the actual length of the current group
        int actualGroupLength = 0;
        // Keep a reference to the start of the group so we can reverse it if needed
        ListNode::Ptr startNode = current;
        while (actualGroupLength < expectedGroupLength && current != nullptr)
        {
            current = current->next;
            actualGroupLength++;
        }

        // If the actual length is even, reverse the group
        if (actualGroupLength % 2 == 0)
        {
            // Connect the previous group to the next first node of the current group
            lastNodePrevGroup->next = reverseGroup(startNode, actualGroupLength);
        }

        // Move 'lastNodePrevGroup' to the end of the current group in preparation for the next group
        for (int i = 0; i < actualGroupLength; i++)
        {
            lastNodePrevGroup = lastNodePrevGroup->next;
        }
        expectedGroupLength++;
    }

    return head;
}
