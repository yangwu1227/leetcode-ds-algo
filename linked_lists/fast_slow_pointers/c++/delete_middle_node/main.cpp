// main.cpp
#include "node.hpp"
#include "delete_middle_node.hpp"
#include "singly.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<std::vector<int>> testCases = {
        {1, 3, 4, 7, 1, 2, 6},
        {1, 2, 3, 4},
        {2, 1},
        {1}};

    for (const auto &dataArray : testCases)
    {
        std::vector<ListNode::Ptr> nodes;
        nodes.reserve(dataArray.size());
        std::transform(
            std::cbegin(dataArray), std::cend(dataArray), std::back_inserter(nodes),
            // Lambada function
            [](int data)
            { return std::make_shared<ListNode>(data); });

        SinglyLinkedList sll;
        for (const auto &node : nodes)
        {
            sll.add_to_end(node);
        }

        std::cout << "Before removing the middle node\n";
        sll.display();
        ListNode::Ptr head = deleteMiddleNode(sll.head);
        std::cout << "After removing the middle node\n";
        sll.display();
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
