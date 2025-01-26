// main.cpp
#include "same_tree.hpp"
#include "tree_node.hpp"
#include "tree_utils.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <variant>
#include <memory>
#include <string>

// Overload for std::ostream to handle std::variant
std::ostream &operator<<(std::ostream &os, const TreeNode::datatype &data)
{
    std::visit(

        // Lambda function, auto &&value is a generic param that deduces the type of the currently active value in std::variant
        [&os](auto &&value)
        {
        // Deduce the actual type of the value stored in std::variant
        using T = std::decay_t<decltype(value)>;
        // Compile-time if checking if T is monostate, if so output null, else sent value to the stream
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
    for (size_t i = 0; i < vector.size(); ++i)
    {
        std::cout << vector[i];
        if (i != vector.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "}";
}

int main()
{
    using vectorDataType = std::vector<TreeNode::datatype>;
    std::map<vectorDataType, vectorDataType> testCases = {
        {{1, 3, 2}, {1, 3, 2}},
        {{1, 2}, {1, std::monostate{}, 2}},
        {{1, 2, 1}, {1, 1, 2}},
        {{3.2, 4.5}, {3.2, 4.5}}};

    tree_utils::TreePrinter printer;

    for (const auto &[firstTreeVals, secondTreeVals] : testCases)
    {
        TreeNode::ptr firstTree = TreeNode::constructBinaryTree(firstTreeVals);
        TreeNode::ptr secondTree = TreeNode::constructBinaryTree(secondTreeVals);
        bool sameTree = Solution::sameTree(firstTree, secondTree);

        std::cout << "The two trees ";
        printer.printLevelOrder(firstTree);
        std::cout << " and ";
        printer.printLevelOrder(secondTree);
        std::cout << " are" << (sameTree ? " " : " not ") << "the same" << "\n\n";
    }
    std::cout << std::endl;

    return 0;
}
