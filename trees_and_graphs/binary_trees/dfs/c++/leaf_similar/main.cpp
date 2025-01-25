// main.cpp
#include "tree_node.hpp"
#include "leaf_similar.hpp"
#include <vector>
#include <tuple>
#include <iostream>

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;
    std::vector<std::tuple<VectorDataType, VectorDataType>> testCases = {
        {{3, 5, 1, 6, 2, 9, 8, std::monostate{}, std::monostate{}, 7, 4}, {3, 5, 1, 6, 7, 4, 2, std::monostate{}, std::monostate{}, std::monostate{}, std::monostate{}, std::monostate{}, std::monostate{}, 9, 8}},
        {{3, 5, 1, 6, 2, 9, 8, std::monostate{}, std::monostate{}, 7, 4}, {3, 5, 1, 6, 7, 4, 2, std::monostate{}, std::monostate{}, std::monostate{}, std::monostate{}, std::monostate{}, std::monostate{}, 9, 11, std::monostate{}, std::monostate{}, 8, 10}},
        {{1, 2, 3}, {1, 2, 3}},
        {{1, 2, 3, std::monostate{}, 9, 17, 18}, {1, 12, 3, std::monostate{}, 9, 18, 12}}};

    for (auto &[nodeData1, nodeData2] : testCases)
    {
        TreeNode::ptr root1 = TreeNode::constructBinaryTree(nodeData1);
        TreeNode::ptr root2 = TreeNode::constructBinaryTree(nodeData2);

        bool similar = LeafSimilar::check(root1, root2);
        std::cout << "The two trees " << *root1 << " and " << *root2 << (similar ? " are " : " are not ") << "leaf-similar" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
