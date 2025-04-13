// level_order_traversal.cpp
#include "level_order_traversal.hpp"
#include "tree_node.hpp"
#include <vector>
#include <variant>
#include <deque>

std::vector<std::vector<TreeNode::datatype>> levelOrderTraversal(TreeNode::ptr &root)
{
    if (root == nullptr)
        return {};
    if (root->left == nullptr && root->right == nullptr)
        return {{root->data}};

    std::deque<TreeNode *> queue = {root.get()};
    std::vector<std::vector<TreeNode::datatype>> output;

    while (!queue.empty())
    {
        const size_t numNodesCurrLevel = queue.size();
        std::vector<TreeNode::datatype> nodeData;

        for (size_t i = 0; i < numNodesCurrLevel; i++)
        {
            TreeNode *currNode = queue.front();
            queue.pop_front();

            nodeData.push_back(currNode->data);

            if (currNode->left)
                queue.push_back(currNode->left.get());
            if (currNode->right)
                queue.push_back(currNode->right.get());
        }

        output.push_back(nodeData);
    }
    return output;
}
