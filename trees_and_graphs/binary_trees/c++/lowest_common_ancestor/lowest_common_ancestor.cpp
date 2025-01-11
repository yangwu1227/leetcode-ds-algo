// lowest_common_ancestor.cpp
#include "lowest_common_ancestor.hpp"
#include "tree_node.hpp"

TreeNode *lowestCommonAncestor(const TreeNode *p, const TreeNode *q, const TreeNode::ptr &root)
{
    // Base case
    if (!root)
    {
        return nullptr;
    }

    // If the target is found
    if (root->data == p->data || root->data == q->data)
    {
        // Return the current root node
        return root.get();
    }

    // Check the left and right subtrees for targets
    TreeNode *leftResult = lowestCommonAncestor(p, q, root->left);
    TreeNode *rightResult = lowestCommonAncestor(p, q, root->right);

    // If both subtrees return non-null, root is LCA
    if (leftResult && rightResult)
    {
        return root.get();
    }

    // Return either non-null result, or nullptr if both are null
    return leftResult ? leftResult : rightResult;
}
