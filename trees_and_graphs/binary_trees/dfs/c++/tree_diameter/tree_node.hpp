// tree_node.hpp
#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP
#include <memory>
#include <iostream>
#include <variant>
#include <string>
#include <vector>

/**
 * @class TreeNode
 * @brief A class representing a node in a binary tree.
 */
class TreeNode
{
public:
    using ptr = std::unique_ptr<TreeNode>;
    // The std::monostate represents a "null" value in the variant
    using datatype = std::variant<std::monostate, int, double, std::string>;

    datatype data; // The value stored in the node, which can be int, double, std::string, or null.
    ptr left;      // Unique pointer to the left child.
    ptr right;     // Unique pointer to the right child.

    /**
     * @brief Constructs a TreeNode instance.
     *
     * @param data The value to store in the node, which can be int, double, std::string, or null (std::monostate).
     * @param left Pointer to the left child node (defaults to nullptr).
     * @param right Pointer to the right child node (defaults to nullptr).
     */
    explicit TreeNode(datatype data = std::monostate{}, ptr left = nullptr, ptr right = nullptr);

    /**
     * @brief Overload the << operator for easy printing of TreeNode.
     *
     * @param os The output stream.
     * @param tree_node The TreeNode to print.
     * @return The output stream with the TreeNode's data.
     */
    friend std::ostream &operator<<(std::ostream &os, const TreeNode &tree_node);

    /**
     * @brief Constructs a binary tree from a list of values representing level-order traversal.
     *
     * @param values A vector where each element represents a node's data in level-order; std::monostate{} represents a missing node.
     * @return A unique pointer to the root of the constructed binary tree.
     */
    static ptr constructBinaryTree(const std::vector<datatype> &values);
};

#endif
