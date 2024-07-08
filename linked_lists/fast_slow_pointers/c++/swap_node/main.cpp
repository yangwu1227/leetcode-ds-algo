// main.cpp
#include "swap_node.hpp"
#include "node.hpp"
#include "singly.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::map<std::vector<int>, int> testCases = {
        {{1, 2, 3, 4, 5}, 2},
        {{7, 9, 6, 6, 7, 8, 3, 0, 9, 5}, 5},
        {{7}, 1}};

    for (const auto &[dataArray, k] : testCases)
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

        std::cout << "Before swapping data values between the k = " << k << " nodes from start and end\n";
        sll.display();
        ListNode::Ptr newHead = swapNode(sll.head, k);
        std::cout << "After swapping data values\n";
        sll.display();
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
