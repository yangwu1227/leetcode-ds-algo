// same_tree.cpp
#include "same_tree.hpp"
#include "tree_node.hpp"

bool Solution::depthFirstSearch(TreeNode::ptr &left, TreeNode::ptr &right)
{
    // If either left or right is a nullptr
    if (left == nullptr || right == nullptr)
    {
        if (left != right)
        {
            // Only one of the inputs is nullptr, return false
            return false;
        }
        // If the above check does not return, then both nodes are leaves, i.e., nullptr
        return true;
    }
    // Left and right subtrees results
    bool leftSubtree = Solution::depthFirstSearch(left->left, right->left);
    bool rightSubtree = Solution::depthFirstSearch(left->right, right->right);
    return left->data == right->data && leftSubtree && rightSubtree;
}

bool Solution::sameTree(TreeNode::ptr &firstTree, TreeNode::ptr &secondTree)
{
    // Handle edge case where both tree have just one node
    if (firstTree == nullptr && secondTree == nullptr)
    {
        return true;
    }
    return Solution::depthFirstSearch(firstTree, secondTree);
}
