// main.cpp
#include "singly.hpp"
#include "has_cycle.hpp"
#include <vector>
#include <iostream>

int main()
{
    // Test case with cycle
    SinglyLinkedList sll1;
    std::vector<ListNode::Ptr> nodes1;
    std::vector<int> data = {3, 2, 1, 4};
    for (auto &val : data)
    {
        nodes1.push_back(std::make_shared<ListNode>(val));
    }
    for (const auto &node : nodes1)
    {
        sll1.add_to_end(node);
    }
    // Add cycle
    sll1.add_to_end(nodes1[1]);

    // Test case without cycle
    SinglyLinkedList sll2;
    std::vector<ListNode::Ptr> nodes2;
    for (int i = 0; i < 5; i++)
    {
        nodes2.push_back(std::make_shared<ListNode>(i));
    }
    for (const auto &node : nodes2)
    {
        sll2.add_to_end(node);
    }

    std::vector<SinglyLinkedList> testCases = {sll1, sll2};
    for (const auto &sll : testCases)
    {
        bool cycle = hasCycle(sll.head);
        std::cout << "The linked list " << (cycle ? "has" : "does not have") << " a cycle" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
