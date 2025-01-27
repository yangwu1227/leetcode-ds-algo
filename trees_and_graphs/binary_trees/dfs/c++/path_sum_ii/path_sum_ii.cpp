// path_sum_ii.cpp
#include "tree_node.hpp"
#include "path_sum_ii.hpp"
#include <functional>
#include <vector>
#include <variant>
#include <stdexcept>

std::vector<std::vector<int>> pathSum(TreeNode::ptr &root, int target)
{
    // Container for the outpuut
    std::vector<std::vector<int>> paths;

    // If emtpy tree, return an empty vector
    if (!root)
        return paths;

    // Container for keeping track of the current path
    std::vector<int> currPath;

    // Depth first search lambda function
    std::function<void(TreeNode::ptr &, int)> depthFirstSearch = [&paths, &currPath, &target, &depthFirstSearch](TreeNode::ptr &node, int currSum)
    {
        if (!node)
            return;

        if (!std::holds_alternative<int>(node->data))
            throw std::runtime_error("Non-integer data encountered in TreeNode");

        // Add to the current sum and current running path
        int currData = std::get<int>(node->data);
        currSum += currData;
        currPath.push_back(currData);

        // Check if leaf node and if the target is matched
        if (!node->left && !node->right && currSum == target)
        {
            // Add the current (full) path to the output
            paths.push_back(currPath);
        }

        // Continue onto left and right subtrees
        if (node->left)
            depthFirstSearch(node->left, currSum);
        if (node->right)
            depthFirstSearch(node->right, currSum);

        // Backtrace by poping the current node back on the way back up the tree
        currPath.pop_back();
    };

    depthFirstSearch(root, 0);
    return paths;
}
