// main.cpp
#include "node.hpp"
#include "k_node.hpp"
#include "singly.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main()
{
    std::map<std::vector<int>, int> testCases = {
        {{12, 9, 6, 8, 7, 14}, 3},
        {{12, 4, 5, 6, 7, 23, 98, 56, 0, 34, 47, 12, 127}, 5}};

    for (auto &[dataVector, k] : testCases)
    {
        SinglyLinkedList sll;
        std::vector<ListNode::Ptr> nodes;

        nodes.reserve(dataVector.size());
        std::transform(
            dataVector.begin(), dataVector.end(), std::back_inserter(nodes),
            [](int data)
            { return std::make_shared<ListNode>(data); });

        for (auto &node : nodes)
        {
            sll.add_to_start(node);
        }

        ListNode::Ptr kth = kthNode(sll.head, k);
        sll.display();
        std::cout << "The k = " << k << " node of the above linked list is " << *kth << '\n';
    }
    std::cout << std::endl;

    return 0;
}
