// leaf_similar.hpp
#ifndef LEAF_SIMILAR_HPP
#define LEAF_SIMILAR_HPP
#include "tree_node.hpp"

class LeafSimilar
{
public:
    /**
     * @brief
     *
     * @param root1 A unique pointer to the first root node
     * @param root2 A unique pointer to the second root node
     *
     * @return bool `true` if the two trees are leaf-similar otherwise `false`
     */
    static bool check(TreeNode::ptr &root1, TreeNode::ptr &root2);
};

#endif
