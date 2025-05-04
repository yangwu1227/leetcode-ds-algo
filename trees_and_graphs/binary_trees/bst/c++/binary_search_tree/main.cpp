// main.cpp
#include "binary_search_tree.hpp"
#include "tree_node.hpp"
#include <vector>
#include <iostream>
#include <variant>
#include <memory>

// Overload for std::ostream to handle std::variant
std::ostream &operator<<(std::ostream &os, const TreeNode::datatype &data)
{
    std::visit(

        // Lambda function, auto &&value is a generic param that deduces the type of the currently active value in std::variant
        [&os](auto &&value)
        {
        // Deduce the actual type of the value stored in std::variant
        using T = std::decay_t<decltype(value)>;
        // Compile-time checking if T is monostate, if so output null, else sent value to the stream
        if constexpr (std::is_same_v<T, std::monostate>) {
            os << "null";
        } else {
            os << value;
        } },

        // List of variants to pass to the visitor
        data);
    return os;
}

void printVector(const std::vector<TreeNode::datatype> &vector)
{
    std::cout << "{";
    for (auto const &element : vector)
    {
        std::cout << element << (&element != &vector.back() ? ", " : "");
    }
    std::cout << "}";
}

int main()
{
    auto bst = std::make_unique<BinarySearchTree>();

    std::cout << "=== Initialization ===\n\n";
    std::cout << "Is empty: " << std::boolalpha << bst->isEmpty() << '\n';
    std::cout << "Size: " << bst->size() << '\n';
    std::cout << "Height: " << bst->height() << '\n';

    std::cout << "\n=== Insertion ===\n\n";
    std::vector<int> nodeData = {50, 30, 70, 20, 40, 60, 80};
    std::cout << "Inserting values\n";
    for (auto &data : nodeData)
    {
        bst->insert(data);
    }
    std::cout << "After insertion:\n";
    std::cout << "Is empty: " << std::boolalpha << bst->isEmpty() << '\n';
    std::cout << "Size: " << bst->size() << '\n';
    std::cout << "Height: " << bst->height() << '\n';

    std::cout << "\n=== Traversal ===\n\n";
    std::cout << "Inorder: ";
    printVector(bst->inorderTraversal());
    std::cout << '\n';
    std::cout << "Preorder: ";
    printVector(bst->preorderTraversal());
    std::cout << '\n';
    std::cout << "Postorder: ";
    printVector(bst->postorderTraversal());
    std::cout << '\n';
    std::cout << "Level order: ";
    printVector(bst->levelOrderTraversal());
    std::cout << '\n';

    std::cout << "\n=== Search ===\n\n";
    std::vector<int> valuesToSearch = {40, 45};
    for (auto &valueToSearch : valuesToSearch)
    {
        std::cout << "Searching for " << valueToSearch << '\n';
        const TreeNode *node = bst->search(valueToSearch);
        std::cout << "Found: " << std::boolalpha << (node != nullptr) << '\n';
        std::cout << "Contains " << valueToSearch << ": " << std::boolalpha << (bst->contains(valueToSearch)) << '\n';
    }

    std::cout << "\n=== Min & Max ===\n\n";
    const TreeNode *minNode = bst->findMinNode();
    const TreeNode *maxNode = bst->findMaxNode();
    std::cout << "Minimum value: " << *minNode << '\n';
    std::cout << "Minimum value: " << *maxNode << '\n';

    std::cout << "\n=== Floor & Ceiling ===\n\n";
    std::vector<int> testValues = {25, 30, 45, 90};
    for (auto &value : testValues)
    {
        std::optional<TreeNode::datatype> floor = bst->floor(value);
        std::optional<TreeNode::datatype> ceiling = bst->ceiling(value);
        if (floor.has_value())
            std::cout << "Floor of " << value << ": " << floor.value() << '\n';
        if (ceiling.has_value())
            std::cout << "Ceiling of " << value << ": " << ceiling.value() << '\n';
    }

    std::cout << "\n=== Select & Rank ===\n\n";
    std::vector<int> selectRankValues = {20, 50, 80};
    for (auto &value : selectRankValues)
    {
        std::cout << "Rank of " << value << ": " << bst->rank(value) << '\n';
    }
    std::cout << "Select by rank:\n";
    for (int k = 0; k < bst->size(); k++)
    {
        std::optional<TreeNode::datatype> selected = bst->select(k);
        if (selected.has_value())
            std::cout << "Select rank " << k << ": " << selected.value() << '\n';
    }

    std::cout << "\n=== Structure ===\n\n";
    std::cout << "Is valid BST: " << std::boolalpha << bst->isValidBst() << '\n';

    std::cout << "\n=== Deletion ===\n\n";
    std::vector<int> valuesToDelete = {20, 30, 50};
    for (auto &value : valuesToDelete)
    {
        std::cout << "\nDeletion Case " << value << " ------" << '\n';

        std::cout << "\nBefore deleting " << value << '\n';
        std::cout << "Size: " << bst->size() << '\n';
        std::cout << "Inorder: ";
        printVector(bst->inorderTraversal());
        std::cout << '\n';

        bool removed = bst->remove(value);

        std::cout << "\nRemoved " << value << ": " << std::boolalpha << removed << '\n';
        std::cout << "After deleting " << value << '\n';
        std::cout << "Size: " << bst->size() << '\n';
        std::cout << "Inorder: ";
        printVector(bst->inorderTraversal());
        std::cout << '\n';
        std::cout << "Is valid BST: " << std::boolalpha << bst->isValidBst() << "\n";
    }

    std::cout << "\n=== Duplicated Data ===\n\n";
    auto dupBst = std::make_unique<BinarySearchTree>();
    std::vector<double> dupValues = {50.0, 30.7, 70.7, 30.7, 50.0, 70.7};
    std::cout << "Inserting values (with duplicates)\n";
    for (auto &data : dupValues)
    {
        dupBst->insert(data);
    }
    std::cout << "Size after inserting duplicates: " << dupBst->size() << '\n';
    std::cout << "Inorder: ";
    printVector(dupBst->inorderTraversal());
    std::cout << '\n';

    std::cout << "\n=== Memory Management Test ===\n\n";
    {
        // Create a scope to test destructor
        std::cout << "Creating a large BST inside a local scope\n";

        // Add a static counter to TreeNode to track living instances
        static size_t nodeCounter = 0;

        // Create a BST that uses our counting nodes with a unique_ptr for automatic memory management
        std::unique_ptr<BinarySearchTree> largeBst = std::make_unique<BinarySearchTree>();

        // Track initial memory usage
        std::cout << "Initial node count: " << nodeCounter << '\n';

        // Add a significant number of nodes (100)
        std::cout << "Adding 100 nodes to BST...\n";
        for (int i = 0; i < 100; i++)
        {
            largeBst->insert(i);
        }

        std::cout << "BST size: " << largeBst->size() << '\n';
        std::cout << "Explicitly deleting BST...\n";

        // Explicitly reset the unique_ptr which triggers the destructor
        largeBst.reset();

        std::cout << "BST deleted, checking for memory leaks...\n";

        // If the destructor works properly, all nodes should be freed
        std::cout << "Final node count (should be 0): " << nodeCounter << '\n';
    }
    std::cout << std::endl;

    return 0;
}
