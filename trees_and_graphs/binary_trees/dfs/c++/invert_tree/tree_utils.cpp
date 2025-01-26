#include "tree_utils.hpp"
#include "tree_node.hpp"
#include <algorithm>

namespace tree_utils
{

    std::string TreePrinter::nodeToString(const TreeNode::datatype &data)
    {
        return std::visit(
            [](const auto &value) -> std::string
            {
                using T = std::decay_t<decltype(value)>;
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

    // Checks if queue contains any non-null nodes ahead
    bool TreePrinter::hasNonNullNode(const std::queue<const TreeNode *> &queue) const
    {
        auto temp_queue = queue;
        while (!temp_queue.empty())
        {
            if (temp_queue.front() != nullptr)
                return true;
            temp_queue.pop();
        }
        return false;
    }

    // Level-order (breadth-first) traversal printing
    void TreePrinter::printLevelOrder(const TreeNode::ptr &root)
    {
        if (!root)
        {
            os_ << "Tree is empty\n";
            return;
        }

        std::queue<const TreeNode *> queue;
        queue.push(root.get());

        while (!queue.empty())
        {
            const TreeNode *current = queue.front();
            queue.pop();

            if (current)
            {
                os_ << nodeToString(current->data) << " ";
                queue.push(current->left.get());  // Push left child
                queue.push(current->right.get()); // Push right child
            }
            else if (hasNonNullNode(queue))
            {
                os_ << "null "; // Print null only if more nodes exist
            }
        }
        os_ << std::endl;
    }

    // Recursive traversal implementations
    void TreePrinter::preOrderTraversal(const TreeNode *node)
    {
        if (!node)
            return;
        os_ << nodeToString(node->data) << " ";
        preOrderTraversal(node->left.get());
        preOrderTraversal(node->right.get());
    }

    void TreePrinter::inOrderTraversal(const TreeNode *node)
    {
        if (!node)
            return;
        inOrderTraversal(node->left.get());
        os_ << nodeToString(node->data) << " ";
        inOrderTraversal(node->right.get());
    }

    void TreePrinter::postOrderTraversal(const TreeNode *node)
    {
        if (!node)
            return;
        postOrderTraversal(node->left.get());
        postOrderTraversal(node->right.get());
        os_ << nodeToString(node->data) << " ";
    }

    // Public interface implementations
    void TreePrinter::printPreOrder(const TreeNode::ptr &root)
    {
        if (!root)
        {
            os_ << "Tree is empty\n";
            return;
        }
        preOrderTraversal(root.get());
        os_ << std::endl;
    }

    void TreePrinter::printInOrder(const TreeNode::ptr &root)
    {
        if (!root)
        {
            os_ << "Tree is empty\n";
            return;
        }
        inOrderTraversal(root.get());
        os_ << std::endl;
    }

    void TreePrinter::printPostOrder(const TreeNode::ptr &root)
    {
        if (!root)
        {
            os_ << "Tree is empty\n";
            return;
        }
        postOrderTraversal(root.get());
        os_ << std::endl;
    }

    namespace utils
    {

        // Compares two trees for structural and value equality
        bool areIdentical(const TreeNode::ptr &root1, const TreeNode::ptr &root2)
        {
            if (!root1 && !root2)
                return true;
            if (!root1 || !root2)
                return false;
            return (root1->data == root2->data) && areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right);
        }

        // Calculates maximum height (depth) of tree
        size_t getHeight(const TreeNode::ptr &root)
        {
            if (!root)
                return 0;
            return 1 + std::max(getHeight(root->left), getHeight(root->right));
        }

        // Counts total number of nodes in tree
        size_t getNodeCount(const TreeNode::ptr &root)
        {
            if (!root)
                return 0;
            return 1 + getNodeCount(root->left) + getNodeCount(root->right);
        }

    } // namespace utils
} // namespace tree_utils
