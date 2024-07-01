// singly.cpp
#include "singly.hpp"

Nodes::Nodes(int data) : data(data), next(nullptr) {}

int Nodes::getData() const
{
    return data;
}

void Nodes::setData(int data)
{
    // The 'this' pointer is passed as a hidden argument to all nonstatic member functions; it is the object for which a member function is called
    this->data = data;
}

Nodes *Nodes::getNext() const
{
    // The 'next' pointer points to the next 'Nodes' object in the linked list, if there is none, next will be a 'nullptr'
    return next;
}

void Nodes::setNext(Nodes *nextNode)
{
    next = nextNode;
}
