// main.cpp
#include "remove_elements.hpp"
#include "node.hpp"
#include "singly.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::map<std::vector<int>, int> dataArrays = {
        {{1, 2, 6, 3, 4, 5, 6}, 6},
        {{5, 2}, 2},
        {{1, 1, 1, 1}, 1}};

    for (const auto &[dataArray, data] : dataArrays)
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

        std::cout << "Before removing " << data << '\n';
        sll.display();
        ListNode::Ptr newHead = removeElements(sll.head, data);
        std::cout << "After removing " << data << '\n';
        sll.display();
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
