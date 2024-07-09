// main.cpp
#include "reverse.hpp"
#include "node.hpp"
#include "singly.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> dataArrays = {
        {1, 2, 3, 4, 5},
        {9},
        {7, 12, 27},
        {12, 24, 48}};

    for (const auto &dataArray : dataArrays)
    {
        std::vector<ListNode::Ptr> nodes;
        nodes.reserve(dataArray.size());
        std::transform(
            std::cbegin(dataArray), std::cend(dataArray), std::back_inserter(nodes),
            [](int data)
            { return std::make_shared<ListNode>(data); });

        SinglyLinkedList sll;
        for (const auto &node : nodes)
        {
            sll.add_to_end(node);
        }

        std::cout << "Before reversing\n";
        sll.display();
        ListNode::Ptr reversedHead = reverse(sll.head);
        std::cout << "After reversing\n";
        sll.display();
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
