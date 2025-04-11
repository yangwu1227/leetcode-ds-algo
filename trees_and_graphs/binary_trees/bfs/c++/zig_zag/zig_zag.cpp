#include "tree_node.hpp"
#include "zig_zag.hpp"
#include <vector>
#include <deque>

std::vector<std::vector<TreeNode::datatype>> zigZag(TreeNode::ptr &root)
{

    if (root == nullptr)
        return {};
    if (root->left == nullptr && root->right == nullptr)
        return {{root->data}};

    std::deque<TreeNode *> queue = {root.get()};
    std::vector<std::vector<TreeNode::datatype>> output;
    int level = 0;

    while (!queue.empty())
    {
        const size_t numNodesCurrLevel = queue.size();
        std::deque<TreeNode::datatype> nodeData;

        for (size_t i = 0; i < numNodesCurrLevel; i++)
        {
            TreeNode *currNode = queue.front();
            queue.pop_front();

            // If even level, left to right by appending to the back
            if (level % 2 == 0)
            {
                nodeData.push_back(currNode->data);
            }
            // If odd level, right to left by appending to the front
            else
            {
                nodeData.push_front(currNode->data);
            }

            if (currNode->left)
                queue.push_back(currNode->left.get());
            if (currNode->right)
                queue.push_back(currNode->right.get());
        }
        output.emplace_back(nodeData.begin(), nodeData.end());
        level += 1;
    }
    return output;
}
