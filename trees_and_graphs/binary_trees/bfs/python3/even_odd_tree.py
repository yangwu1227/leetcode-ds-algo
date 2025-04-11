from collections import deque
from typing import Deque, List, Optional

from tree_node import TreeNode


def check_even_odd(root: Optional[TreeNode]) -> bool:
    """
    Check if a binary tree is an Even-Odd tree.

    Parameters
    ----------
    root : Optional[TreeNode]
        Root node of the binary tree.

    Returns
    -------
    bool
        `True` if the tree is an Even-Odd tree, `False` otherwise.
    """
    if not root:
        return False
    if not (root.left or root.right):
        assert isinstance(root.data, int)
        return root.data % 2 != 0

    queue: Deque[TreeNode] = deque([root])
    level: int = 0
    print(f"Initial state of the queue: {queue}")

    while queue:
        prefix: str = f"{level * ' '}Level {level} | "
        num_nodes_curr_level: int = len(queue)
        previous_data: Optional[int] = None
        is_even_level: bool = level % 2 == 0
        print(f"{prefix}Number of nodes = {num_nodes_curr_level}")

        for _ in range(num_nodes_curr_level):
            print(f"{prefix}State of queue: {queue}")
            curr_node: TreeNode = queue.popleft()
            print(f"{prefix}Dequeue and process {curr_node}")
            assert isinstance(curr_node.data, int)
            curr_data: int = curr_node.data

            if is_even_level == (curr_data % 2 == 0):
                return False

            if previous_data is not None:
                is_decreasing: bool = curr_data < previous_data
                is_increasing: bool = curr_data > previous_data
                if not ((is_even_level and is_increasing) or (not is_even_level and is_decreasing)):
                    return False
            if curr_node.left:
                queue.append(curr_node.left)
            if curr_node.right:
                queue.append(curr_node.right)
            previous_data = curr_data
        level += 1
    return True


def main() -> int:
    test_cases: List[List[Optional[int]]] = [
        [1, 10, 4, 3, None, 7, 9, 12, 8, 6, None, None, 2],
        [5, 4, 2, 3, 3, 7],
        [],
        [5],
        [5, 9, 1, 3, 5, 7],
    ]
    for node_data in test_cases:
        print(f"Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=node_data)
        is_even_odd: bool = check_even_odd(root=root)
        print(f"The binary tree is{' ' if is_even_odd else ' not '}an even odd tree\n")

    return 0


if __name__ == "__main__":
    main()
