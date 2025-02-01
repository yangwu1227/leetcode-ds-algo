// main.cpp
#include "tree_node.hpp"
#include "path_sum_iii.hpp"
#include <vector>
#include <map>
#include <iostream>

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;
    std::map<VectorDataType, int> testCases = {
        {{5, 4, 8, 11, std::monostate{}, 13, 4, 7, 2, std::monostate{}, std::monostate{}, 5, 1}, 22},
        {{1, 2, 3}, 5},
        {{1, 2, 2, 2, 2, 2, 2}, 5},
        // Test for integer overflow
        {{1000000000, 1000000000, 294967296, std::monostate{}, 1000000000, std::monostate{}, 1000000000, std::monostate{}, 1000000000}, 0}};

    for (auto &[nodeData, target] : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        int numPaths = pathSum(root, target);
        std::cout << "Number of paths found = " << numPaths << '\n';
    }
    std::cout << std::endl;

    return 0;
}
