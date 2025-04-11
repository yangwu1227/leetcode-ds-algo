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
    if (root->left == nullptr && root->right == nullptr)
    {
        if (std::holds_alternative<int>(root->data))
        {
            int rootData = std::get<int>(root->data);
            // Return true if rootData (level 0) is odd, return false if it is even
            return rootData % 2 != 0;
        }
    }

    std::deque<TreeNode *> queue = {root.get()};
    int level = 0;
    int currData, numNodesCurrLevel;
    bool isDecreasing, isIncreasing, isEvenLevel;

    while (!queue.empty())
    {
        numNodesCurrLevel = queue.size();
        isEvenLevel = level % 2 == 0;
        // Set as optional before traversing each level
        std::optional<int> previousData;

        for (size_t i = 0; i < numNodesCurrLevel; ++i)
        {
            TreeNode *currNode = queue.front();
            queue.pop_front();
            if (std::holds_alternative<int>(currNode->data))
            {
                currData = std::get<int>(currNode->data);
            }
            else
            {
                throw std::invalid_argument("TreeNode data should be int for this algorithm");
            }

            // If odd (even) level matchs with odd (even) data, return false
            if (isEvenLevel == (currData % 2 == 0))
                return false;

            // The first node of each level has no values, so this is not run
            if (previousData.has_value())
            {
                isDecreasing = currData < previousData;
                isIncreasing = currData > previousData;
                // The only valid even odd conditions are (even && increasing) or (odd && decreasing)
                if (!((isEvenLevel && isIncreasing) || (!isEvenLevel && isDecreasing)))
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
