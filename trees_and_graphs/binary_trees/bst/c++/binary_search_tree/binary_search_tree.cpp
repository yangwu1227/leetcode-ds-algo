// binary_search_tree.hpp
#include "binary_search_tree.hpp"
#include "tree_node.hpp"
#include <vector>
#include <deque>
#include <type_traits> // std::decay_t, std::is_same_v
#include <stdexcept>   // std::invalid_argument
#include <memory>      // std::make_unique
#include <optional>    // std::optional, std::nullopt
#include <variant>     // std::get, std::hold_alternative
#include <limits>      // std::numeric_limits
#include <algorithm>   // std::max

/* -------------------------------------------------------------------------- */
/*                    Constructor, Destructor, and Helpers                    */
/* -------------------------------------------------------------------------- */

// Constructor
BinarySearchTree::BinarySearchTree() : root(nullptr), size_(0) {}

// Destructor
BinarySearchTree::~BinarySearchTree()
{
    // Call the recursive helper to clean up all nodes
    clearRecursive(root);
}

// Recursive helper for destructor
void BinarySearchTree::clearRecursive(TreeNode::ptr &node)
{
    if (node == nullptr)
    {
        return;
    }

    // Recursively clear children
    clearRecursive(node->left);
    clearRecursive(node->right);

    // Going up the tree, reset the pointer, which triggers `unique_ptr` deletion
    node.reset();
}

// Check if tree is empty
bool BinarySearchTree::isEmpty() const
{
    return root == nullptr;
}

// Public getter for the number of nodes in the tree
size_t BinarySearchTree::size() const
{
    return size_;
}

/* -------------------------------------------------------------------------- */
/*                          TreeNode Data Validation                          */
/* -------------------------------------------------------------------------- */

TreeNode::datatype BinarySearchTree::validateData(const TreeNode::datatype &data) const
{
    // Check if the variant contains an inactive value (monostate)
    if (std::holds_alternative<std::monostate>(data))
    {
        throw std::invalid_argument("TreeNode data cannot be null (std::monostate)");
    }

    // Use std::visit (generic dispatcher), which calls the visitor lambda with whichever alternative data currently holds
    return std::visit(
        // Perfectly forward the held value (int&, int&&, double&, or double&&)
        [](auto &&arg) -> TreeNode::datatype
        {
            // Deduce the type of the data (strip references & or && at compile time so arg type is int or double)
            using ArgType = std::decay_t<decltype(arg)>;

            if constexpr (
                std::is_same_v<ArgType, int> ||
                std::is_same_v<ArgType, double>)
            {
                // Simply return valid type
                return arg;
            }
            else
            {
                throw std::invalid_argument("TreeNode data must be int or double");
            }
        },
        data);
}

/* -------------------------------------------------------------------------- */
/*                                   Insert                                   */
/* -------------------------------------------------------------------------- */

bool BinarySearchTree::insert(const TreeNode::datatype &data)
{
    TreeNode::datatype validatedData = validateData(data);
    // If empty tree, simply create the unique pointer to a new TreeNode instance
    if (root == nullptr)
    {
        root = std::make_unique<TreeNode>(validatedData);
        size_ += 1;
        return true;
    }
    // If not an empty tree, recursive insert
    return insertRecursive(root, validatedData);
}

bool BinarySearchTree::insertRecursive(TreeNode::ptr &node, const TreeNode::datatype &dataToInsert)
{
    // Base case for leaf node
    if (node == nullptr)
    {
        node = std::make_unique<TreeNode>(dataToInsert);
        size_ += 1;
        return true;
    }

    // Recursive left and right children
    if (dataToInsert < node->data)
    {
        return insertRecursive(node->left, dataToInsert);
    }
    else if (dataToInsert > node->data)
    {
        return insertRecursive(node->right, dataToInsert);
    }
    else
    {
        // Replace if duplicated data
        node->data = dataToInsert;
        // Indicate that we simply replaced the data for the matching node
        return false;
    }
}

/* -------------------------------------------------------------------------- */
/*                                   Search                                   */
/* -------------------------------------------------------------------------- */

const TreeNode *BinarySearchTree::search(const TreeNode::datatype &data) const
{
    TreeNode::datatype validatedData = validateData(data);
    return searchRecursive(root.get(), validatedData);
}

const TreeNode *BinarySearchTree::searchRecursive(const TreeNode *node, const TreeNode::datatype &dataToSearch) const
{
    // Base case: search miss (return nullptr) or search hit
    if (node == nullptr || dataToSearch == node->data)
        return node;
    // Recursive cases
    if (dataToSearch < node->data)
    {
        return searchRecursive(node->left.get(), dataToSearch);
    }
    // Must be dataToSearch > node->data since equality was checked earlier
    else
    {
        return searchRecursive(node->right.get(), dataToSearch);
    }
}

/* -------------------------------------------------------------------------- */
/*                                   Remove                                   */
/* -------------------------------------------------------------------------- */

// Find the minimum data value in the subtree, used in remove member function
TreeNode::datatype BinarySearchTree::findMinData(const TreeNode *node) const
{
    // Raw pointer for traversal
    const TreeNode *currNode = node;
    // Keep going left until the minimum data value is found
    while (currNode->left != nullptr)
    {
        currNode = currNode->left.get();
    }
    return currNode->data;
}

bool BinarySearchTree::remove(const TreeNode::datatype &data)
{
    TreeNode::datatype validatedData = validateData(data);
    // If the tree is empty, return False to indicate no node is removed
    if (root == nullptr)
        return false;
    // If not an empty tree
    return removeRecursive(root, validatedData);
}

bool BinarySearchTree::removeRecursive(TreeNode::ptr &node, const TreeNode::datatype &dataToRemove)
{
    // Base case, return false if dataToRemove is not found in the tree
    if (node == nullptr)
        return false;

    bool removed = false;

    // Recursive left if less than current node data
    if (dataToRemove < node->data)
    {
        removed = removeRecursive(node->left, dataToRemove);
    }
    // Recursive right if greater than current node data
    else if (dataToRemove > node->data)
    {
        removed = removeRecursive(node->right, dataToRemove);
    }
    // This else branch runs when node to remove is found, i.e., dataToRemove == node->data
    else
    {
        // Case I: leaf node with no children, simply
        if (node->left == nullptr && node->right == nullptr)
        {
            // Destroy the object managed by the pointer
            node.reset();
            size_ -= 1;
            return true;
        }
        // Case II: Node with only one child
        else if (node->left == nullptr)
        {
            // Move the right child up to replace the current node
            TreeNode::ptr temp = std::move(node->right);
            node.reset();
            node = std::move(temp);
            size_ -= 1;
            return true;
        }
        else if (node->right == nullptr)
        {
            // Move the left child up to replace the current node
            TreeNode::ptr temp = std::move(node->left);
            node.reset();
            node = std::move(temp);
            size_ -= 1;
            return true;
        }
        // Case III: node with two children, find the inorder successor (smallest data in the right subtree of this matched node)
        else
        {
            // Find the minimum data value in the right subtree (i.e., the successor)
            TreeNode::datatype successorData = findMinData(node->right.get());
            // Replace current node's data with the successor's data
            node->data = successorData;

            // Remove the successor from the right subtree
            // No need to decrement size as it will be decremented when the successor node is removed
            removed = removeRecursive(node->right, successorData);
            return true;
        }
    }
    return removed;
}

/* -------------------------------------------------------------------------- */
/*                                  Contains                                  */
/* -------------------------------------------------------------------------- */

bool BinarySearchTree::contains(const TreeNode::datatype &data) const
{
    // No need to call validateData, since search already calls it
    return search(data) != nullptr;
}

/* -------------------------------------------------------------------------- */
/*                              Min and Max Nodes                             */
/* -------------------------------------------------------------------------- */

const TreeNode *BinarySearchTree::findMinNode() const
{
    // Empty tree
    if (isEmpty())
        return nullptr;

    // Raw pointer for traversal
    const TreeNode *currNode = root.get();
    // Keep moving left for minimum
    while (currNode->left != nullptr)
    {
        currNode = currNode->left.get();
    }
    return currNode;
}

const TreeNode *BinarySearchTree::findMaxNode() const
{
    // Empty tree
    if (isEmpty())
        return nullptr;

    // Raw pointer for traversal
    const TreeNode *currNode = root.get();
    // Keep moving right for maximum
    while (currNode->right != nullptr)
    {
        currNode = currNode->right.get();
    }
    return currNode;
}

/* -------------------------------------------------------------------------- */
/*                              Floor and Ceiling                             */
/* -------------------------------------------------------------------------- */

std::optional<TreeNode::datatype> BinarySearchTree::floor(const TreeNode::datatype &target) const
{
    if (isEmpty())
        return std::nullopt;
    TreeNode::datatype validatedTarget = validateData(target);
    const TreeNode *floorNode = floorRecursive(root.get(), validatedTarget);
    return floorNode == nullptr ? std::nullopt : std::optional<TreeNode::datatype>{floorNode->data};
}

const TreeNode *BinarySearchTree::floorRecursive(const TreeNode *node, const TreeNode::datatype &target) const
{
    // Base case, empty node
    if (node == nullptr)
        return nullptr;

    // If current node's data equals the target, we've found an exact match, which is the floor
    if (node->data == target)
        return node;

    // If target is less than current node's data, the floor cannot be in the right subtree
    // All values in right subtree are greater than node->data which is already > target
    // Continue searching for the floor in the left subtree
    if (target < node->data)
        return floorRecursive(node->left.get(), target);

    // If we reach here, target > node->data, so the current node could be the floor
    // But there might be a larger value than the current node (but still <= target) in the right subtree

    // Search the right subtree for a potential better floor candidate
    // A better candidate would be a value that is <= target but still > node->data
    const TreeNode *rightFloorNode = floorRecursive(node->right.get(), target);
    return rightFloorNode == nullptr ? node : rightFloorNode;
}

std::optional<TreeNode::datatype> BinarySearchTree::ceiling(const TreeNode::datatype &target) const
{
    if (isEmpty())
        return std::nullopt;
    TreeNode::datatype validatedTarget = validateData(target);
    const TreeNode *ceilingNode = ceilingRecursive(root.get(), validatedTarget);
    return ceilingNode == nullptr ? std::nullopt : std::optional<TreeNode::datatype>{ceilingNode->data};
}

const TreeNode *BinarySearchTree::ceilingRecursive(const TreeNode *node, const TreeNode::datatype &target) const
{
    // Base case: If we've reached a null node, return nullptr indicating no ceiling found in this path
    if (node == nullptr)
        return nullptr;

    // If current node's data equals the target, we've found an exact match, which is the ceiling
    if (node->data == target)
        return node;

    // If target is greater than current node's data, the ceiling cannot be in the left subtree
    // All values in left subtree are less than node->data which is already < target
    // Continue searching for the ceiling in the right subtree
    if (target > node->data)
        return ceilingRecursive(node->right.get(), target);

    // If we reach here, target < node->data, so the current node could be the ceiling
    // But there might be a smaller value than the current node (but still >= target) in the left subtree

    // Search the left subtree for a potential better ceiling candidate
    // A better candidate would be a value that is >= target but still < node->data
    const TreeNode *leftCeilingNode = ceilingRecursive(node->left.get(), target);
    return leftCeilingNode == nullptr ? node : leftCeilingNode;
}

/* -------------------------------------------------------------------------- */
/*                                    Rank                                    */
/* -------------------------------------------------------------------------- */

int BinarySearchTree::rank(const TreeNode::datatype &data) const
{
    // If monostate, then return 0
    if (std::holds_alternative<std::monostate>(data))
        return 0;
    // If not monostate, must be int or double
    TreeNode::datatype validatedData = validateData(data);
    return rankRecursive(root.get(), validatedData);
}

size_t BinarySearchTree::sizeRecursive(const TreeNode *node) const
{
    // Base case, empty node
    if (node == nullptr)
        return 0;
    // Size of the tree rooted at the current node
    return 1 + sizeRecursive(node->left.get()) + sizeRecursive(node->right.get());
}

int BinarySearchTree::rankRecursive(const TreeNode *node, const TreeNode::datatype &data) const
{
    // Base case, empty node
    if (node == nullptr)
        return 0;

    // If data is less than the current node's data, explore left subtree
    if (data < node->data)
    {
        return rankRecursive(node->left.get(), data);
    }
    // If data is greater than the current node's data, we count this node in the rank
    else if (data > node->data)
    {
        // Count the left subtree size + current node + rank in right subtree
        int leftSize = sizeRecursive(node->left.get());
        return 1 + leftSize + rankRecursive(node->right.get(), data);
    }
    // This branch handles the case when data == node->data
    else
    {
        // The rank of the current node is the number of nodes in the left subtree
        return sizeRecursive(node->left.get());
    }
}

/* -------------------------------------------------------------------------- */
/*                                   Select                                   */
/* -------------------------------------------------------------------------- */

std::optional<TreeNode::datatype> BinarySearchTree::select(int k) const
{
    if (k < 0 || k >= size_)
        return std::nullopt;

    const TreeNode *selectNode = selectRecursive(root.get(), k);
    return (selectNode == nullptr) ? std::nullopt : std::optional<TreeNode::datatype>{selectNode->data};
}

const TreeNode *BinarySearchTree::selectRecursive(const TreeNode *node, int k) const
{
    // Base case, empty node
    if (node == nullptr)
        return node;

    // This is the number of nodes smaller than the current node
    int leftSize = sizeRecursive(node->left.get());

    // If k < left size, there may be a node with smaller rank in the left subtree
    if (k < leftSize)
    {
        return selectRecursive(node->left.get(), k);
    }
    // If k > left size, skip entire left subtree (not possible to find the kth smallest node there) and the current node
    else if (k > leftSize)
    {
        return selectRecursive(node->right.get(), k - leftSize - 1);
    }
    // Handles the case when k == leftSize, i.e., the current ndoe is the kth smallest
    else
    {
        return node;
    }
}

/* -------------------------------------------------------------------------- */
/*                       Valid Binary Search Tree Check                       */
/* -------------------------------------------------------------------------- */

bool BinarySearchTree::isValidBst() const
{
    if (root == nullptr)
        return true;

    return isValidBstRecursive(root.get(), std::nullopt, std::nullopt);
}

bool BinarySearchTree::isValidBstRecursive(const TreeNode *node, const std::optional<TreeNode::datatype> &minValue, const std::optional<TreeNode::datatype> &maxValue) const
{
    // Base case, empty node
    if (node == nullptr)
        return true;

    // Validate current node's data is within bounds
    // The root node has no constraints (i.e., `std::nullopt`), only as we descend into the tree do we start adding constraints
    if (minValue.has_value() && !(node->data > minValue.value()))
        return false;

    if (maxValue.has_value() && !(node->data < maxValue.value()))
        return false;

    // Recursive validations for children
    return isValidBstRecursive(node->left.get(), minValue, node->data) && isValidBstRecursive(node->right.get(), node->data, maxValue);
}

/* -------------------------------------------------------------------------- */
/*                                   Height                                   */
/* -------------------------------------------------------------------------- */

int BinarySearchTree::height() const
{
    return heightRecursive(root.get());
}

int BinarySearchTree::heightRecursive(const TreeNode *node) const
{
    // Base case, empty tree has a height of -1
    if (node == nullptr)
        return -1;

    int leftHeight = heightRecursive(node->left.get());
    int rightHeight = heightRecursive(node->right.get());

    return std::max(leftHeight, rightHeight) + 1;
}

/* -------------------------------------------------------------------------- */
/*                                 Traversals                                 */
/* -------------------------------------------------------------------------- */

std::vector<TreeNode::datatype> BinarySearchTree::inorderTraversal() const
{
    std::vector<TreeNode::datatype> result;
    inorderRecursive(root.get(), result);
    return result;
}

void BinarySearchTree::inorderRecursive(const TreeNode *node, std::vector<TreeNode::datatype> &result) const
{
    if (node != nullptr)
    {
        inorderRecursive(node->left.get(), result);
        result.push_back(node->data);
        inorderRecursive(node->right.get(), result);
    }
}

std::vector<TreeNode::datatype> BinarySearchTree::preorderTraversal() const
{
    std::vector<TreeNode::datatype> result;
    preorderRecursive(root.get(), result);
    return result;
}

void BinarySearchTree::preorderRecursive(const TreeNode *node, std::vector<TreeNode::datatype> &result) const
{
    if (node != nullptr)
    {
        result.push_back(node->data);
        preorderRecursive(node->left.get(), result);
        preorderRecursive(node->right.get(), result);
    }
}

std::vector<TreeNode::datatype> BinarySearchTree::postorderTraversal() const
{
    std::vector<TreeNode::datatype> result;
    postorderRecursive(root.get(), result);
    return result;
}

void BinarySearchTree::postorderRecursive(const TreeNode *node, std::vector<TreeNode::datatype> &result) const
{
    if (node != nullptr)
    {
        postorderRecursive(node->left.get(), result);
        postorderRecursive(node->right.get(), result);
        result.push_back(node->data);
    }
}

std::vector<TreeNode::datatype> BinarySearchTree::levelOrderTraversal() const
{
    std::vector<TreeNode::datatype> result;
    if (isEmpty())
        return result;
    std::deque<TreeNode *> queue = {root.get()};

    while (!queue.empty())
    {
        int numNodesCurrLevel = queue.size();
        for (size_t i = 0; i < numNodesCurrLevel; i++)
        {
            TreeNode *currNode = queue.front();
            queue.pop_front();
            result.push_back(currNode->data);

            if (currNode->left)
                queue.push_back(currNode->left.get());
            if (currNode->right)
                queue.push_back(currNode->right.get());
        }
    }

    return result;
}
