// main.cpp
#include "doubly.hpp"
#include <iostream>
#include <vector>

int main()
{
    DoublyLinkedList dll;
    std::vector<ListNode::Ptr> nodes;
    for (int i = 1; i <= 5; ++i)
    {
        nodes.push_back(std::make_shared<ListNode>(i));
    }

    for (const auto &node : nodes)
    {
        std::cout << "Adding " << *node << " to the end of the doubly linked list" << '\n';
        dll.add_to_end(node);
    }

    std::cout << "Current state of the doubly linked list: " << '\n';
    dll.display();

    std::cout << "Removing the first node" << '\n';
    dll.remove_from_start();
    dll.display();


    std::cout << "Removing the last node" << '\n';
    dll.remove_from_end();
    dll.display();

    std::cout << "Adding a node to the start" << '\n';
    dll.add_to_start(std::make_shared<ListNode>(23));
    dll.display();

    std::cout << "Adding a node at index 2" << '\n';
    dll.add_at_index(2, std::make_shared<ListNode>(99));
    dll.display();

    std::cout << "Removing a node at index 4" << '\n';
    dll.remove_at_index(4);
    dll.display();

    return 0;
}
