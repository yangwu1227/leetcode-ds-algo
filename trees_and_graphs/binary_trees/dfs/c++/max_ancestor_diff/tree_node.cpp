// tree_node.cpp
#include "tree_node.hpp"
#include <memory>
#include <queue>
#include <vector>

TreeNode::TreeNode(datatype data, ptr left, ptr right)
    : data(std::move(data)), left(std::move(left)), right(std::move(right)) {}

std::ostream &operator<<(std::ostream &os, const TreeNode &tree_node)
{
    // Use std::visit to handle different types stored in the std::variant `data`
    std::visit(
        // This lambda function acts as a visitor, taking each variant type into account
        [&os](auto &&arg)
        {
            // Use type deduction to determine the actual type of `arg` (the current variant value)
            using T = std::decay_t<decltype(arg)>;
            // Check if the type of `arg` is std::monostate, which indicates a "null" node or empty data representation in the variant
            if constexpr (std::is_same_v<T, std::monostate>)
            {
                os << "null";
            }
            else
            {
                os << arg;
            }
        },
        tree_node.data);
    return os;
}

TreeNode::ptr TreeNode::construct_binary_tree(const std::vector<datatype> &values)
{
    // Check if the input vector is empty or "null", return nullptr if so
    if (values.empty() || std::holds_alternative<std::monostate>(values[0]))
    {
        return nullptr;
    }

    // Create the root node
    auto root = std::make_unique<TreeNode>(values[0]);
    // Initialize a queue to keep track of nodes at each level while constructing the tree
    // Use raw pointers (TreeNode*) here because the queue does not own the nodes, it only references them temporarily
    std::queue<TreeNode *> queue;
    // Push the root node into the queue for processing
    queue.push(root.get());
    size_t index = 1;

    // Traverse the vector and build the tree level-by-level using the queue
    while (index < values.size())
    {
        // Get the front node from the queue, which represents the current parent node we are adding children to
        TreeNode *current_node = queue.front();
        // Remove the node from the queue after processing
        queue.pop();

        // Add the left child if available in the vector and it is not "null" (std::monostate)
        if (index < values.size() && !std::holds_alternative<std::monostate>(values[index]))
        {
            // Create a new TreeNode for the left child and assign it to the left pointer of the current node
            current_node->left = std::make_unique<TreeNode>(values[index]);
            // Push the left child pointer (raw) into the queue for further child processing
            queue.push(current_node->left.get());
        }
        // Move to the next element in the vector
        ++index;

        // Add the right child in a similar way if it exists and is not "null"
        if (index < values.size() && !std::holds_alternative<std::monostate>(values[index]))
        {
            current_node->right = std::make_unique<TreeNode>(values[index]);
            queue.push(current_node->right.get());
        }
        ++index;
    }

    // Return the pointer to the root node of the binary tree
    return root;
}
