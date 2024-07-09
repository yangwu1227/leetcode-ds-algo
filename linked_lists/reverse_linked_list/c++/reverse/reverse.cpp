// reverse.cpp
#include "reverse.hpp"
#include "node.hpp"

ListNode::Ptr reverse(const ListNode::Ptr &head)
{
    ListNode::Ptr prev = nullptr;
    // Pointer to the first real node
    ListNode::Ptr current = head->next;
    while (current != nullptr)
    {
        // Keep a reference to the next pointer of the current node
        ListNode::Ptr nextNode = current->next;
        // Point the next pointer of the current node to the previous node
        current->next = prev;
        // The current node should now become the new previous node
        prev = current;
        // To continue with the loop, the current pointer should now point to the original next node to the right
        current = nextNode;
    }

    // The next pointer of the original sentinel head node should now point to the new first node
    head->next = prev;
    return head;
}
