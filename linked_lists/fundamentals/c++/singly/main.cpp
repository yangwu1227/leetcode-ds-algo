// main.cpp
#include "singly.hpp"
#include <iostream>

int main()
{
    Nodes *one = new Nodes(1);
    Nodes *two = new Nodes(2);
    Nodes *three = new Nodes(3);
    Nodes *four = new Nodes(4);
    Nodes *five = new Nodes(5);

    // The '->' operator is used to call methods on the object that the pointer points to
    // It is equivalent to dereferencing the pointer and then accessing the member: (*one).setNext(two)
    one->setNext(two);
    two->setNext(three);
    three->setNext(four);
    four->setNext(five);

    // Modify data of the first two nodes
    one->setData(10);
    two->setData(20);

    Nodes *currentNode = one;
    while (currentNode != nullptr)
    {
        std::cout << "Node data: " << currentNode->getData() << std::endl;
        currentNode = currentNode->getNext();
    }

    return 0;
}
