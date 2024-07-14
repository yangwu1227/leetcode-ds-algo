// node.cpp
#include "node.hpp"
#include <memory>
#include <iostream>

ListNode::ListNode(int data) : data(data) {}

std::ostream &operator<<(std::ostream &os, const ListNode &node)
{
    os << "ListNode(data = " << node.data << ")";
    return os;
}
