// main.cpp
#include "tree_node.hpp"
#include "min_depth.hpp"
#include <vector>
#include <iostream>

int main()
{
    using vectorDataType = std::vector<TreeNode::datatype>;
    std::vector<vectorDataType> testCases = {
        {3, 9, 20, std::monostate{}, std::monostate{}, 15, 7},
        {2, std::monostate{}, 3, std::monostate{}, 4, std::monostate{}, 5, std::monostate{}, 6},
        {1, std::monostate{}, std::monostate{}},
        {1, 2, 3, 4, 5, 6}};

    for (const auto &nodeData : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        int depth = minDepth(root);
        std::cout << "The minimum depth of the binary tree is " << depth << '\n';
    }
    std::cout << std::endl;

    return 0;
}
