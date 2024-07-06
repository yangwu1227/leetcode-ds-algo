// main.cpp
#include "remove_duplicates.hpp"
#include "node.hpp"
#include "singly.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<std::vector<int>> testCases = {
        {1, 1, 2}, {1, 1, 2, 3, 3}, {9, 12, 12, 7, 3, 7, 3, 4, 4, 5}};

    for (auto &testCase : testCases)
    {
        SinglyLinkedList sll;
        std::vector<ListNode::Ptr> nodes;

        std::sort(testCase.begin(), testCase.end());

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

        // Pass the sentinel head node
        ListNode::Ptr dedupedHead = removeDuplicates(sll.head);

        sll.display();
        // Dereference the shared pointer
        std::cout << "The new first node of the deduplicated sorted linked list above is " << *dedupedHead->next << '\n';
    }
    std::cout << std::endl;

    return 0;
}
