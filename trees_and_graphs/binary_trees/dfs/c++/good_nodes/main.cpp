// main.cpp
#include "tree_node.hpp"
#include "good_nodes.hpp"
#include <iostream>
#include <vector>

int main()
{
    // Test cases
    using VectorDataType = std::vector<TreeNode::datatype>;
    std::vector<VectorDataType> testCases = {
        {3, 1, 4, 3, std::monostate{}, 1, 5},
        {3, 3, std::monostate{}, 4, 2},
        {1}};

    for (const auto &nodeData : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        int totalNumGoodNodes = Solution::goodNodes(root);
        std::cout << "The total number of good nodes in the binary tree is " << totalNumGoodNodes << '\n';
    }
    std::cout << std::endl;

    return 0;
}
