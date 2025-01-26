// main.cpp
#include "invert_tree.hpp"
#include "tree_node.hpp"
#include "tree_utils.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <queue>

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;
    std::vector<VectorDataType> testCases = {
        {4, 2, 7, 1, 3, 6, 9},
        {2, 1, 3},
        {},
        {9, 12, 7, std::monostate{}, 9, 20, std::monostate{}, 8}};

    tree_utils::TreePrinter printer;

    for (auto &nodeData : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        std::cout << "Nodes before inversion:\n";
        printer.printLevelOrder(root);
        // Invert the tree
        InvertTree::invert(root);
        std::cout << "Nodes after inversion:\n";
        printer.printLevelOrder(root);
        std::cout << "--------------------\n";
    }
    std::cout << std::endl;

    return 0;
}
