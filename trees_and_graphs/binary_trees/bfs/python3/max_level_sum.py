from collections import deque
from sys import maxsize
from typing import Deque, List, Optional

from tree_node import TreeNode


def max_level_sum(root: Optional[TreeNode]) -> int:
    """
    Find the smallest level in a binary tree with the maximum sum of node values.

    Parameters
    ----------
    root : Optional[TreeNode]
        The root node of the binary tree.

    Returns
    -------
    int
        The smallest level (1-indexed) with the maximum sum of node values.
    """
    if not root:
        print(f"Empty tree")
        return 0
    if not (root.left or root.right):
        print(f"Single node binary tree")
        return 1

    queue: Deque[TreeNode] = deque([root])
    max_sum: int = -maxsize
    max_level: int = 1
    level: int = 1
    print(f"Initial state of the queue: {queue}")
    print(f"Initial max sum = {max_sum} | max level = {max_sum}")

    while queue:
        prefix: str = f"{level * ' '}Level {level} | "
        num_nodes_curr_level: int = len(queue)
        running_level_sum: int = 0
        print(f"{prefix}Number of nodes = {num_nodes_curr_level}")
        print(f"{prefix}Initial level running sum = {running_level_sum}")

        for _ in range(num_nodes_curr_level):
            print(f"{prefix}State of queue: {queue}")
            curr_node: TreeNode = queue.popleft()
            print(f"{prefix}Dequeue and process {curr_node}")
            assert isinstance(curr_node.data, int)
            print(
                f"{prefix}Running sum = {running_level_sum} + {curr_node.data} = {running_level_sum + curr_node.data}"
            )
            running_level_sum += curr_node.data

            if curr_node.left:
                print(f"{prefix}Enque left child of {curr_node}: {curr_node.left}")
                queue.append(curr_node.left)
            else:
                print(f"{prefix}Left child of {curr_node} is empty")
            if curr_node.right:
                print(f"{prefix}Enque right child of {curr_node}: {curr_node.right}")
                queue.append(curr_node.right)
            else:
                print(f"{prefix}Right child of {curr_node} is empty")

        found_larger_max: bool = running_level_sum > max_sum
        print(
            f"{prefix}Level sum ({running_level_sum}) {'>' if found_larger_max else '<'} Max sum ({max_sum})"
        )
        print(
            f"{prefix}{f'Update max level to {level}' if found_larger_max else f'Keep max level to {max_level}'}"
        )
        max_level = level if running_level_sum > max_sum else max_level
        print(
            f"{prefix}Max sum = Max(Level sum ({running_level_sum}), Max sum ({max_sum})) = {max(max_sum, running_level_sum)}"
        )
        max_sum = max(max_sum, running_level_sum)
        level += 1

    return max_level


def main() -> int:
    test_cases: List[List[Optional[int]]] = [
        [1, 7, 0, 7, -8, None, None],
        [989, None, 10250, 98693, -89388, None, None, None, -32127],
        [8],
        [],
        [1, 7, 0, 7, -8, None, None, 23, 17, None, 8, 12, 77, 53],
    ]
    for node_data in test_cases:
        print(f"Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=node_data)
        max_level: int = max_level_sum(root=root)
        print(f"The smallest level with the maximal sum is {max_level}\n")

    return 0


if __name__ == "__main__":
    main()
