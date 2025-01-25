from copy import deepcopy
from typing import List, Optional

from tree_node import TreeNode


class InvertTree(object):
    """
    A class that implements binary tree inversion.
    """

    @staticmethod
    def depth_first_search(node: Optional[TreeNode]) -> Optional[TreeNode]:
        """
        Performs a post-order depth-first traversal to invert the binary tree.

        Parameters
        ----------
        node : Optional[TreeNode]
            The root node of the binary tree or subtree.

        Returns
        -------
        Optional[TreeNode]
            The root node of the inverted binary tree or subtree.
        """
        if not node:
            return None

        left_subtree: Optional[TreeNode] = InvertTree.depth_first_search(node.left)
        right_subtree: Optional[TreeNode] = InvertTree.depth_first_search(node.right)

        # Swap the left and right substrees
        node.left, node.right = right_subtree, left_subtree

        return node

    @staticmethod
    def invert(root: Optional[TreeNode]) -> Optional[TreeNode]:
        """
        Inverts a binary tree by swapping left and right subtrees recursively.

        Parameters
        ----------
        root : Optional[TreeNode]
            The root node of the binary tree.

        Returns
        -------
        Optional[TreeNode]
            The root node of the inverted binary tree.
        """
        if not root:
            return root
        _: Optional[TreeNode] = InvertTree.depth_first_search(root)
        return root


def main() -> int:
    test_cases: List[List[Optional[int]]] = [
        [4, 2, 7, 1, 3, 6, 9],
        [2, 1, 3],
        [],
        [9, 12, 7, None, 9, 20, None, 8],
    ]

    for node_data in test_cases:
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(node_data)
        root_before: Optional[TreeNode] = deepcopy(root)
        _: Optional[TreeNode] = InvertTree.invert(root)
        if root and root_before:
            TreeNode.visualize_binary_tree(root=root_before)
            TreeNode.visualize_binary_tree(root=root)

    return 0


if __name__ == "__main__":
    main()
