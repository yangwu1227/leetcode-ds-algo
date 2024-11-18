from typing import Optional

from tree_node import TreeNode


def max_depth(root: Optional[TreeNode]) -> int:
    """
    Calculate the maximum depth of a binary tree.

    Parameters
    ----------
    root : Optional[TreeNode]
        The root node of the binary tree; if the tree is empty, `root` is None

    Returns
    -------
    int
        The maximum depth of the binary tree. Depth is defined as the number
        of nodes along the longest path from the root node down to the farthest leaf node.
    """
    if not root:
        return 0

    left_depth = max_depth(root.left)
    right_depth = max_depth(root.right)

    return max(left_depth, right_depth) + 1


def main() -> int:
    test_cases = [
        [3, 9, 20, None, None, 15, 7],
        [1, None, 2],
        [1, None, 2, 9, 10, 23, None, 8, 7, None, 12],
    ]
    for node_data in test_cases:
        root = TreeNode.construct_binary_tree(values=node_data)
        print(f"The max depth of the tree is {max_depth(root)}")

    return 0


if __name__ == "__main__":
    main()
