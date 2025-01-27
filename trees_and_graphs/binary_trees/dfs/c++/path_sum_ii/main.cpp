// main.cpp
#include "tree_node.hpp"
#include "path_sum_ii.hpp"
#include <vector>
#include <map>
#include <iostream>

void printVectorOfVectors(const std::vector<std::vector<int>> &vectors)
{
    std::cout << "{";
    for (size_t i = 0; i < vectors.size(); ++i)
    {
        std::cout << "{";
        for (size_t j = 0; j < vectors[i].size(); ++j)
        {
            std::cout << vectors[i][j];
            if (j < vectors[i].size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "}";
        if (i < vectors.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "}" << '\n';
}

int main()
{
    using vectorDataType = std::vector<TreeNode::datatype>;
    std::map<vectorDataType, int> testCases = {
        {{5, 4, 8, 11, std::monostate{}, 13, 4, 7, 2, std::monostate{}, std::monostate{}, 5, 1}, 22},
        {{1, 2, 3}, 5},
        {{1, 2, 2, 2, 2, 2, 2}, 5},
        {{}, 0}};

    for (auto &[nodeData, target] : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        std::vector<std::vector<int>> paths = pathSum(root, target);
        std::cout << "Searched paths = ";
        printVectorOfVectors(paths);
    }
    std::cout << std::endl;

    return 0;
}
