// main.cpp
#include "max_ancestor_diff.hpp"
#include "tree_node.hpp"
#include <iostream>
#include <vector>

int main()
{
    using vectorDataType = std::vector<TreeNode::datatype>;
    std::vector<vectorDataType> testCases = {
        {8, 3, 10, 1, 6, std::monostate{}, 14, std::monostate{}, std::monostate{}, 4, 7, 13},
        {1, std::monostate{}, 2, std::monostate{}, 0, 3}};

    for (auto &nodeData : testCases)
    {
        TreeNode::ptr root = TreeNode::construct_binary_tree(nodeData);
        int maxDiff = Solution::maxAncestorDiff(root);
        std::cout << "The maximum difference between a node and its ancestor in the binary tree is " << maxDiff << '\n';
    }
    std::cout << std::endl;

    return 0;
}
