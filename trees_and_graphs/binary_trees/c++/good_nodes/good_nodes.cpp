// good_nodes.cpp
#include "tree_node.hpp"
#include "good_nodes.hpp"
#include <algorithm>

int Solution::depthFirstSearch(const TreeNode::ptr &node, const int maxValSoFar)
{
    // Base case if the current node is an empty node
    if (node == nullptr)
    {
        return 0;
    }

    // Ensure that the data is an integer
    int currData;
    int currMaxValSoFar;
    if (std::holds_alternative<int>(node->data))
    {
        currData = std::get<int>(node->data);
        currMaxValSoFar = std::max(currData, maxValSoFar);
    }
    else
    {
        throw std::runtime_error("Non-integer data encountered in TreeNode");
    }
    // Traverse the left and right subtrees, counting the number of good nodes encountered
    int left = Solution::depthFirstSearch(node->left, currMaxValSoFar);
    int right = Solution::depthFirstSearch(node->right, currMaxValSoFar);
    // Sum all good nodes encountered so far in the left and right subtrees
    int numGoodNodes = left + right;
    // If the current current data is greater than or equal to the max value so far (not including itself), it is a good node
    if (currData >= maxValSoFar)
    {
        numGoodNodes += 1;
    }
    return numGoodNodes;
}

int Solution::goodNodes(const TreeNode::ptr &root)
{
    // Handle single node root
    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }
    const int MIN_INT = std::numeric_limits<int>::min();
    return Solution::depthFirstSearch(root, MIN_INT);
}
