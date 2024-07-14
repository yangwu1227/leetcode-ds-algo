#include "singly.hpp"
#include <iostream>
#include <vector>

int main()
{
    SinglyLinkedList sll;
    std::vector<ListNode::Ptr> nodes;
    for (int i = 1; i <= 5; ++i)
    {
        nodes.push_back(std::make_shared<ListNode>(i));
    }

    for (const auto &node : nodes)
    {
        std::cout << "Adding " << *node << " to the end of the singly linked list" << '\n';
        sll.add_to_end(node);
    }

    std::cout << "Current state of the singly linked list: " << '\n';
    sll.display();

    std::cout << "Removing the first node" << '\n';
    sll.remove_from_start();
    sll.display();

    std::cout << "Removing the last node" << '\n';
    sll.remove_from_end();
    sll.display();

    std::cout << "Adding a node to the start" << '\n';
    sll.add_to_start(std::make_shared<ListNode>(8));
    sll.display();

    return 0;
}
