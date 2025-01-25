from collections import deque
from typing import Deque, List, Optional, Tuple

from tree_node import TreeNode


class LeafSimilar(object):
    """
    A class to compare two binary trees and determine if they are leaf-similar.

    Attributes
    ----------
    _queue : Deque[Optional[int] | Optional[float]]
        A queue to store leaf nodes' data during the traversal.
    _similar : bool
        A flag to indicate if the trees are leaf-similar.
    """

    def __init__(self) -> None:
        """
        Initializes the instance.
        """
        self._internal_deque: Deque[Optional[int] | Optional[float]] = deque()
        self._similar: bool = True

    def depth_first_search(
        self, node: Optional[TreeNode], enqueque_mode: bool
    ) -> Optional[int] | Optional[float]:
        """
        Perform a depth-first search on the binary tree.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node of the binary tree.
        enqueque_mode : bool
            The mode of operation: 'enquequeque' to enquequeue leaf nodes, 'dequeque' to compare leaf nodes and dequeue.

        Returns
        -------
        Optional[int] | Optional[float]
            The data of the current node if it exists otherwise None.
        """
        if not node:
            return None

        left_subtree_result = self.depth_first_search(node.left, enqueque_mode)
        right_subtree_result = self.depth_first_search(node.right, enqueque_mode)

        if not left_subtree_result and not right_subtree_result:
            if enqueque_mode:
                self._internal_deque.append(node.data)
            else:
                if self._internal_deque and node.data == self._internal_deque[0]:
                    self._internal_deque.popleft()
                else:
                    self._similar = False

        return node.data

    def check(self, root_1: Optional[TreeNode], root_2: Optional[TreeNode]) -> bool:
        """
        Check if two binary trees are leaf-similar.

        Parameters
        ----------
        root_1 : Optional[TreeNode]
            The root of the first binary tree.
        root_2 : Optional[TreeNode]
            The root of the second binary tree.

        Returns
        -------
        bool
            True if the two trees are leaf-similar otherwise False.
        """
        self.depth_first_search(root_1, True)
        self.depth_first_search(root_2, False)
        return len(self._internal_deque) == 0 and self._similar


def main() -> int:
    test_cases: List[Tuple[List[Optional[int]], List[Optional[int]]]] = [
        (
            [3, 5, 1, 6, 2, 9, 8, None, None, 7, 4],
            [3, 5, 1, 6, 7, 4, 2, None, None, None, None, None, None, 9, 8],
        ),
        (
            [3, 5, 1, 6, 2, 9, 8, None, None, 7, 4],
            [3, 5, 1, 6, 7, 4, 2, None, None, None, None, None, None, 9, 11, None, None, 8, 10],
        ),
        ([1, 2, 3], [1, 2, 3]),
    ]

    for node_data_1, node_data_2 in test_cases:
        print("Case " + "-" * 60, "\n")
        root_1: Optional[TreeNode] = TreeNode.construct_binary_tree(node_data_1)
        root_2: Optional[TreeNode] = TreeNode.construct_binary_tree(node_data_2)
        leaf_similar: LeafSimilar = LeafSimilar()
        similar: bool = leaf_similar.check(root_1, root_2)
        print(
            f"\nThe two trees {root_1} and {root_2} {f'are not' if not similar else 'are'} leaf-similar\n\n"
        )

    return 0


if __name__ == "__main__":
    main()
