// main.cpp
#include "doubly.hpp"
#include <iostream>
#include <vector>

int main()
{
    DoublyLinkedList dll;
    std::vector<Node::Ptr> nodes;
    for (int i = 1; i <= 5; ++i)
    {
        nodes.push_back(std::make_shared<Node>(i));
    }

    for (const auto &node : nodes)
    {
        std::cout << "Adding " << *node << " to the end of the doubly linked list" << std::endl;
        dll.add_to_end(node);
    }

    std::cout << "Current state of the doubly linked list: " << std::endl;
    dll.display();

    std::cout << "Removing the first node" << std::endl;
    dll.remove_from_start();
    dll.display();

    std::cout << "Removing the last node" << std::endl;
    dll.remove_from_end();
    dll.display();

    return 0;
}
