// main.cpp
#include "palindrome.hpp"
#include "singly.hpp"
#include "node.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<std::vector<int>> dataArrays = {
        {1, 2},
        {1, 2, 2, 3, 2, 2, 1},
        {1},
        {1, 2, 3, 4}};

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
        bool isPalindrome = palindrome(sll.head);
        std::cout << "After reversing\n";
        sll.display();
        std::cout << "The linked list " << (isPalindrome ? "is" : "is not") << " a palindrome\n";
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
