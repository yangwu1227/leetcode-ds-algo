// binary_search_tree.hpp
#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include "tree_node.hpp"
#include <vector>
#include <optional>

/**
 * @class BinarySearchTree
 *
 * @brief Implementation of a Binary Search Tree data structure with smart pointer-based memory management
 */
class BinarySearchTree
{
public:
    /**
     * @brief Construct a new empty Binary Search Tree instance
     */
    explicit BinarySearchTree();

    /**
     * @brief Destroy the Binary Search Tree instance and recursively free all nodes
     */
    ~BinarySearchTree();

    /**
     * @brief Check if the tree is empty
     *
     * @return bool `true` if the tree is empty, `false` otherwise
     */
    bool isEmpty() const;

    /**
     * @brief Get the number of nodes in the tree
     *
     * @return size_t The number of nodes in the tree
     */
    size_t size() const;

    /**
     * @brief Insert a new node with the given data
     *
     * @param data Reference to the data to insert into the tree
     * @return bool `true` if a new node was inserted, `false` if an existing node was updated
     */
    bool insert(const TreeNode::datatype &data);

    /**
     * @brief Search for a node with the given data
     *
     * @param data Reference to the data to search for
     * @return const TreeNode* Non-owning raw pointer to the node containing the data, or nullptr if not found
     */
    const TreeNode *search(const TreeNode::datatype &data) const;

    /**
     * @brief Remove a node with the given data using Hibbard deletion
     *
     * @param data Reference to the data to remove from the tree
     * @return bool `true` if a node was removed, `false` otherwise
     */
    bool remove(const TreeNode::datatype &data);

    /**
     * @brief Check if the tree contains a node with the given data
     *
     * @param data Reference to the data to check for
     * @return bool `true` if the tree contains the data, `false` otherwise
     */
    bool contains(const TreeNode::datatype &data) const;

    /**
     * @brief Find the node with the minimum data in the tree
     *
     * @return const TreeNode* Non-owning raw pointer to the node with the minimum data,
     *                         or nullptr if tree is empty
     */
    const TreeNode *findMinNode() const;

    /**
     * @brief Find the node with the maximum data in the tree
     *
     * @return const TreeNode* Non-owning raw pointer to the node with the maximum data,
     *                         or nullptr if tree is empty
     */
    const TreeNode *findMaxNode() const;

    /**
     * @brief Find the largest key less than or equal to the given target
     *
     * @param target Reference to the target to find the floor of
     * @return std::optional<TreeNode::datatype> The floor value if found, or std::nullopt if none exists
     */
    std::optional<TreeNode::datatype> floor(const TreeNode::datatype &target) const;

    /**
     * @brief Find the smallest key greater than or equal to the given target
     *
     * @param target Reference to the target to find the ceiling of
     *
     * @return std::optional<TreeNode::datatype> The ceiling value if found, or `std::nullopt` if none exists
     */
    std::optional<TreeNode::datatype> ceiling(const TreeNode::datatype &target) const;

    /**
     * @brief Return the number of keys less than the given data (its rank)
     *
     * @param data Reference to the data to find the rank of
     * @return int The number of keys less than the given data
     */
    int rank(const TreeNode::datatype &data) const;

    /**
     * @brief Find the node of rank `k` in the binary search tree (i.e., the kth smallest node)
     *
     * @param k The rank (0-indexed)
     *
     * @return std::optional<TreeNode::datatype> The key of rank k if found, or `std::nullopt` if k is out of bounds
     */
    std::optional<TreeNode::datatype> select(int k) const;

    /**
     * @brief Check if the tree satisfies the binary search tree invariant
     *
     * @return bool `true` if the tree is a valid binary search tree, `false` otherwise
     */
    bool isValidBst() const;

    /**
     * @brief Get the height of the tree (path length from root to deepest leaf)
     *
     * @return int The height of the tree, -1 for empty tree
     */
    int height() const;

    /**
     * @brief Perform an inorder traversal of the tree (left-root-right)
     *
     * @return std::vector<TreeNode::datatype> The node values in inorder sequence
     */
    std::vector<TreeNode::datatype> inorderTraversal() const;

    /**
     * @brief Perform a preorder traversal of the tree (root-left-right)
     *
     * @return std::vector<TreeNode::datatype> The node values in preorder sequence
     */
    std::vector<TreeNode::datatype> preorderTraversal() const;

    /**
     * @brief Perform a postorder traversal of the tree (left-right-root)
     *
     * @return std::vector<TreeNode::datatype> The node values in postorder sequence
     */
    std::vector<TreeNode::datatype> postorderTraversal() const;

    /**
     * @brief Perform a level order traversal of the tree (breadth-first)
     *
     * @return std::vector<TreeNode::datatype> The node values in level order sequence
     */
    std::vector<TreeNode::datatype> levelOrderTraversal() const;

private:
    TreeNode::ptr root; // Owning smart pointer to the root node
    size_t size_;       // Number of nodes in the tree

    /**
     * @brief Validate that data is one of the supported variants in TreeNode::datatype
     *
     * @param data Reference to the data to validate
     *
     * @return TreeNode::datatype The validated data
     *
     * @throws std::invalid_argument If the data is not a valid number type
     */
    TreeNode::datatype validateData(const TreeNode::datatype &data) const;

    /**
     * @brief Recursively insert data into the proper position in the BST
     *
     * @param node Reference to the owning smart pointer of the current node being examined
     * @param dataToInsert Reference to the data to insert
     *
     * @return bool `true` if a new node was inserted, `false` if an existing node was updated
     */
    bool insertRecursive(TreeNode::ptr &node, const TreeNode::datatype &dataToInsert);

    /**
     * @brief Recursively search for a node with the given data
     *
     * @param node Non-owning raw pointer to the current node being examined
     * @param dataToSearch Reference to the data to search for
     *
     * @return const TreeNode* Non-owning raw pointer to the node containing the data, or `nullptr` if not found
     */
    const TreeNode *searchRecursive(const TreeNode *node, const TreeNode::datatype &dataToSearch) const;

    /**
     * @brief Find the minimum data value in the subtree
     *
     * @param node Non-owning raw pointer to the root of the subtree
     *
     * @return TreeNode::datatype The minimum data value
     *
     * @note Assumes node is not `nullptr`
     */
    TreeNode::datatype findMinData(const TreeNode *node) const;

    /**
     * @brief Recursively remove a node with the given data using Hibbard deletion
     *
     * @param node Reference to the owning smart pointer of the current node being examined
     * @param dataToRemove Reference to the data to remove
     *
     * @return bool `true` if deletion occurred, `false` otherwise
     */
    bool removeRecursive(TreeNode::ptr &node, const TreeNode::datatype &dataToRemove);

    /**
     * @brief Recursively find the floor of a data value in the BST
     *
     * @param node Non-owning raw pointer to the current node being examined
     * @param target Reference to the target to find the floor of
     *
     * @return const TreeNode* Non-owning raw pointer to the node containing the floor, or `nullptr` if none exists
     */
    const TreeNode *floorRecursive(const TreeNode *node, const TreeNode::datatype &target) const;

    /**
     * @brief Recursively find the ceiling of a data value in the BST
     *
     * @param node Non-owning raw pointer to the current node being examined
     * @param target Reference to the target to find the ceiling of
     *
     * @return const TreeNode* Non-owning raw pointer to the node containing the ceiling, or `nullptr` if none exists
     */
    const TreeNode *ceilingRecursive(const TreeNode *node, const TreeNode::datatype &target) const;

    /**
     * @brief Recursively calculate the rank of a data value
     *
     * @param node Non-owning raw pointer to the current node being examined
     * @param data Reference to the data to find the rank of
     *
     * @return int The number of keys less than the given data in this subtree
     */
    int rankRecursive(const TreeNode *node, const TreeNode::datatype &data) const;

    /**
     * @brief Recursively calculate the size of a subtree
     *
     * @param node Non-owning raw pointer to the root of the subtree
     *
     * @return size_t The number of nodes in the subtree
     */
    size_t sizeRecursive(const TreeNode *node) const;

    /**
     * @brief Recursively select the key of rank k
     *
     * @param node Non-owning raw pointer to the current node being examined
     * @param k The rank to find (0-indexed)
     *
     * @return const TreeNode* Non-owning raw pointer to the node with key of rank k, or `nullptr` if none exists
     */
    const TreeNode *selectRecursive(const TreeNode *node, int k) const;

    /**
     * @brief Recursively validates if a subtree maintains the Binary Search Tree invariant
     *
     * This function checks if the current node's value falls within the allowed range defined by
     * optional minimum and maximum bounds. For the root node, there are initially no constraints
     * (both bounds are `std::nullopt`).
     *
     * As we traverse down the tree, we add constraints:
     *
     *  * Left children must be less than their parent, inheriting the parent’s upper bound
     *  * Right children must be greater than their parent, inheriting the parent’s lower bound
     *
     * @param node Non-owning raw pointer to the current node being examined
     * @param minValue Optional lower bound that all nodes in this subtree must exceed
     * @param maxValue Optional upper bound that all nodes in this subtree must be less than
     *
     * @return bool `true` if the subtree rooted at `node` satisfies the BST property, `false` otherwise
     */
    bool isValidBstRecursive(const TreeNode *node, const std::optional<TreeNode::datatype> &minValue, const std::optional<TreeNode::datatype> &maxValue) const;

    /**
     * @brief Recursively calculate the height of a subtree
     *
     * @param node Non-owning raw pointer to the root of the subtree
     *
     * @return int The height of the subtree, -1 for empty subtree
     */
    int heightRecursive(const TreeNode *node) const;

    /**
     * @brief Recursively perform an inorder traversal (left-root-right)
     *
     * @param node Non-owning raw pointer to the current node being examined
     *
     * @param result Reference to vector to store the traversal result
     */
    void inorderRecursive(const TreeNode *node, std::vector<TreeNode::datatype> &result) const;

    /**
     * @brief Recursively perform a preorder traversal (root-left-right)
     *
     * @param node Non-owning raw pointer to the current node being examined
     *
     * @param result Reference to vector to store the traversal result
     */
    void preorderRecursive(const TreeNode *node, std::vector<TreeNode::datatype> &result) const;

    /**
     * @brief Recursively perform a postorder traversal (left-right-root)
     *
     * @param node Non-owning raw pointer to the current node being examined
     *
     * @param result Reference to vector to store the traversal result
     */
    void postorderRecursive(const TreeNode *node, std::vector<TreeNode::datatype> &result) const;

    /**
     * @brief Recursively free memory of all nodes
     *
     * @param node Reference to the owning smart pointer of the current node to delete
     */
    void clearRecursive(TreeNode::ptr &node);
};

#endif
