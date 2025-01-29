from collections import defaultdict
from typing import DefaultDict, List, Optional, Tuple

from tree_node import TreeNode


class PathSum(object):
    """
    Finds the number of paths in a binary tree where the sum of node values equals a given target.

    Attributes
    ----------
    target : int
        The target sum to find in paths.
    count : int
        The number of valid paths found.
    curr_sum : int
        The running sum of the current path.
    curr_sum_counts : DefaultDict[int, int]
        A hashmap tracking prefix sums and their frequencies.
    """

    def __init__(self, target: int) -> None:
        """
        Initializes the PathSum instance.

        Parameters
        ----------
        target : int
            The target sum to find in paths.
        """
        self.target: int = target
        self.count: int = 0
        self.curr_sum: int = 0
        self.curr_sum_counts: DefaultDict[int, int] = defaultdict(int)

    def depth_first_search(self, node: Optional[TreeNode], depth: int) -> None:
        """
        Performs a depth-first search to count paths that sum to the target.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node being processed.
        depth : int
            The depth of the current node in the tree.
        """
        print_prefix: str = f"{'  ' * depth}Depth {depth} | "
        if not node:
            print(f"{print_prefix}Empty node")
            return None

        assert isinstance(node.data, int)
        print(f"{print_prefix}Current sum ({self.curr_sum}) + Node data ({node.data}) = ", end="")
        print(f"{self.curr_sum + node.data}")
        self.curr_sum += node.data

        print(f"{print_prefix}Current sum ({self.curr_sum}) == target ({self.target}) is ", end="")
        print(f"{self.curr_sum == self.target}")
        if self.curr_sum == self.target:
            print(f"{print_prefix}Total count ({self.count}) + 1 = {self.count + 1}")
            self.count += 1

        print(f"{print_prefix}Current sum ({self.curr_sum}) - target ({self.target}) = ", end="")
        print(f"{self.curr_sum - self.target} is in the counts map? ", end="")
        print(f"{(self.curr_sum - self.target) in self.curr_sum_counts}")
        if (self.curr_sum - self.target) in self.curr_sum_counts:
            print(f"{print_prefix}Total count ({self.count}) ", end="")
            print(f" + Counts for {self.curr_sum - self.target} ", end="")
            print(f"({self.curr_sum_counts[self.curr_sum - self.target]}) = ", end="")
            print(f"{self.count + self.curr_sum_counts[self.curr_sum - self.target]}")
            self.count += self.curr_sum_counts[self.curr_sum - self.target]

        print(f"{print_prefix}Counts hash map before = {self.curr_sum_counts}")
        self.curr_sum_counts[self.curr_sum] += 1
        print(f"{print_prefix}Counts hash map after = {self.curr_sum_counts}")

        self.depth_first_search(node.left, depth + 1)
        self.depth_first_search(node.right, depth + 1)

        backtrace_prefix: str = f"{print_prefix} Backtrace | "
        print(f"{backtrace_prefix}Count for {self.curr_sum} ", end="")
        print(f"({self.curr_sum_counts[self.curr_sum]}) - 1 = ", end="")
        print(f"{self.curr_sum_counts[self.curr_sum] - 1}")
        self.curr_sum_counts[self.curr_sum] -= 1

        print(f"{backtrace_prefix}Remaining count for {self.curr_sum} ", end="")
        print(f" = {self.curr_sum_counts[self.curr_sum]}")
        if not self.curr_sum_counts[self.curr_sum]:
            print(f"{backtrace_prefix}Remove key {self.curr_sum_counts[self.curr_sum]}")
            del self.curr_sum_counts[self.curr_sum]

        print(f"{backtrace_prefix}Current sum ({self.curr_sum}) - Node data ({node.data}) ", end="")
        print(f" = {self.curr_sum - node.data}")
        self.curr_sum -= node.data
        return None

    def search(self, root: Optional[TreeNode]) -> int:
        """
        Search for paths that sum to the target.

        Parameters
        ----------
        root : Optional[TreeNode]
            The root node of the binary tree.

        Returns
        -------
        int
            The number of valid paths found.
        """
        if not root:
            return 0
        self.depth_first_search(root, 0)
        return self.count


def main() -> int:
    test_cases: List[Tuple[List[Optional[int]], int]] = [
        ([5, 4, 8, 11, None, 13, 4, 7, 2, None, None, 5, 1], 22),
        ([0, 1, 1], 1),
        ([10, 5, -3, 3, 2, None, 11, 3, -2, None, 1], 5),
    ]
    for node_data, target in test_cases:
        print("Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=node_data)
        path_sum: PathSum = PathSum(target=target)
        num_paths: int = path_sum.search(root)
        print(f"\nNumber of searched paths = {num_paths}\n")
    return 0


if __name__ == "__main__":
    main()
