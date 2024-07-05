// main.cpp
#include "singly.hpp"
#include "middle_node.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::vector<int>> testCases = {
        {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5, 6, 7, 8}, {12, 17}, {12, 17, 8, 7}};

    for (auto &testCase : testCases)
    {
        SinglyLinkedList sll;
        std::vector<ListNode::Ptr> nodes;

        // Create a vector of pointers
        nodes.reserve(testCase.size());
        std::transform(
            testCase.begin(), testCase.end(), std::back_inserter(nodes),
            // Lambda function
            [](int data)
            { return std::make_shared<ListNode>(data); });

        for (auto &node : nodes)
        {
            sll.add_to_end(node);
        }

        // Pass the first real node after the sentinel head node
        ListNode::Ptr middle = middleNode(sll.head->next);

        sll.display();
        // Dereference the shared pointer
        std::cout << "The middle node of the linked list above is " << *middle << '\n';
    }
    std::cout << std::endl;

    return 0;
}
