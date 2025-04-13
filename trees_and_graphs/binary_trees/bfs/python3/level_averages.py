from array import ArrayType, array
from collections import deque
from typing import Deque, List, Optional

from tree_node import TreeNode


def compute_level_averages(root: Optional[TreeNode]) -> ArrayType[float]:
    """
    Compute the average value of nodes at each level of a binary tree.

    Parameters
    ----------
    root : Optional[TreeNode]
        The root node of the binary tree.

    Returns
    -------
    ArrayType[float]
        An array of C doubles (8 bytes) where each element is the average
        of node values at the corresponding level in the tree.
    """
    if not root:
        return array("d")
    if not (root.left or root.right):
        assert isinstance(root.data, (int, float))
        return array("d", [float(root.data)])

    queue: Deque[TreeNode] = deque([root])
    output: ArrayType[float] = array("d")
    level: int = 0
    print(f"Initial state of the queue: {queue}")

    while queue:
        prefix: str = f"{level * ' '}Level {level} | "
        num_nodes_curr_level: int = len(queue)
        running_level_sum: float = 0
        print(f"{prefix}Number of nodes = {num_nodes_curr_level}")
        print(f"{prefix}Initial running sum = {running_level_sum}")

        for _ in range(num_nodes_curr_level):
            print(f"{prefix}State of queue: {queue}")
            curr_node: TreeNode = queue.popleft()
            print(f"{prefix}Dequeue and process {curr_node}")
            assert isinstance(curr_node.data, (int, float))
            print(
                f"{prefix}Running sum = {running_level_sum} + {curr_node.data} = {running_level_sum + curr_node.data}"
            )
            running_level_sum += curr_node.data

            if curr_node.left:
                queue.append(curr_node.left)
            if curr_node.right:
                queue.append(curr_node.right)
        level += 1
        output.append(running_level_sum / num_nodes_curr_level)

    return output


def main() -> int:
    test_cases: List[List[Optional[int]]] = [
        [3, 9, 20, None, None, 15, 7],
        [3, 9, 20, 15, 7],
        [],
        [2147483647, 2147483647, 2147483647],
    ]
    for node_data in test_cases:
        print(f"Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=node_data)
        output: ArrayType[float] = compute_level_averages(root=root)
        print(f"The array of level averages is: {output if output else []}\n")

    return 0


if __name__ == "__main__":
    main()
