from typing import Optional

from tree_node import TreeNode


class TreeDiameterCalculator(object):
    def __init__(self) -> None:
        """
        Initialize the TreeDiameterCalculator instance.

        Attributes
        ----------
        diameter : int
            The maximum diameter found during the depth-first search traversal.
        """
        self.diameter: int = 0

    def _depth_first_search(self, node: Optional[TreeNode]) -> int:
        """
        Perform a depth-first search to calculate the height of subtrees and update the diameter.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node in the binary tree.

        Returns
        -------
        int
            The height of the subtree rooted at the given node.
        """
        if not node:
            return 0

        left_subtree_height: int = self._depth_first_search(node.left)
        right_subtree_height: int = self._depth_first_search(node.right)

        self.diameter = max(self.diameter, left_subtree_height + right_subtree_height)
        return max(left_subtree_height, right_subtree_height) + 1

    def find_diameter(self, root: Optional[TreeNode]) -> int:
        """
        Calculate the diameter of a binary tree.

        Parameters
        ----------
        root : Optional[TreeNode]
            The root node of the binary tree.

        Returns
        -------
        int
            The diameter of the binary tree, defined as the longest path
            between any two nodes.

        Raises
        ------
        RuntimeError
            If the method is called on an instance that has already processed a tree.
        """
        if self.diameter > 0:
            raise RuntimeError(
                "This instance has already processed a tree; please create a new instance"
            )
        _ = self._depth_first_search(root)
        return self.diameter


def main() -> int:
    test_cases = [
        [1, 2, 3, 4, 5],
        [1, 2],
        [3, 7, 9, None, 7, None, 8, 9, 10, 233, 17, None, 23],
    ]
    for node_data in test_cases:
        print("Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(node_data)
        tree_diameter_calculator: TreeDiameterCalculator = TreeDiameterCalculator()
        tree_diameter: int = tree_diameter_calculator.find_diameter(root=root)
        print(f"\nThe tree diameter is {tree_diameter}\n\n")
    return 0


if __name__ == "__main__":
    main()
