// remove_leaves.cpp
#include "tree_node.hpp"
#include "remove_leaves.hpp"
#include <variant>
#include <stdexcept>

TreeNode::ptr removeLeaves(TreeNode::ptr &root, int target)
{
    auto depthFirstSearch = [&](auto &&self, TreeNode::ptr &node) -> TreeNode::ptr
    {
        // If nullptr, return
        if (!node)
            return nullptr;

        // Prune left and right subtrees
        node->left = self(self, node->left);
        node->right = self(self, node->right);

        // Ensure node data is an integer
        if (!std::holds_alternative<int>(node->data))
            throw std::runtime_error("Non-integer data encountered in TreeNode");

        // Extract integer value
        int nodeData = std::get<int>(node->data);

        // Return nullptr if leaf and the data matches the target
        if (!node->left && !node->right && nodeData == target)
            return nullptr;

        // Return the node by moving it
        return std::move(node);
    };

    return depthFirstSearch(depthFirstSearch, root);
}
