// main.cpp
#include "node.hpp"
#include "delete_k_node.hpp"
#include "singly.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

int main()
{
    std::map<std::vector<int>, int> testCases = {
        {{1, 2}, 2},
        {{1, 2, 2}, 1},
        {{1, 2, 3, 4, 5}, 2},
        {{1}, 1},
        {{2, 7, 12, 5, 9, 8, 13, 17}, 5}};

    for (const auto &[dataArray, k] : testCases)
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

        std::cout << "Before removing the k = " << k << " node\n";
        sll.display();
        ListNode::Ptr head = deleteKthNode(sll.head, k);
        std::cout << "After removing the k = " << k << " node\n";
        sll.display();
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
