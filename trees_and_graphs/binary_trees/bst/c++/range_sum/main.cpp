// main.cpp
#include "range_sum.hpp"
#include "tree_node.hpp"
#include <iostream>
#include <utility> // std::pair, std::make_pair
#include <tuple>   // std::tuple, std::make_tuple
#include <vector>
#include <cassert>

int main()
{
    using VectorDataType = std::vector<TreeNode::datatype>;
    using TestCaseType = std::tuple<std::pair<int, int>, VectorDataType>;

    std::vector<TestCaseType> testCases = {
        std::make_tuple(std::make_pair(7, 15), VectorDataType{10, 5, 15, 3, 7, std::monostate{}, 18}),
        std::make_tuple(std::make_pair(6, 10), VectorDataType{10, 5, 15, 3, 7, 13, 18, 1, std::monostate{}, 6}),
        std::make_tuple(std::make_pair(12, 17), VectorDataType{3}),
        std::make_tuple(std::make_pair(7, 27), VectorDataType{9, 12, 34, std::monostate{}, 4, std::monostate{}, std::monostate{}, 7, 27, 89, 32, std::monostate{}}),
        std::make_tuple(std::make_pair(7, 13), VectorDataType{9, 12, 34, std::monostate{}, 4, std::monostate{}, std::monostate{}, 7, 26, 7, 12, std::monostate{}})};

    for (auto &[range, nodeData] : testCases)
    {
        int low = range.first, high = range.second;
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);

        RangeSum rangeSum = RangeSum(root, low, high);
        int rangeSumIterative = rangeSum.iterative();
        int rangeSumRecursive = rangeSum.resursive();
        assert(rangeSumIterative == rangeSumRecursive);

        std::cout << "The range sum of all nodes between " << low << " and  " << high << " is " << rangeSumRecursive << '\n';
    }
    std::cout << std::endl;

    return 0;
}
