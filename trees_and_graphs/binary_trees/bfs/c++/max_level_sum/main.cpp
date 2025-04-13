// main.cpp
#include "max_level_sum.hpp"
#include "tree_node.hpp"
#include <vector>
#include <iostream>

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;

    std::vector<VectorDataType> testCases = {
        {1, 7, 0, 7, -8, std::monostate{}, std::monostate{}},
        {989, std::monostate{}, 10250, 98693, -89388, std::monostate{}, std::monostate{}, std::monostate{}, -32127},
        {},
        {8},
        {1, 7, 0, 7, -8, std::monostate{}, std::monostate{}, 23, 17, std::monostate{}, 8, 12, 77, 53}};

    for (auto &nodeData : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        int maxLevel = maxLevelSum(root);

        std::cout << "The smallest level with maximal level sum is " << maxLevel << '\n';
    }
    std::cout << std::endl;

    return 0;
}
