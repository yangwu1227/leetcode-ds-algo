from collections import deque
from typing import Deque, List, Optional, Tuple

from tree_node import TreeNode


class RangeSum(object):
    """
    Implements logics to calculate the sum of all node values in a binary search tree that fall within a given range.
    """

    def __init__(self, root: Optional[TreeNode], low: int, high: int) -> None:
        """
        Initialize the instance.

        Parameters
        ----------
        root : Optional[TreeNode]
            The root node of the binary search tree.
        low : int
            The lower bound of the range (inclusive).
        high : int
            The upper bound of the range (inclusive).
        """
        self.root: Optional[TreeNode] = root
        self.low: int = low
        self.high: int = high

    def iterative(self) -> int:
        """
        Calculate the range sum using an iterative breadth-first search approach.

        Returns
        -------
        int
            The sum of all node values within the specified range.
        """
        if not self.root:
            return 0
        if not (self.root.left or self.root.right):
            assert isinstance(self.root.data, int)
            return self.root.data if self.low <= self.root.data <= self.high else 0

        queue: Deque[TreeNode] = deque([self.root])
        range_sum: int = 0

        while queue:
            curr_node: TreeNode = queue.popleft()
            assert isinstance(curr_node.data, int)
            curr_data: int = curr_node.data
            if self.low <= curr_node.data <= self.high:
                range_sum += curr_node.data
            if curr_node.left and curr_data > self.low:
                queue.append(curr_node.left)
            if curr_node.right and curr_data < self.high:
                queue.append(curr_node.right)

        return range_sum

    def _depth_first_search(self, node: Optional[TreeNode], curr_sum: int) -> int:
        """
        Helper method for recursive calculation using depth-first search.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node being processed.
        curr_sum : int
            The accumulated sum so far.

        Returns
        -------
        int
            The sum of all node values within the specified range in the subtree.
        """
        cumulative_sum: int = 0
        if not node:
            return 0
        assert isinstance(node.data, int)
        if self.low <= node.data <= self.high:
            cumulative_sum += node.data

        if node.data > self.low:
            cumulative_sum += self._depth_first_search(node.left, cumulative_sum)
        if node.data < self.high:
            cumulative_sum += self._depth_first_search(node.right, cumulative_sum)

        return cumulative_sum

    def recursive(self) -> int:
        """
        Calculate the range sum using a recursive depth-first search approach.

        Returns
        -------
        int
            The sum of all node values within the specified range.
        """
        if not self.root:
            return 0
        if not (self.root.left or self.root.right):
            assert isinstance(self.root.data, int)
            return self.root.data if self.low <= self.root.data <= self.high else 0

        return self._depth_first_search(self.root, 0)


def main() -> int:
    test_cases: List[Tuple[Tuple[int, int], List[Optional[int]]]] = [
        ((7, 15), [10, 5, 15, 3, 7, None, 18]),
        ((6, 10), [10, 5, 15, 3, 7, 13, 18, 1, None, 6]),
        ((12, 17), [3]),
        ((7, 27), [9, 12, 34, None, 4, None, None, 7, 27, 89, 32, None]),
    ]
    for (low, high), node_data in test_cases:
        print(f"Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=node_data)
        range_sum = RangeSum(root=root, low=low, high=high)
        range_sum_iterative: int = range_sum.iterative()
        range_sum_recursive: int = range_sum.recursive()
        assert range_sum_iterative == range_sum_recursive
        print(f"The range sum of all nodes between {low} and {high} is {range_sum_iterative}\n")

    return 0


if __name__ == "__main__":
    main()
