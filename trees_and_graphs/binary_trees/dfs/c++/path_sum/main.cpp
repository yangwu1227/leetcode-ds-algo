// main.cpp
#include "tree_node.hpp"
#include "path_sum.hpp"
#include <vector>
#include <map>
#include <iostream>

int main()
{
    using vectorDataType = std::vector<TreeNode::datatype>;
    std::map<vectorDataType, int> testCases = {
        {{5, 4, 8, 11, std::monostate{}, 13, 4, 7, 2, std::monostate{}, std::monostate{}, std::monostate{}, 1}, 22},
        {{1, 2, 3}, 5},
        {{7, 12, std::monostate{}, 8, 9, 12, 7, 17, std::monostate{}, std::monostate{}, 19, 27, std::monostate{}}, 58}};

    for (const auto &[nodeData, target] : testCases)
    {
        TreeNode::ptr root = TreeNode::construct_binary_tree(nodeData);
        bool pathExists = PathSum::searchPath(root, target);
        std::cout << "There exists " << (pathExists ? "a" : "no") << " path such that sum of all data values equals target = ";
        std::cout << target << '\n';
    }
    std::cout << std::endl;
    return 0;
}
