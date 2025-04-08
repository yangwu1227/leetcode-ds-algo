from collections import deque
from sys import maxsize
from typing import List, Optional

from tree_node import NodeData, TreeNode


def largest_values(root: Optional[TreeNode]) -> List[NodeData]:
    """
    Find the largest data in each level of a binary tree using BFS.

    Parameters
    ----------
    root : Optional[TreeNode]
        Root node of the binary tree.

    Returns
    -------
    List[NodeData]
        List of maximum values for each level of the tree.
    """
    if not root:
        return []
    queue: deque[TreeNode] = deque([root])
    largest_data: List[NodeData] = []
    level: int = 1
    print(f"Initial state of the queue: {queue}")
    print(f"Initial state of the output array: {largest_data}")

    while queue:
        prefix: str = f"{level * ' '}Level {level} | "
        num_nodes_curr_level: int = len(queue)
        max_data_curr_level: int = -maxsize
        print(f"{prefix}Number of nodes = {num_nodes_curr_level}")
        print(f"{prefix}State of output array: {largest_data}")

        for i in range(num_nodes_curr_level):
            print(f"{prefix}State of queue: {queue}")
            curr_node: TreeNode = queue.popleft()
            print(f"{prefix}Dequeue and process {curr_node}")
            assert isinstance(curr_node.data, int)
            max_data_curr_level = max(curr_node.data, max_data_curr_level)
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
        largest_data.append(max_data_curr_level)

    return largest_data


def main() -> int:
    test_cases: List[List[Optional[int]]] = [
        [1, 3, 2, 5, 3, None, 9],
        [1, 2, 3],
        [],
        [1, None, 3, 9, 7, 12, None, 8, None, 17, None, None, 27, None, 4, 3, 6, 5, 2],
    ]
    for test_case in test_cases:
        print(f"Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=test_case)
        result: List[NodeData] = largest_values(root=root)
        print(f"Array containing largest data values at each level: {result}\n")

    return 0


if __name__ == "__main__":
    main()
