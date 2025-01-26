// main.cpp
#include "tree_node.hpp"
#include "tree_utils.hpp"
#include "symmetric_tree.hpp"
#include <vector>
#include <iostream>

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;
    std::vector<VectorDataType> testCases = {
        {1, 2, 2, 3, 4, 4, 3},
        {1, 2, 2, 8, 4, 4, 7},
        {1, 2, 2, std::monostate{}, 3, std::monostate{}, 3}};

    tree_utils::TreePrinter printer;

    for (auto &nodeData : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        bool symmetric = SymmetricTree::check(root);
        std::cout << "The binary tree " << (symmetric ? "is" : "is not") << " symmetric:\n";
        printer.printLevelOrder(root);
        std::cout << "\n\n";
    }
    std::cout << std::endl;

    return 0;
}
