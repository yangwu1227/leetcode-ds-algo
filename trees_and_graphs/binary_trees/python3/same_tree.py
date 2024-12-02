from typing import Optional

from tree_node import TreeNode


class Solution(object):
    @staticmethod
    def depth_first_search(left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
        """
        Recursively compares two binary tree nodes to determine if they are the same.

        Parameters
        ----------
        left : Optional[TreeNode]
            The left node of the first binary tree to compare
        right : Optional[TreeNode]
            The right node of the second binary tree to compare

        Returns
        -------
        bool
            True if the two nodes (and their subtrees) are identical, otherwise False
        """
        if left is None and right is None:
            print(f"    Both nodes are None returning True")
            return True
        if left is None or right is None:
            print(f"    One node is None (left: {left}, right: {right}) | returning False")
            return False

        print(
            f"    Comparing nodes (left: {left.data}, right: {right.data}) "
            f"{'Equal' if left.data == right.data else 'Not equal'}."
        )
        left_subtree_result = Solution.depth_first_search(left.left, right.left)
        right_subtree_result = Solution.depth_first_search(left.right, right.right)
        result = left.data == right.data and left_subtree_result and right_subtree_result
        print(f"    Returning {result} for nodes (left: {left.data}, right: {right.data})")
        return left.data == right.data and left_subtree_result and right_subtree_result

    @staticmethod
    def same_tree(first_tree: Optional[TreeNode], second_tree: Optional[TreeNode]) -> bool:
        """
        Determines whether two binary trees are the same.

        Parameters
        ----------
        first_tree : Optional[TreeNode]
            The root of the first binary tree
        second_tree : Optional[TreeNode]
            The root of the second binary tree

        Returns
        -------
        bool
            True if the two trees are identical, otherwise False
        """
        if not first_tree and not second_tree:
            print(f"  Both trees have just one node")
            return True
        return Solution.depth_first_search(first_tree, second_tree)


def main() -> int:
    test_cases = [
        ([], []),
        ((1, 2, 3), (1, 2, 3)),
        ([1, 2, 1, None], [1, None, 1, 7]),
        ([1, 9, 7, None], (1, 9, 7, None)),
        ([1, 3, 5, 7, 10], [1, 3, 5, 7, 9]),
    ]
    for first_tree_vals, second_tree_vals in test_cases:
        print("Case " + "-" * 60, "\n")
        first_tree = TreeNode.construct_binary_tree(first_tree_vals)
        second_tree = TreeNode.construct_binary_tree(second_tree_vals)
        same_tree = Solution.same_tree(first_tree, second_tree)
        print(
            f"The two trees {first_tree_vals} and {second_tree_vals} are{f' not ' if not same_tree else ' '}the same\n\n"
        )
    return 0


if __name__ == "__main__":
    main()
