// main.cpp
#include "tree_diameter.hpp"
#include "tree_node.hpp"
#include <vector>
#include <iostream>

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;

    std::vector<VectorDataType> testCases = {
        {1, 2, 3, 4, 5},
        {1, 2},
        {3, 7, 9, std::monostate{}, 7, std::monostate{}, 8, 9, 10, 233, 17, std::monostate{}, 23}};

    for (auto &nodeData : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        TreeDiameterCalculator calculator = TreeDiameterCalculator();
        int treeDiameter = calculator.findDiameter(root);
        std::cout << "The tree diameter of the binary tree is " << treeDiameter << '\n';
    }
    std::cout << std::endl;

    return 0;
}
