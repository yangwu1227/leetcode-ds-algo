from collections import deque
from typing import List, Optional

from tree_node import NodeData, TreeNode


def level_order_traversal(root: Optional[TreeNode]) -> List[List[NodeData]]:
    """
    Perform a level-order traversal (breadth-first search) on a binary tree.

    Parameters
    ----------
    root : Optional[TreeNode]
        The root node of the binary tree.

    Returns
    -------
    List[List[NodeData]]
        A list of lists, where each inner list contains the data of nodes at the same level in the tree.
    """
    if not root:
        print(f"Empty tree")
        return []
    if not (root.left or root.right):
        print(f"Single node binary tree")
        return [[root.data]]

    queue: deque[TreeNode] = deque([root])
    output: List[List[NodeData]] = []
    level: int = 0
    print(f"Initial state of the queue: {queue}")
    print(f"Initial state of the output array: {output}")

    while queue:
        prefix: str = f"{level * ' '}Level {level} | "
        num_nodes_curr_level: int = len(queue)
        node_data: List[NodeData] = []
        print(f"{prefix}Number of nodes = {num_nodes_curr_level}")
        print(f"{prefix}Initial node data array: {node_data}")

        for _ in range(num_nodes_curr_level):
            print(f"{prefix}State of queue: {queue}")
            curr_node: TreeNode = queue.popleft()
            print(f"{prefix}Dequeue and process {curr_node}")
            node_data.append(curr_node.data)
            print(f"{prefix}Updated node data array: {node_data}")

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
        output.append(node_data)

    return output


def main() -> int:
    test_cases: List[List[Optional[int]]] = [
        [3, 9, 20, None, None, 15, 7],
        [6, 7, 8, 3, 9, None, 1, 4, None, None, None, 5],
        [],
        [1],
    ]
    for node_data in test_cases:
        print(f"Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=node_data)
        output: List[List[NodeData]] = level_order_traversal(root=root)
        print(f"The level order traversal output: {output}\n")

    return 0


if __name__ == "__main__":
    main()
