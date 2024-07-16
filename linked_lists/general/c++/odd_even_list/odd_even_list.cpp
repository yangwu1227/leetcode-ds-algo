// odd_even_list.cpp
#include "odd_even_list.hpp"
#include "node.hpp"

ListNode::Ptr oddEvenList(const ListNode::Ptr &head)
{
    // Empty list
    if (head->next == nullptr)
    {
        return head;
    }
    // Single or two nodes
    if (head->next->next == nullptr || head->next->next->next == nullptr)
    {
        return head;
    }

    ListNode::Ptr prev = head;
    ListNode::Ptr current = head->next;
    // Keep a reference to the first even node
    ListNode::Ptr firstEvenNode = head->next->next;
    int length = 0;
    while (current->next != nullptr)
    {
        // Keep a reference to the next node
        ListNode::Ptr nextNode = current->next;
        // Skip a node to connect even with even and odd with odd
        current->next = current->next->next;
        // Iterate and increment length
        prev = current;
        current = nextNode;
        length++;
    }
    // When the loop finishes, length = n - 1 since the last node is not counted due to the current->next != nullptr condition
    length++;

    // If odd, then the current pointer is pointing at the last odd node
    if (length % 2 != 0)
    {
        current->next = firstEvenNode;
    }
    else
    {
        // If even, then the prev pointer is pointing at the last odd node
        prev->next = firstEvenNode;
    }

    return head;
}
