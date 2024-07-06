// main.cpp
#include "remove_duplicates.hpp"
#include "node.hpp"
#include "singly.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

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
        ListNode::Ptr dedupedHeadSingle = RemoveDuplicates::singlePointer(sll.head);
        ListNode::Ptr dedupedHeadFastSlow = RemoveDuplicates::fastSlowPointers(sll.head);
        ListNode::Ptr currentSingle, currentFastSlow;
        while (currentSingle != nullptr && currentFastSlow->next != nullptr)
        {
            assert(currentSingle->data == currentFastSlow->data);
        }

        sll.display();
        // Dereference the shared pointer
        std::cout << "The new first node of the deduplicated sorted linked list above is " << *dedupedHeadFastSlow->next << '\n';
    }
    std::cout << std::endl;

    return 0;
}
