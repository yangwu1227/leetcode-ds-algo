// main.cpp
#include "odd_even_list.hpp"
#include "node.hpp"
#include "singly.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> dataArrays = {
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1},
        {1, 2}};

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

        std::cout << "Before reordering\n";
        sll.display();
        ListNode::Ptr newHead = oddEvenList(sll.head);
        std::cout << "After reordering\n";
        sll.display();
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
