// main.cpp
#include "remove_duplicates_II.hpp"
#include "node.hpp"
#include "singly.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    // Test cases
    std::vector<std::vector<int>> dataArrays = {
        {1, 1, 1, 2, 3, 3, 4},
        {1, 1, 1, 2, 3},
        {1},
        {1, 2, 3, 3, 4, 4, 5},
        {1, 1, 1}};

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

        std::cout << "Before removing all duplicates\n";
        sll.display();
        ListNode::Ptr dedupedHead = removeDuplicates(sll.head);
        std::cout << "After removing all duplicates\n";
        sll.display();
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
