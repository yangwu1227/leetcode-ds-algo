from collections import deque
from typing import Deque, List, Optional

from tree_node import NodeData, TreeNode


def zig_zag(root: Optional[TreeNode]) -> List[Deque[NodeData]]:
    """
    Perform a zig-zag (spiral) level order traversal of a binary tree.

    In zig-zag traversal, the traversal alternates between left-to-right and
    right-to-left order at each level of the tree.

    Parameters
    ----------
    root : Optional[TreeNode]
        The root node of the binary tree.

    Returns
    -------
    List[Deque[NodeData]]
        A list where each element is a deque containing the node data for one level.
        The nodes at even-indexed levels are ordered left-to-right, while nodes at
        odd-indexed levels are ordered right-to-left.
    """
    if not root:
        return []

    if not (root.left or root.right):
        return [deque([root.data])]

    queue: Deque[TreeNode] = deque([root])
    output: List[Deque[NodeData]] = []
    level: int = 0
    print(f"Initial state of the queue: {queue}")
    print(f"Initial state of the output array: {output}")

    while queue:
        prefix: str = f"{level * ' '}Level {level} | "
        num_nodes_curr_level: int = len(queue)
        node_data: Deque[NodeData] = deque()
        print(f"{prefix}Number of nodes = {num_nodes_curr_level}")
        print(f"{prefix}State of output array: {output}")

        for _ in range(num_nodes_curr_level):
            print(f"{prefix}State of queue: {queue}")
            curr_node: TreeNode = queue.popleft()
            print(f"{prefix}Dequeue and process {curr_node}")

            if level % 2 == 0:
                print(f"{prefix}Level is even. Append {curr_node.data} to end of {node_data}")
                node_data.append(curr_node.data)
            else:
                print(f"{prefix}Level is odd. Append {curr_node.data} to front of {node_data}")
                node_data.appendleft(curr_node.data)

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
        [1, 2, 3, 4, None, None, 5],
        [],
        [3],
    ]
    for test_case in test_cases:
        print(f"Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=test_case)
        output: List[Deque[NodeData]] = zig_zag(root=root)
        print(f"The output array of zig zag traversal is {output}\n")

    return 0


if __name__ == "__main__":
    main()
