// main.cpp
#include "max_zigzag.hpp"
#include "tree_node.hpp"
#include <vector>
#include <iostream>

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;
    std::vector<VectorDataType> testCases = {
        {1, std::monostate{}, 1, 1, 1, std::monostate{}, std::monostate{}, 1, 1, std::monostate{},
         1, std::monostate{}, std::monostate{}, std::monostate{}, 1},
        {1, 1, 1, std::monostate{}, 1, std::monostate{}, std::monostate{}, 1, 1, std::monostate{}, 1},
        {1}};

    for (auto &nodeData : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        int maxLen = maxZigZag(root);
        std::cout << "The maximum length among all ZigZag paths is " << maxLen << '\n';
    }
    std::cout << std::endl;

    return 0;
}
