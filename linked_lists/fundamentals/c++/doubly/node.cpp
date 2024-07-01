// node.cpp
#include "node.hpp"
#include <memory>
#include <iostream>

Node::Node(int data) : data(data) {}

std::ostream &operator<<(std::ostream &os, const Node &node)
{
    os << "Node(data = " << node.data << ")";
    return os;
}
