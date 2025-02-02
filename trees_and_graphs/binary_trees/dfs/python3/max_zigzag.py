from typing import Dict, List, Optional

from tree_node import TreeNode


class ZigZag(object):
    """
    A class that finds the longest zig zag path of a binary tree.
    """

    def __init__(self) -> None:
        """
        Initialize the ZigZag instance.
        """
        self._max_len: int = 0

    def depth_first_search(self, node: Optional[TreeNode], depth: int) -> Dict[str, int]:
        """
        Perform a depth-first search to calculate the maximum ZigZag path length rooted at
        the current `node`.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node in the binary tree.
        depth : int
            The depth of the current node in the tree.

        Returns
        -------
        Dict[str, int]
            A dictionary containing the lengths of paths when turning left and right:
            `{"turn_left": int, "turn_right": int}`
        """
        print_prefix: str = f"{'  ' * depth}Depth {depth} | "
        if not node:
            print(f"{print_prefix}Empty Node, return {{'turn_left': -1, 'turn_right': -1}}")
            return {"turn_left": -1, "turn_right": -1}

        print(f"{print_prefix}Visiting left child at depth = {depth}")
        left_results: Dict[str, int] = self.depth_first_search(node.left, depth + 1)
        print(f"{print_prefix}Visiting right child at depth = {depth}")
        right_results: Dict[str, int] = self.depth_first_search(node.right, depth + 1)

        prefix_1: str = f"{print_prefix}Longest path starting from the "
        prefix_2: str = "Longest path in the children nodes if we turn "
        print(f"{prefix_1}left = {prefix_2}right + 1 = {left_results['turn_right'] + 1}")
        print(f"{prefix_1}right = {prefix_2}left + 1 = {right_results['turn_left'] + 1}")
        left_len: int = left_results["turn_right"] + 1
        right_len: int = right_results["turn_left"] + 1

        print(f"{print_prefix}Previous ({self._max_len}), Left ({left_len}), Right ({right_len})]")
        print(f"{print_prefix}New max length = {max(self._max_len, left_len, right_len)}")
        self._max_len = max(self._max_len, left_len, right_len)

        return {"turn_left": left_len, "turn_right": right_len}

    def find_max(self, root: Optional[TreeNode]) -> int:
        """
        Find the maximum length of a ZigZag path in the binary tree.

        Parameters
        ----------
        root : Optional[TreeNode]
            The root node of the binary tree.

        Returns
        -------
        int
            The length of the longest ZigZag path in the tree.
        """
        if not root:
            return 0
        _: Dict[str, int] = self.depth_first_search(root, 0)
        return self._max_len


def main() -> int:
    test_cases: List[List[Optional[int]]] = [
        [1, None, 1, 1, 1, None, None, 1, 1, None, 1, None, None, None, 1],
        [1, 1, 1, None, 1, None, None, 1, 1, None, 1],
        [1],
    ]

    for node_data in test_cases:
        print("Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=node_data)
        zig_zag: ZigZag = ZigZag()
        max_len: int = zig_zag.find_max(root)
        print(f"\nThe maximum length among all zigzag paths is {max_len}\n\n")

    return 0


if __name__ == "__main__":
    main()
