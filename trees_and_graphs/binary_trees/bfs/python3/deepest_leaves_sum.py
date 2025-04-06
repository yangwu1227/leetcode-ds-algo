from collections import deque
from typing import Deque, List, Optional

from tree_node import TreeNode


def deepest_leaves_sum(root: Optional[TreeNode]) -> int:
    """
    Given a binary tree, return the sum of values of its deepest leaves.

    Parameters
    ----------
    root : Optional[TreeNode]
        The root of the binary tree.

    Returns
    -------
    int
        The sum of values of the deepest leaves.
    """
    if not root:
        print(f"Empty tree")
        return 0
    if not (root.left or root.right):
        print(f"Single node binary tree")
        assert isinstance(root.data, int)
        return root.data

    queue: Deque[TreeNode] = deque([root])
    level: int = 1
    sum_curr_level: int = 0

    while queue:
        prefix: str = f"{level * ' '}Level {level} | "
        num_nodes_curr_level: int = len(queue)
        sum_curr_level = 0
        print(f"{prefix}Number of nodes = {num_nodes_curr_level}")

        for _ in range(num_nodes_curr_level):
            print(f"{prefix}State of queue: {queue}")
            curr_node: TreeNode = queue.popleft()
            print(f"{prefix}Dequeue and process {curr_node}")
            assert isinstance(curr_node.data, int)
            print(
                f"{prefix}{sum_curr_level} + {curr_node.data} = {sum_curr_level + curr_node.data}"
            )
            sum_curr_level += curr_node.data

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
        level += 1

    return sum_curr_level


def main() -> int:
    test_cases: List[List[Optional[int]]] = [
        [1, 2, 3, 4, 5, None, 6, 7, None, None, None, None, 8],
        [6, 7, 8, 2, 7, 1, 3, 9, None, 1, 4, None, None, None, 5],
        [],
        [3],
    ]
    for test_case in test_cases:
        print(f"Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=test_case)
        leaves_sum: int = deepest_leaves_sum(root=root)
        print(f"The leaves sum at the deepest leve of the tree is: {leaves_sum}\n")

    return 0


if __name__ == "__main__":
    main()
