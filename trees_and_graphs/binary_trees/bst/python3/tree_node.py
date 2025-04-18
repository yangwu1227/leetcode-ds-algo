from __future__ import annotations

from collections import deque
from typing import MutableMapping, Optional, Sequence, Tuple, TypeAlias, Union

import matplotlib.pyplot as plt
import networkx as nx

NodeData: TypeAlias = Optional[Union[int, float]]


class TreeNode(object):
    """
    This class represents a node in a binary tree.
    """

    def __init__(
        self,
        data: NodeData = None,
        left: Optional[TreeNode] = None,
        right: Optional[TreeNode] = None,
    ) -> None:
        """
        Initializes the tree node instance.

        Parameters
        ----------
        data : NodeData
            The data value stored in this node, by default None
        left : Optional[TreeNode], optional
            The left child node, by default None
        right : Optional[TreeNode], optional
            The right child node, by default None
        """
        self.data = data
        self.left = left
        self.right = right

    def __repr__(self) -> str:
        """
        Return a string representation of the TreeNode instance.

        Returns
        -------
        str
            A string in the format `TreeNode(data = <data>)`
        """
        return f"TreeNode(data = {self.data})"

    @staticmethod
    def construct_binary_tree(
        values: Sequence[NodeData],
    ) -> Optional[TreeNode]:
        """
        Constructs a binary tree from a list of values representing level-order traversal.

        Parameters
        ----------
        values : Sequence[NodeData]
            A list where each element represents a node's data in level-order;
            `None` represents a missing node

        Returns
        -------
        Optional[TreeNode]
            The root of the constructed binary tree
        """
        if not values or values[0] is None:
            return None

        root = TreeNode(values[0])
        # Queue to hold nodes at each level
        queue = deque([root])
        # Start from the second element in `values`
        index = 1
        while index < len(values):
            current_node = queue.popleft()

            # Add the left child
            if values[index] is not None:
                current_node.left = TreeNode(values[index])
                queue.append(current_node.left)
            index += 1

            # Ensure we don’t go out of bounds before adding the right child
            if index < len(values) and values[index] is not None:
                current_node.right = TreeNode(values[index])
                queue.append(current_node.right)
            index += 1

        return root

    @staticmethod
    def visualize_binary_tree(root: TreeNode) -> None:
        """
        Visualizes a binary tree using matplotlib and networkx.

        Parameters
        ----------
        root : TreeNode
            The root node of the binary tree
        """

        def add_edges(
            graph: nx.DiGraph,
            node: TreeNode,
            pos: MutableMapping[TreeNode, Tuple[float, float]],
            x: float = 0,
            y: float = 0,
            layer: int = 1,
            dx: float = 1.5,
        ) -> None:
            if not node:
                return
            pos[node] = (x, y)
            if node.left:
                graph.add_edge(node, node.left)
                add_edges(graph, node.left, pos, x - dx / layer, y - 1, layer + 1, dx)
            if node.right:
                graph.add_edge(node, node.right)
                add_edges(graph, node.right, pos, x + dx / layer, y - 1, layer + 1, dx)

        graph = nx.DiGraph()
        pos: MutableMapping[TreeNode, Tuple[float, float]] = {}
        add_edges(graph, root, pos)

        plt.figure(figsize=(10, 8))
        nx.draw(
            graph,
            pos,
            with_labels=False,
            node_size=800,
            node_color="skyblue",
            edge_color="gray",
            font_size=10,
        )
        nx.draw_networkx_labels(graph, pos, labels={node: str(node.data) for node in pos})
        plt.title("Binary Tree Visualization")
        plt.axis("off")
        plt.show()
