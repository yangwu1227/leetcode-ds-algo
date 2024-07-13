#include "reverse_group.hpp"
#include "node.hpp"

ListNode::Ptr reverseGroup(ListNode::Ptr &startNode, int groupLength)
{
    // Pointers for reversal
    ListNode::Ptr prev = nullptr;
    ListNode::Ptr current = startNode;
    // Given groupLength = 3 and group: (startNode = current = currentGroupA) -> currentGroupB -> currentGroupC -> nextGroupA -> ...
    while (groupLength > 0)
    {
        ListNode::Ptr nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
        groupLength--;
    }

    // Connect the current and next groups: (prev = currentGroupC) -> currentGroupB -> (startNode = currentGroupA) -> (current = nextGroupA) -> ...
    startNode->next = current;
    // Return the new first node of the group so we can connect the previous group to this group
    return prev;
}
