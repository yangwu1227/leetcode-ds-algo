// main.cpp
#include "tree_node.hpp"
#include "max_depth.hpp"
#include <iostream>
#include <vector>
#include <variant>

int main()
{
    std::vector<std::vector<TreeNode::datatype>> testCases = {
        {3, 9, 20, std::monostate{}, std::monostate{}, 15, 7},
        {1, std::monostate{}, 2},
        {1, std::monostate{}, 2, 9, 10, 23, std::monostate{}, 8, 7, std::monostate{}, 12}};

    for (const auto &nodeData : testCases)
    {
        // Construct binary tree
        TreeNode::ptr root = TreeNode::construct_binary_tree(nodeData);

        // Calculate and print the max depth
        std::cout << "The max depth of the tree is " << maxDepth(root) << '\n';
    }
    std::cout << std::endl;

    return 0;
}
