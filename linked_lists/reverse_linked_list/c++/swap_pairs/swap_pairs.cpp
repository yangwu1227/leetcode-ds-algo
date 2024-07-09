// swap_pairs.cpp
#include "swap_pairs.hpp"
#include "node.hpp"

ListNode::Ptr swapPairs(const ListNode::Ptr &head)
{
    // Single node or empty list
    if (head->next == nullptr)
    {
        return head;
    }
    if (head->next->next == nullptr)
    {
        return head;
    }

    // Initialize pointers
    ListNode::Ptr prev = head;
    // First real node
    ListNode::Ptr current = head->next;
    // As long as there are two nodes to swap
    while (current != nullptr && current->next != nullptr)
    {
        // Identify pairs to swap: prev -> first -> second -> next_first -> next_second
        ListNode::Ptr first = current;
        ListNode::Ptr second = current->next;

        // Step 1: prev -> (first & second) -> next_first -> next_second
        first->next = second->next;
        // Step 2: (second & prev) -> first -> next_first -> next_second
        second->next = first;
        // Step 3: prev -> second -> first -> next_first -> next_second
        prev->next = second;

        // After the swap, update prev to the new second node: (prev = first) -> next_first -> next_second
        prev = first;
        // Move current to the next first node for the next iteration: (prev = first) -> (current = next_first) -> next_second
        current = first->next;
    }

    return head;
}
