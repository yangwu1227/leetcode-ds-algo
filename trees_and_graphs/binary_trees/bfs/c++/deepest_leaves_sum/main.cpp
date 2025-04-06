// main.cpp
#include "deepest_leaves_sum.hpp"
#include "tree_node.hpp"
#include <vector>
#include <iostream>

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;

    std::vector<VectorDataType> testCases = {
        {1, 2, 3, 4, 5, std::monostate{}, 6, 7, std::monostate{}, std::monostate{}, std::monostate{}, std::monostate{}, 8},
        {6, 7, 8, 2, 7, 1, 3, 9, std::monostate{}, 1, 4, std::monostate{}, std::monostate{}, std::monostate{}, 5},
        {},
        {3},
    };

    for (auto &nodeData : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        int leavesSum = deepestLeavesSum(root);

        std::cout << "The sum of the last level of the tree is " << leavesSum << '\n';
    }
    std::cout << std::endl;

    return 0;
}
