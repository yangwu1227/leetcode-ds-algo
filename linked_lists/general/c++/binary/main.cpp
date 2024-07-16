// main.cpp
#include "binary.hpp"
#include "node.hpp"
#include "singly.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> dataArrays = {
        {1, 0, 1},
        {1, 1, 1},
        {1, 0, 0, 1, 0, 1, 0}};

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

        std::cout << "Binary representation:'\n";
        sll.display();
        int decimalValue = getDecimal(sll.head);
        std::cout << "The decimal value is " << decimalValue << '\n';
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
