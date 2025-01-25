// main.cpp
#include "invert_tree.hpp"
#include "tree_node.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <queue>

/**
 * @brief Helper function to convert `TreeNode::datatype` to `std::string`.
 *
 * @param data The `std::variant` member of the binary tree.
 * @return std::string String representation of the variant.
 */
std::string nodeToString(const TreeNode::datatype &data)
{
    return std::visit(
        [](const auto &value) -> std::string
        {
            // Use type deduction to determine the actual type of `value` (the current variant value)
            using T = std::decay_t<decltype(value)>;

            // The `if constexpr` ensures that the condition is evaluated at compile time, not runtime
            // This eliminates unnecessary branches during runtime and ensures only the matching branch is compiled
            if constexpr (std::is_same_v<T, std::monostate>)
                return "null";
            else if constexpr (std::is_same_v<T, int> || std::is_same_v<T, double>)
                return std::to_string(value);
            else if constexpr (std::is_same_v<T, std::string>)
                return value;
            else
                return "unknown";
        },
        data);
}

void printNodes(const TreeNode::ptr &root)
{
    if (!root)
    {
        std::cout << "Tree is empty\n";
        return;
    }

    // Use raw pointers for priting
    std::queue<const TreeNode *> queue;
    queue.push(root.get());

    // Track the last meaningful node
    while (!queue.empty())
    {
        // Dereference to get the tree node instance
        const TreeNode *current = queue.front();
        queue.pop();

        if (current)
        {
            std::cout << nodeToString(current->data) << " ";
            queue.push(current->left.get());
            queue.push(current->right.get());
        }
        else
        {
            // Check if any future nodes in the queue are meaningful (i.e., not nullptrs)
            bool hasMeaningfulNode = false;
            std::queue<const TreeNode *> tempQueue = queue;
            while (!tempQueue.empty())
            {
                if (tempQueue.front() != nullptr)
                {
                    hasMeaningfulNode = true;
                    break;
                }
                tempQueue.pop();
            }

            if (hasMeaningfulNode)
            {
                std::cout << "null ";
            }
        }
    }
    std::cout << std::endl;
}

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;
    std::vector<VectorDataType> testCases = {
        {4, 2, 7, 1, 3, 6, 9},
        {2, 1, 3},
        {},
        {9, 12, 7, std::monostate{}, 9, 20, std::monostate{}, 8}};

    for (auto &nodeData : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        std::cout << "Nodes before inversion:\n";
        printNodes(root);
        // Invert the tree
        InvertTree::invert(root);
        std::cout << "Nodes after inversion:\n";
        printNodes(root);
        std::cout << "--------------------\n";
    }
    std::cout << std::endl;

    return 0;
}
