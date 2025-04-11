from collections import deque
from typing import List, Optional

from tree_node import NodeData, TreeNode


def right_side(root: Optional[TreeNode]) -> List[NodeData]:
    """
    Find the rightmost node's value at each level of a binary tree.

    Parameters
    ----------
    root : Optional[TreeNode]
        The root node of the binary tree.

    Returns
    -------
    List[NodeData]
        A list containing the values of the rightmost node at each level
        of the tree.
    """
    if not root:
        return []
    level: int = 1
    right_side_nodes: List[NodeData] = []
    queue: deque[TreeNode] = deque([root])
    print(f"Initial state of the queue: {queue}")
    print(f"Initial state of the output array: {right_side_nodes}")

    while queue:
        prefix: str = f"{level * ' '}Level {level} | "
        num_nodes_curr_level: int = len(queue)
        right_side_nodes.append(queue[-1].data)
        print(f"{prefix}Number of nodes = {num_nodes_curr_level}")
        print(f"{prefix}State of output array: {right_side_nodes}")

        for _ in range(num_nodes_curr_level):
            print(f"{prefix}State of queue: {queue}")
            curr_node: TreeNode = queue.popleft()
            print(f"{prefix}Dequeue and process {curr_node}")

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

    return right_side_nodes


def main() -> int:
    test_cases: List[List[Optional[int]]] = [
        [1, 2, 3, None, 5, None, 4],
        [1, 2, 3, 4, None, None, None, 5],
        [],
        [1, None, 3],
    ]
    for node_data in test_cases:
        print(f"Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=node_data)
        right_side_nodes: List[NodeData] = right_side(root=root)
        print(f"Output array: {right_side_nodes}\n")

    return 0


if __name__ == "__main__":
    main()
