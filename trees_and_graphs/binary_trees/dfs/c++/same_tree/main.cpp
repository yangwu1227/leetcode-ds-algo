// main.cpp
#include "same_tree.hpp"
#include "tree_node.hpp"
#include "tree_utils.hpp"
#include <map>
#include <vector>
#include <iostream>

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;
    std::map<VectorDataType, VectorDataType> testCases = {
        {{1, 3, 2}, {1, 3, 2}},
        {{1, 2}, {1, std::monostate{}, 2}},
        {{1, 2, 1}, {1, 1, 2}},
        {{3.2, 4.5}, {3.2, 4.5}}};

    tree_utils::TreePrinter printer;

    for (const auto &[firstTreeVals, secondTreeVals] : testCases)
    {
        TreeNode::ptr firstTree = TreeNode::constructBinaryTree(firstTreeVals);
        TreeNode::ptr secondTree = TreeNode::constructBinaryTree(secondTreeVals);
        bool sameTree = Solution::sameTree(firstTree, secondTree);

        std::cout << "The two trees ";
        printer.printLevelOrder(firstTree);
        std::cout << "and ";
        printer.printLevelOrder(secondTree);
        std::cout << "are" << (sameTree ? " " : " not ") << "the same" << "\n\n";
    }
    std::cout << std::endl;

    return 0;
}
