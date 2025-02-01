from copy import deepcopy
from typing import List, Optional, Tuple

from tree_node import TreeNode


class RemoveLeaves(object):
    """
    A class that implements a pruning algorithm that removes leaves in a binary tree that have a specific target value.
    """

    def __init__(self, target: int) -> None:
        """
        Initialize the RemoveLeaves object with a target value.

        Parameters
        ----------
        target : int
            The target value to identify and remove leaf nodes.
        """
        self.target: int = target

    def depth_first_search(self, node: Optional[TreeNode]) -> Optional[TreeNode]:
        """
        Perform a depth-first search to prune leaves with the target value.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node in the binary tree.

        Returns
        -------
        Optional[TreeNode]
            The modified subtree rooted at this node or None.
        """
        if not node:
            return None

        node.left = self.depth_first_search(node.left)
        node.right = self.depth_first_search(node.right)

        if not node.left and not node.right and node.data == self.target:
            return None
        return node

    def prune(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        """
        Prune the binary tree by removing all leaves with the target value.

        Parameters
        ----------
        root : Optional[TreeNode]
            The root node of the binary tree.

        Returns
        -------
        Optional[TreeNode]
            The root node of the modified binary tree; None if all nodes are removed.
        """
        return self.depth_first_search(root)


def main() -> int:
    test_cases: List[Tuple[List[Optional[int]], int]] = [
        ([1, 2, 3, 2, None, 2, 4], 2),
        ([1, 3, 3, 3, 2], 3),
        ([1, 2, None, 2, None, 2], 2),
    ]

    for node_data, target in test_cases:
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(node_data)
        root_before: Optional[TreeNode] = deepcopy(root)
        remove_leaves: RemoveLeaves = RemoveLeaves(target)
        _: Optional[TreeNode] = remove_leaves.prune(root)
        if root and root_before:
            TreeNode.visualize_binary_tree(root=root_before)
            TreeNode.visualize_binary_tree(root=root)

    return 0


if __name__ == "__main__":
    main()
