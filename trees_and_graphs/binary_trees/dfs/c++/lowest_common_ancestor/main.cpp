// main.cpp
#include "lowest_common_ancestor.hpp"
#include <unordered_map>
#include <vector>
#include <tuple>
#include <ostream>

int main()
{
    using vectorDataType = std::vector<TreeNode::datatype>;
    using testCase = std::tuple<vectorDataType, int, int>;
    std::vector<testCase> testCases = {
        {{3, 5, 1, 6, 2, 0, 8, std::monostate{}, std::monostate{}, 7, 4}, 5, 1},
        {{3, 5, 1, 7, 2, 0, 8, std::monostate{}, std::monostate{}, 8, 4}, 5, 4},
        {{1, 2}, 1, 2}};

    for (const auto &[nodeData, pData, qData] : testCases)
    {
        // Root node
        TreeNode::ptr root = TreeNode::constructBinaryTree(nodeData);
        // Raw pointers
        TreeNode::ptr pPointer = std::make_unique<TreeNode>(pData);
        TreeNode *p = pPointer.get();
        TreeNode::ptr qPointer = std::make_unique<TreeNode>(qData);
        TreeNode *q = qPointer.get();

        TreeNode::ptr lca = nullptr;
        if (TreeNode *rawLca = lowestCommonAncestor(p, q, root))
        {
            lca = std::make_unique<TreeNode>(rawLca->data);
        }
        std::cout << "The lowest common ancester node is " << *lca << '\n';
    }
    std::cout << std::endl;

    return 0;
}
