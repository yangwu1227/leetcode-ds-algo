// binary.cpp
#include "binary.hpp"
#include "node.hpp"

int getDecimal(const ListNode::Ptr &head)
{
    int decimalValue = 0;
    ListNode::Ptr current = head->next;
    while (current != nullptr)
    {
        decimalValue = (decimalValue << 1) | current->data;
        current = current->next;
    }
    return decimalValue;
}
