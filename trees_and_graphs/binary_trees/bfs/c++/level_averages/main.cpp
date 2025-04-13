// main.cpp
#include "level_averages.hpp"
#include "tree_node.hpp"
#include <vector>
#include <iostream>
#include <iomanip> // For precision control

void printVector(const std::vector<double> &vector, int precision = 2)
{
    std::cout << std::fixed << std::setprecision(precision) << "{";
    for (auto const &element : vector)
    {
        std::cout << element << (&element != &vector.back() ? ", " : "");
    }
    std::cout << "}";
}

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;

    std::vector<VectorDataType> testCases = {
        {3, 8, 20, std::monostate{}, std::monostate{}, 15, 7},
        {3, 9, 20, 15, 7},
        {10},
        {2147483647, 2147483647, 2},
        {}};

    for (auto &nodeData : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        std::vector<double> output = computeLevelAverages(root);

        std::cout << "The output of level averages is ";
        printVector(output);
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
