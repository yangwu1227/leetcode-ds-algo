// main.cpp
#include "remove_leaves.hpp"
#include "tree_node.hpp"
#include "tree_utils.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <map>

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;
    std::map<VectorDataType, int> testCases = {
        {{1, 2, 3, 2, std::monostate{}, 2, 4}, 2},
        {{1, 3, 3, 3, 2}, 3},
        {{1, 2, std::monostate{}, 2, std::monostate{}, 2}, 2}};

    tree_utils::TreePrinter printer;

    for (auto &[nodeData, target] : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        std::cout << "Nodes before pruning:\n";
        printer.printLevelOrder(root);

        // Prune the tree and update the root pointer
        root = removeLeaves(root, target);

        std::cout << "Nodes after pruning:\n";
        printer.printLevelOrder(root);
        std::cout << "--------------------\n";
    }
    std::cout << std::endl;

    return 0;
}
