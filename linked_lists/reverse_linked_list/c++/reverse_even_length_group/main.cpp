// main.cpp
#include "reverse_even_length_group.hpp"
#include "reverse_group.hpp"
#include "node.hpp"
#include "singly.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> dataArrays = {
        {5, 2, 6, 3, 9, 1, 7, 3, 8, 4},
        {5, 2},
        {1, 1, 0, 6, 5},
        {1}};

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
        ListNode::Ptr newHead = reverseEvenLengthGroup(sll.head);
        std::cout << "After reversing\n";
        sll.display();
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
