// leaf_similar.cpp
#include "tree_node.hpp"
#include "leaf_similar.hpp"
#include <deque>      // For std::deque
#include <functional> // For std::function

bool LeafSimilar::check(TreeNode::ptr &root1, TreeNode::ptr &root2)
{
    // Internal deque to store leaf data
    std::deque<TreeNode::datatype> internalDeque;

    // Lambda depth first search
    std::function<bool(TreeNode::ptr &, bool)> depthFirstSearch = [&internalDeque, &depthFirstSearch](TreeNode::ptr &node, bool enquequeMode) -> bool
    {
        // Return true if a leaf node, this handles the base case
        if (!node)
            return true;

        // If both left and right child are nullptr's
        if (!node->left && !node->right)
        {
            if (enquequeMode)
            {
                // Push the current data to the queque
                internalDeque.push_back(node->data);
            }
            else
            {
                // If not in enqueque mode, check if the deque is empty or whether the data does not match the front of the queue
                if (internalDeque.empty() || internalDeque.front() != node->data)
                {
                    return false;
                }
                // If deque is non-empty and the data matches the front, pop the front as the two leaf nodes are matched
                internalDeque.pop_front();
            }
        }
        // Traverse the left and right subtrees
        return depthFirstSearch(node->left, enquequeMode) && depthFirstSearch(node->right, enquequeMode);
    };

    // Traverse the first tree and enqueue the deque (always returns true for this step)
    if (!depthFirstSearch(root1, true))
        return false;
    // Traverse the second tree and verify the deque
    if (!depthFirstSearch(root2, false))
        return false;

    // Check if the deque has been completely cleared to ensure all leaves are matched
    // This guarantees there are no unmatched leaves remaining from the first tree
    return internalDeque.empty();
}
