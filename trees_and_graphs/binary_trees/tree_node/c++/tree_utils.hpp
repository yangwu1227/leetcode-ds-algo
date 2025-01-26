#ifndef TREE_UTILS_HPP
#define TREE_UTILS_HPP
#include "tree_node.hpp"
#include <algorithm>
#include <string>
#include <queue>
#include <memory>
#include <iostream>
#include <functional>

namespace tree_utils
{
    /**
     * @brief Utility class for tree traversal and visualization operations
     *
     * Provides various methods to print tree structures in different traversal
     * orders and formats. Uses visitor pattern for consistent string conversion.
     */
    class TreePrinter
    {
    public:
        /**
         * @brief Constructs printer with specified output stream
         * @param os Output stream to use (defaults to std::cout)
         */
        explicit TreePrinter(std::ostream &os = std::cout) : os_(os) {}

        /**
         * @brief Prints tree in level-order (breadth-first) traversal
         * @param root Root node of the tree to print
         *
         * Prints nodes level by level, left to right, with "null" for empty positions.
         */
        void printLevelOrder(const TreeNode::ptr &root);

        /**
         * @brief Prints tree in pre-order traversal (root-left-right)
         * @param root Root node of the tree to print
         */
        void printPreOrder(const TreeNode::ptr &root);

        /**
         * @brief Prints tree in in-order traversal (left-root-right)
         * @param root Root node of the tree to print
         */
        void printInOrder(const TreeNode::ptr &root);

        /**
         * @brief Prints tree in post-order traversal (left-right-root)
         * @param root Root node of the tree to print
         */
        void printPostOrder(const TreeNode::ptr &root);

    private:
        std::ostream &os_; ///< Output stream for printing

        /**
         * @brief Converts node data to string representation
         * @param data The variant data to convert
         * @return String representation of the data
         */
        std::string nodeToString(const TreeNode::datatype &data);

        /**
         * @brief Checks if queue contains any non-null nodes
         * @param queue Queue of node pointers to check
         * @return true if queue contains at least one non-null node
         */
        bool hasNonNullNode(const std::queue<const TreeNode *> &queue) const;

        // Private members called by public print functions
        void preOrderTraversal(const TreeNode *node);
        void inOrderTraversal(const TreeNode *node);
        void postOrderTraversal(const TreeNode *node);
    };

    /**
     * @brief Namespace containing utility functions for tree analysis and comparison
     */
    namespace utils
    {
        /**
         * @brief Compares two trees for structural and value equality
         * @param root1 Root of first tree
         * @param root2 Root of second tree
         * @return true if trees are identical in structure and values
         *
         * Trees are considered identical if they have the same shape and
         * corresponding nodes have equal values.
         */
        bool areIdentical(const TreeNode::ptr &root1, const TreeNode::ptr &root2);

        /**
         * @brief Calculates the height of a tree
         * @param root Root node of the tree
         * @return Number of edges in longest path from root to leaf
         *
         * Empty tree has height 0, tree with only root has height 1.
         */
        size_t getHeight(const TreeNode::ptr &root);

        /**
         * @brief Counts total number of nodes in the tree
         * @param root Root node of the tree
         * @return Total number of nodes in the tree
         *
         * Includes root and all descendants. Empty tree has count 0.
         */
        size_t getNodeCount(const TreeNode::ptr &root);
    }

} // namespace tree_utils

#endif // TREE_UTILS_HPP
