from sys import maxsize
from typing import List, Optional

from tree_node import TreeNode


class Solution(object):
    @staticmethod
    def depth_first_search(current_max: int, current_min: int, node: Optional[TreeNode]) -> int:
        """
        Perform a depth-first search to calculate the maximum difference between ancestor and descendant nodes in a binary tree.

        Parameters
        ----------
        current_max : int
            The maximum value encountered along the current path.
        current_min : int
            The minimum value encountered along the current path.
        node : Optional[TreeNode]
            The current node being processed.

        Returns
        -------
        int
            The maximum difference between ancestor and descendant nodes along the current path.
        """
        if not node:
            print(
                f"    A leaf node is encountered, returning |{current_max} - {current_min}| = {abs(current_max - current_min)}"
            )
            return abs(current_max - current_min)

        if isinstance(node.data, int):
            updated_max: int = max(current_max, node.data)
            updated_min: int = min(current_min, node.data)
            print(
                f"  Current node data = {node.data} | Current (max, min) = {current_max, current_min} | Update (max, min) = {updated_max, updated_min}"
            )
        else:
            raise ValueError("Node data must be integers")

        left_max_diff: int = Solution.depth_first_search(updated_max, updated_min, node.left)
        right_max_diff: int = Solution.depth_first_search(updated_max, updated_min, node.right)
        print(
            f" Left subtree max diff = {left_max_diff} | Right subtree max diff = {right_max_diff}"
        )

        return max(left_max_diff, right_max_diff)

    @staticmethod
    def max_ancestor_diff(root: Optional[TreeNode]) -> int:
        """
        Compute the maximum value `v` such that there exist different nodes `a` and `b` where
        `v = |a.val - b.val|` and `a` is an ancestor of `b`.

        Parameters
        ----------
        root : Optional[TreeNode]
            The root of the binary tree.

        Returns
        -------
        int
            The maximum difference `v` between the values of ancestor and descendant nodes.
        """
        if not root:
            return 0
        current_max: int = -maxsize
        current_min: int = maxsize
        return Solution.depth_first_search(current_max, current_min, root)


def main() -> int:
    test_cases: List[List[Optional[int]]] = [
        [8, 3, 10, 1, 6, None, 14, None, None, 4, 7, 13],
        [1, None, 2, None, 0, 3],
    ]

    for node_data in test_cases:
        print("Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=node_data)
        max_diff: int = Solution.max_ancestor_diff(root)
        print(f"\nThe maximum difference found is {max_diff}\n\n")

    return 0


if __name__ == "__main__":
    main()
