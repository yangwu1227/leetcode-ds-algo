// main.cpp
#include "zig_zag.hpp"
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

void print2DVector(const std::vector<std::vector<TreeNode::datatype>> &vectors)
{
    std::cout << "{";
    for (auto &vector : vectors)
    {
        std::cout << "{";
        for (auto &element : vector)
        {
            std::cout << element << (&element != &vector.back() ? ", " : "");
        }
        std::cout << (vector != vectors.back() ? "}, " : "}");
    }
    std::cout << "}";
}

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;

    std::vector<VectorDataType> testCases = {
        {1, 2, 3, std::monostate{}, 5, std::monostate{}, 4},
        {1, 2, 3, 4, std::monostate{}, std::monostate{}, 5},
        {3, 9, 20, std::monostate{}, std::monostate{}, 15, 7},
        {},
        {1, std::monostate{}, 3, 17, 27, 12, std::monostate{}},
    };

    for (auto &nodeData : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        std::vector<std::vector<TreeNode::datatype>> output = zigZag(root);

        std::cout << "The output of zig zag traversal is ";
        print2DVector(output);
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
