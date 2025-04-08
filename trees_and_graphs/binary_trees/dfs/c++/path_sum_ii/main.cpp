// main.cpp
#include "tree_node.hpp"
#include "path_sum_ii.hpp"
#include <vector>
#include <map>
#include <iostream>

void printVectors2D(const std::vector<std::vector<int>> &vectors)
{
    std::cout << "{";
    for (auto &vector : vectors)
    {
        std::cout << "{";
        for (auto &element : vector)
        {
            std::cout << element << (&element != &vector.back() ? ", " : "");
        }
        std::cout << "}" << (&vector != &vectors.back() ? ", " : "");
    }
    std::cout << "}" << '\n';
}

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;
    std::map<VectorDataType, int> testCases = {
        {{5, 4, 8, 11, std::monostate{}, 13, 4, 7, 2, std::monostate{}, std::monostate{}, 5, 1}, 22},
        {{1, 2, 3}, 5},
        {{1, 2, 2, 2, 2, 2, 2}, 5},
        {{}, 0}};

    for (auto &[nodeData, target] : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        std::vector<std::vector<int>> paths = pathSum(root, target);
        std::cout << "Searched paths = ";
        printVectors2D(paths);
    }
    std::cout << std::endl;

    return 0;
}
