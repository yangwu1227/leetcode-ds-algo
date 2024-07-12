// main.cpp
#include "reverse_between.hpp"
#include "singly.hpp"
#include "node.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

int main()
{
    std::map<std::vector<int>, std::pair<int, int>> testCases = {
        {{1, 2, 3, 4, 5, 6, 7}, {3, 5}},
        {{1, 2, 3, 4}, {3, 3}},
        {{2}, {1, 1}}};

    for (const auto &[dataArray, pair] : testCases)
    {
        std::vector<std::shared_ptr<ListNode>> nodes;
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

        std::cout << "Before reversing'\n";
        sll.display();
        ListNode::Ptr newHead = reverseBetween(sll.head, pair.first, pair.second);
        std::cout << "After reversing between node = " << pair.first << " and node = " << pair.second << '\n';
        sll.display();
        std::cout << '\n';
    }
    std::cout << std::endl;
}
