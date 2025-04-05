// main.cpp
#include "largest_values.hpp"
#include "tree_node.hpp"
#include <vector>
#include <iostream>

void printVector(const std::vector<int> &vector)
{
    std::cout << "{";
    for (size_t i = 0; i < vector.size(); ++i)
    {
        std::cout << vector[i];
        if (i != vector.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "}";
}

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;

    std::vector<VectorDataType> testCases = {
        {1, 2, 3},
        {1, 3, 2, 5, 3, std::monostate{}, 9},
        {},
        {1, std::monostate{}, 3, 9, 7, 12, std::monostate{}, 8, std::monostate{}, 17, std::monostate{}, std::monostate{}, 27, std::monostate{}, 4, 3, 6, 5, 2},
    };

    for (auto &nodeData : testCases)
    {
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        std::vector<int> largestVals = largestValues(root);

        std::cout << "The maximum data values at each level are ";
        printVector(largestVals);
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
