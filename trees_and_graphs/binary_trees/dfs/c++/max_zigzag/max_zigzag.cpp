// max_zigzag.cpp
#include "max_zigzag.hpp"
#include "tree_node.hpp"
#include <algorithm> // For std::max
#include <utility>   // For std::pair, std::make_pair

int maxZigZag(TreeNode::ptr &root)
{
    // Type alias for convenience and global max length variable
    using Pair = std::pair<int, int>;
    int maxLen = 0;

    // Using auto&& self so that our lambda can correctly accept two parameters (itself and the unique pointer)
    auto depthFirstSearch = [&](auto &&self, TreeNode::ptr &node) -> Pair
    {
        // This ensures that any leaf's result becomes 0 when we add 1
        if (!node)
            return Pair{-1, -1};

        // Recursively compute results for left and right subtrees
        auto [leftThenLeft, leftThenRight] = self(self, node->left);
        auto [rightThenLeft, rightThenRight] = self(self, node->right);

        // If we go left from this node, we must have come from a right move in the left subtree
        int leftLen = leftThenRight + 1;
        // If we go right from this node, we must have come from a left move inthe right subtree
        int rightLen = rightThenLeft + 1;

        // Update the global maximum length
        maxLen = std::max({maxLen, leftLen, rightLen});

        return Pair{leftLen, rightLen};
    };

    [[maybe_unused]] Pair results = depthFirstSearch(depthFirstSearch, root);

    return maxLen;
}
