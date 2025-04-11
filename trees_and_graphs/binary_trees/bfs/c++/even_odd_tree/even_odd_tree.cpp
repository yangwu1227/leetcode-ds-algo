// even_odd_tree.cpp
#include "tree_node.hpp"
#include "even_odd_tree.hpp"
#include <deque>
#include <optional>  // std::optional
#include <variant>   // std::holds_alternative
#include <stdexcept> // std::invalid_argument

bool checkEvenOdd(TreeNode::ptr &root)
{
    if (root == nullptr)
        return false;
    // Check if single-node tree has an odd value at level 0
    if (root->left == nullptr && root->right == nullptr)
    {
        if (std::holds_alternative<int>(root->data))
        {
            int rootData = std::get<int>(root->data);
            return rootData % 2 != 0;
        }
    }

    std::deque<TreeNode *> queue = {root.get()};
    int level = 0;

    while (!queue.empty())
    {
        const size_t numNodesCurrLevel = queue.size();
        const bool isEvenLevel = (level % 2 == 0);
        // Set as optional before traversing each level
        std::optional<int> previousData;

        for (size_t i = 0; i < numNodesCurrLevel; ++i)
        {
            TreeNode *currNode = queue.front();
            queue.pop_front();
            if (!std::holds_alternative<int>(currNode->data))
            {
                throw std::invalid_argument("TreeNode data should be int for this algorithm");
            }

            const int currData = std::get<int>(currNode->data);

            // Check value parity: even levels need odd values, odd levels need even values
            if (isEvenLevel == (currData % 2 == 0))
                return false;

            // The first node of each level has no values, so this is not run
            if (previousData.has_value())
            {
                const bool validOrder = isEvenLevel ? currData > *previousData : // Even level: strictly increasing
                                            currData < *previousData;            // Odd level: strictly decreasing
                if (!validOrder)
                    return false;
            }

            if (currNode->left)
                queue.push_back(currNode->left.get());
            if (currNode->right)
                queue.push_back(currNode->right.get());

            previousData = currData;
        }
        level += 1;
    }
    return true;
}
