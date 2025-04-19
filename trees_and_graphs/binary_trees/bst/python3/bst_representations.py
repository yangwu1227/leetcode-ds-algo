from __future__ import annotations

from typing import Dict, List, Optional, Tuple

import matplotlib.pyplot as plt
import networkx as nx


class Node:
    """
    Node of a binary search tree.
    """

    def __init__(self, key: int) -> None:
        """
        Initialize a node with a key.

        Parameters
        ----------
        key : int
            The key of the node.
        left : Optional[Node], optional
            Left child of the node, by default None
        right : Optional[Node], optional
            Right child of the node, by default None
        """
        self.key: int = key
        self.left: Optional[Node] = None
        self.right: Optional[Node] = None


def insert(root: Optional[Node], key: int) -> Node:
    """
    Insert a key into the BST rooted at `root`.

    Parameters
    ----------
    root : Optional[Node]
        Root of the BST (None if tree is empty).
    key : int
        Key to insert.

    Returns
    -------
    Node
        The root of the BST after insertion.
    """
    if root is None:
        return Node(key)
    if key < root.key:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    return root


def build_tree(order: List[int]) -> Optional[Node]:
    """
    Build a BST by inserting keys in the given order.

    Parameters
    ----------
    order : List[int]
        Sequence of keys to insert.

    Returns
    -------
    Optional[Node]
        Root of the constructed BST.
    """
    root: Optional[Node] = None
    for k in order:
        root = insert(root, k)
    return root


def get_positions(root: Optional[Node]) -> Dict[Node, Tuple[int, int]]:
    """
    Compute 2D positions for each node via in-order traversal.

    Parameters
    ----------
    root : Optional[Node]
        Root of the BST.

    Returns
    -------
    Dict[Node, Tuple[int, int]]
        Mapping from node to (x, y) coordinates for plotting.
    """
    pos: Dict[Node, Tuple[int, int]] = {}
    counter = 0

    def assign(node: Optional[Node], depth: int = 0) -> None:
        nonlocal counter
        if node is None:
            return
        assign(node.left, depth + 1)
        pos[node] = (counter, -depth)
        counter += 1
        assign(node.right, depth + 1)

    assign(root)
    return pos


def get_edges(root: Optional[Node]) -> List[Tuple[Node, Node]]:
    """
    Collect all parent-child edges in the BST.

    Parameters
    ----------
    root : Optional[Node]
        Root of the BST.

    Returns
    -------
    List[Tuple[Node, Node]]
        List of (parent, child) tuples.
    """
    edges: List[Tuple[Node, Node]] = []

    def traverse(node: Optional[Node]) -> None:
        if node is None:
            return
        if node.left:
            edges.append((node, node.left))
            traverse(node.left)
        if node.right:
            edges.append((node, node.right))
            traverse(node.right)

    traverse(root)
    return edges


def main() -> int:
    keys = [5, 3, 7, 2, 4, 6, 8]
    balanced_order = [5, 3, 2, 4, 7, 6, 8]
    random_order = [2, 6, 7, 3, 5, 8, 4]
    worst_order = sorted(keys)

    trees: List[Tuple[str, List[int]]] = [
        ("Balanced BST", balanced_order),
        ("Random insertion", random_order),
        ("Worst-case BST (inorder insertion)", worst_order),
    ]

    _, axes = plt.subplots(1, 3, figsize=(15, 5))
    for ax, (title, order) in zip(axes, trees):
        tree = build_tree(order)
        pos = get_positions(tree)
        edges = get_edges(tree)
        G = nx.DiGraph()
        G.add_nodes_from(pos.keys())
        for parent, child in edges:
            G.add_edge(parent, child)
        labels = {node: node.key for node in pos}
        nx.draw(
            G,
            pos=pos,
            labels=labels,
            ax=ax,
            with_labels=True,
            node_size=1000,
            node_shape="o",
            node_color="white",
            edgecolors="black",
            linewidths=1,
            arrows=False,
        )
        ax.set_title(f"{title}\nInsertion order: {order}")
        ax.axis("off")

    plt.tight_layout()
    plt.show()

    return 0


if __name__ == "__main__":
    main()
