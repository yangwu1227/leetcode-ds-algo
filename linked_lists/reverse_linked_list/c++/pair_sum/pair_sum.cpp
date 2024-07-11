// pair_sum.cpp
#include "pair_sum.hpp"
#include "node.hpp"

int pairSum(const ListNode::Ptr &head)
{
    // Two nodes only
    if (head->next->next->next == nullptr)
    {
        return head->next->data + head->next->next->data;
    }

    // Find the middle of the linked list
    ListNode::Ptr fastMiddle = head;
    ListNode::Ptr slowMiddle = head;
    int length = 0;
    while (fastMiddle != nullptr && fastMiddle->next != nullptr)
    {
        fastMiddle = fastMiddle->next->next;
        slowMiddle = slowMiddle->next;
        length += 1;
    }
    length *= 2;

    // Reverse the second half of the list
    ListNode::Ptr prev = nullptr;
    ListNode::Ptr lastNodeFirstHalf = slowMiddle;
    ListNode::Ptr lastNodeSecondHalf = fastMiddle;
    ListNode::Ptr current = slowMiddle->next;
    while (current != nullptr)
    {
        // Keep a refernce to the next node
        ListNode::Ptr nextNode = current->next; // Reverse the current node to point to the previous node
        current->next = prev;
        // The current node should now become the previous of the next current node
        prev = current;
        // Move the current pointer to the next node
        current = nextNode;
    }
    // To connect the first half with the reversed second half
    lastNodeFirstHalf->next = lastNodeSecondHalf;

    // Find maximum twin sum
    ListNode::Ptr fastSum = head;
    ListNode::Ptr slowSum = head;
    for (int i = 0; i < length / 2; i++)
    {
        fastSum = fastSum->next;
    }
    int maxSum = 0;
    while (fastSum != nullptr && fastSum->next != nullptr)
    {
        maxSum = std::max(fastSum->next->data + slowSum->next->data, maxSum);
        fastSum = fastSum->next;
        slowSum = slowSum->next;
    }
    return maxSum;
}
