// main.cpp
#include "even_odd_tree.hpp"
#include "tree_node.hpp"
#include <vector>
#include <iostream>
#include <variant>
#include <memory>

// Overload for std::ostream to handle std::variant
std::ostream &operator<<(std::ostream &os, const TreeNode::datatype &data)
{
    std::visit(

        // Lambda function, auto &&value is a generic param that deduces the type of the currently active value in std::variant
        [&os](auto &&value)
        {
        // Deduce the actual type of the value stored in std::variant
        using T = std::decay_t<decltype(value)>;
        // Compile-time checking if T is monostate, if so output null, else sent value to the stream
        if constexpr (std::is_same_v<T, std::monostate>) {
            os << "null";
        } else {
            os << value;
        } },

        // List of variants to pass to the visitor
        data);
    return os;
}

void printVector(const std::vector<TreeNode::datatype> &vector)
{
    std::cout << "{";
    for (auto const &element : vector)
    {
        std::cout << element << (&element != &vector.back() ? ", " : "");
    }
    std::cout << "}";
}

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;

    std::vector<VectorDataType> testCases = {
        {1, 10, 4, 3, std::monostate{}, 7, 9, 12, 8, 6, std::monostate{}, std::monostate{}, 2},
        {5, 4, 2, 3, 3, 7},
        {},
        {7},
        {5, 9, 1, 3, 5, 7}};

    for (auto &nodeData : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        bool isEvenodd = checkEvenOdd(root);

        std::cout << "The binary tree ";
        printVector(nodeData);
        std::cout << " is" << (isEvenodd ? " " : " not ") << "even odd\n";
    }
    std::cout << std::endl;

    return 0;
}
