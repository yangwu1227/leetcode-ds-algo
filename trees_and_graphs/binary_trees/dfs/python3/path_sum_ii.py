from typing import List, Optional, Tuple

from tree_node import TreeNode


class PathSum(object):
    """
    Class to find all paths in a binary tree where the sum of node values equals a target sum.

    Attributes
    ----------
    target : int
        The target sum to match.
    _paths : List[Optional[List[int]]]
        List to store all valid paths.
    _curr_path : List[int]
        List to track the current path during depth-first search.
    _curr_sum : int
        Variable to store the running sum during traversal.
    """

    def __init__(self, target: int) -> None:
        """
        Initializes the PathSum instance with a target sum.

        Parameters
        ----------
        target : int
            The target sum to match.
        """
        self._paths: List[Optional[List[int]]] = []
        self._curr_path: List[int] = []
        self._curr_sum: int = 0
        self.target: int = target

    def depth_first_search(self, node: Optional[TreeNode], depth: int) -> None:
        """
        Performs a depth-first search to find paths that sum to the target.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node in the binary tree.
        depth : int
            The current depth in the binary tree for printing purposes.

        Returns
        -------
        None
        """
        print_prefix: str = f"{'  ' * depth}Depth {depth} | "
        if not node:
            print(f"{print_prefix}Empty Node")
            return None
        assert isinstance(node.data, int), "Expected node.data to be an int"
        sum_equation: str = (
            f"Current Sum {self._curr_sum} + Node Data {node.data} = {self._curr_sum + node.data}"
        )

        print(f"{print_prefix}{sum_equation}")
        self._curr_sum += node.data
        print(f"{print_prefix}Current Path {self._curr_path} -> {self._curr_path + [node.data]}")
        self._curr_path.append(node.data)

        print(
            f"{print_prefix}{sum_equation} == {self.target}? {'Yes' if self._curr_sum == self.target else 'No'}"
        )
        if node.left is None and node.right is None and self._curr_sum == self.target:
            print(f"{print_prefix}Add to Paths {self._paths + [self._curr_path + [node.data]]}")
            self._paths.append(self._curr_path[:])  # Shallow copy

        if node.left:
            self.depth_first_search(node.left, depth + 1)
        if node.right:
            self.depth_first_search(node.right, depth + 1)

        print(
            f"{print_prefix}Backtrace | Current Sum {self._curr_sum} - Node Data {node.data} = {self._curr_sum - node.data}"
        )
        self._curr_sum -= node.data
        print(f"{print_prefix}Current Path {self._curr_path} -> {self._curr_path[:-1]}")
        self._curr_path.pop(-1)

        return None

    def search(self, root: Optional[TreeNode]) -> List[Optional[List[int]]]:
        """
        Finds all paths in the binary tree where the sum of node values equals the target sum.

        Parameters
        ----------
        root : Optional[TreeNode]
            The root node of the binary tree.

        Returns
        -------
        List[Optional[List[int]]]
            A list of all valid paths, where each path is represented as a list of integers.
        """
        if not root:
            return self._paths
        self.depth_first_search(root, 0)
        return self._paths


def main() -> int:
    test_cases: List[Tuple[List[Optional[int]], int]] = [
        ([5, 4, 8, 11, None, 13, 4, 7, 2, None, None, 5, 1], 22),
        ([1, 2, 3], 5),
        ([1, 2, 2, 2, 2, 2, 2], 5),
        ([], 0),
    ]
    for node_data, target in test_cases:
        print("Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=node_data)
        path_sum: PathSum = PathSum(target=target)
        paths: List[Optional[List[int]]] = path_sum.search(root)
        print(f"\nSearched paths = {paths}\n")
    return 0


if __name__ == "__main__":
    main()
