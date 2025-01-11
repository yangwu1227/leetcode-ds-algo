from typing import List, Optional

from tree_node import TreeNode


def min_depth(root: Optional[TreeNode]) -> int:
    """
    Calculate the minimum depth of a binary tree. The minimum depth is the number
    of nodes along the shortest path from the root node down to the nearest leaf
    node. A leaf is a node with no children.

    Parameters
    ----------
    root : Optional[TreeNode]
        The root node of the binary tree. Can be None for an empty tree.

    Returns
    -------
    int
        The minimum depth of the binary tree. If the tree is empty, returns 0.
    """
    if not root:
        return 0
    if root.left is None:
        result_right: int = min_depth(root.right) + 1
        print(f"  Left node of {root} is None | Result for right subtree = {result_right}")
        return result_right
    elif root.right is None:
        result_left: int = min_depth(root.left) + 1
        print(f"  Right node of {root} is None | Result for left substree = {result_left}")
        return result_left
    result: int = min(min_depth(root.left), min_depth(root.right)) + 1
    print(f"  Neither node of {root} is None | Result = {result}")
    return result


def main() -> int:
    test_cases: List[List[int | None]] = [
        [3, 9, 20, None, None, 15, 7],
        [2, None, 3, None, 4, None, 5, None, 6],
        [1, None, None],
    ]
    for node_data in test_cases:
        print("Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(node_data)
        depth: int = min_depth(root)
        print(f"\nThe minimum depth of the binary tree is {depth}\n\n")
    return 0


if __name__ == "__main__":
    main()
