// right_size_view.cpp
#include "right_side_view.hpp"
#include "tree_node.hpp"
#include <vector>
#include <deque>
#include <utility> // For std::move

std::vector<TreeNode::datatype> rightSide(TreeNode::ptr &root)
{
    // Empty tree case
    if (root == nullptr)
        return {};

    std::vector<TreeNode::datatype> rightSideNodes;
    std::deque<TreeNode *> queue = {root.get()};

    while (!queue.empty())
    {
        const auto numNodesCurrLevel = queue.size();
        TreeNode *rightmostNode = nullptr;

        for (size_t i = 0; i < numNodesCurrLevel; ++i)
        {
            TreeNode *currNode = queue.front();
            queue.pop_front();

            // Track the rightmost node at this level
            rightmostNode = currNode;

            if (currNode->left)
                queue.push_back(currNode->left.get());
            if (currNode->right)
                queue.push_back(currNode->right.get());
        }

        // After processing the level, add the rightmost node's data
        rightSideNodes.push_back(rightmostNode->data);
    }

    return rightSideNodes;
}
