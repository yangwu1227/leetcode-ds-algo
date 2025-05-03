from collections import deque
from typing import Deque, List, MutableMapping, Optional, Tuple

import matplotlib.pyplot as plt
import networkx as nx
from tree_node import NodeData, TreeNode


class BinarySearchTree(object):
    """
    Implementation of a Binary Search Tree data structure.
    """

    def __init__(self) -> None:
        """
        Initialize an empty binary search tree.
        """
        self.root: Optional[TreeNode] = None
        self._size: int = 0

    def __len__(self) -> int:
        """
        Return the number of nodes in the tree.

        Returns
        -------
        int
            The number of nodes in the tree.
        """
        return self._size

    def is_empty(self) -> bool:
        """
        Check if the tree is empty.

        Returns
        -------
        bool
            True if the tree is empty, False otherwise.
        """
        return self.root is None

    def _validate_data(self, data: NodeData) -> NodeData:
        """
        Validate that data is either an `int` or `float` and
        return the validated data.

        Parameters
        ----------
        data : NodeData
            The data to validate.

        Returns
        -------
        NodeData
            The validated data.

        Raises
        ------
        ValueError
            If the data is not an integer or float.
        """
        if not isinstance(data, (int, float)):
            raise ValueError("Node data must either be integer or float")
        return data

    def insert(self, data: NodeData) -> None:
        """
        Insert a new node with the given data into the binary search tree.

        Parameters
        ----------
        data : NodeData
            The data to insert into the tree.
        """
        validated_data = self._validate_data(data)

        if self.is_empty():
            self.root = TreeNode(validated_data)
            self._size = 1
            return None

        self.root = self._insert_recursive(self.root, validated_data)

    def _insert_recursive(self, node: Optional[TreeNode], data: NodeData) -> TreeNode:
        """
        Recursively insert data into the proper position in the binary search tree.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node being examined.
        data : NodeData
            The data to insert.

        Returns
        -------
        TreeNode
            The root of the updated subtree.
        """
        # Base case: we've reached a leaf node
        if node is None:
            self._size += 1
            return TreeNode(data)

        validated_node_data = self._validate_data(node.data)

        # Recursive cases
        if data < node.data:
            node.left = self._insert_recursive(node.left, data)
        elif data > node.data:
            node.right = self._insert_recursive(node.right, data)
        else:
            # Simple replace strategy for duplicate data
            node.data = data

        return node

    def search(self, data: NodeData) -> Optional[TreeNode]:
        """
        Search for a node with the given data in the binary search tree.

        Parameters
        ----------
        data : NodeData
            The data to search for.

        Returns
        -------
        Optional[TreeNode]
            The node containing the data, or `None` if not found.
        """
        if data is None:
            return None
        return self._search_recursive(self.root, data)

    def _search_recursive(
        self, node: Optional[TreeNode], data_to_search: NodeData
    ) -> Optional[TreeNode]:
        """
        Recursively search for a node with the given data.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node being examined.
        data_to_search : NodeData
            The data to search for.

        Returns
        -------
        Optional[TreeNode]
            The node containing the data, or `None` if not found.
        """
        # Base case: search miss (None) or search hit
        if node is None or node.data == data_to_search:
            return node

        # Recursive cases
        if data_to_search < node.data:
            return self._search_recursive(node.left, data_to_search)
        elif data_to_search > node.data:
            return self._search_recursive(node.right, data_to_search)

        return None

    def contains(self, data: NodeData) -> bool:
        """
        Check if the binary search tree contains a node with the given data.

        Parameters
        ----------
        data : NodeData
            The data to check for.

        Returns
        -------
        bool
            True if the tree contains the data, False otherwise.
        """
        validated_data = self._validate_data(data)
        return self.search(validated_data) is not None

    def _find_min_data(self, node: TreeNode) -> NodeData:
        """
        Find the minimum data value in the subtree rooted at node.

        Parameters
        ----------
        node : TreeNode
            The root of the subtree.

        Returns
        -------
        NodeData
            The minimum data value in the subtree.
        """
        curr_node = node
        # Keep going left to find the minimum data
        while curr_node.left is not None:
            curr_node = curr_node.left
        return curr_node.data

    def delete(self, data_to_delete: NodeData) -> bool:
        """
        Delete a node with the given data from the binary search tree. This
        implementation uses Hibbard deletion.

        Parameters
        ----------
        data_to_delete : NodeData
            The data to delete from the tree.

        Returns
        -------
        bool
            `True` if a node was deleted, `False` otherwise.
        """
        # If data to be deleted or tree is empty, return False
        if data_to_delete is None or self.is_empty():
            return False

        self.root, deleted = self._delete_recursive(self.root, data_to_delete)
        return deleted

    def _delete_recursive(
        self, node: Optional[TreeNode], data_to_delete: NodeData
    ) -> Tuple[Optional[TreeNode], bool]:
        """
        Recursively delete a node with the given data.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node being examined.
        data_to_delete : NodeData
            The data to delete.

        Returns
        -------
        Tuple[Optional[TreeNode], bool]
            The root of the updated subtree and a boolean indicating whether
            a deletion occurred.
        """
        # Base case, return None if this is a leaf
        if node is None:
            return None, False

        deleted: bool = False

        if data_to_delete < node.data:
            node.left, deleted = self._delete_recursive(node.left, data_to_delete)
        elif data_to_delete > node.data:
            node.right, deleted = self._delete_recursive(node.right, data_to_delete)
        # This branch runs when node to delete is found, i.e., data_to_delete == node.data
        else:
            # Case I: leaf node with no children
            if node.left is None and node.right is None:
                self._size -= 1
                return None, True

            # Case II: only one child
            elif node.left is None:
                self._size -= 1
                return node.right, True
            elif node.right is None:
                self._size -= 1
                return node.left, True

            # Case III: two children
            # Find the inorder successor (smallest data in the rigth subtree of the matched node)
            successor_data: NodeData = self._find_min_data(node.right)
            node.data = successor_data

            # Delete the inorder successor
            node.right, _ = self._delete_recursive(node.right, successor_data)
            deleted = True

        return node, deleted

    def find_min_node(self) -> Optional[TreeNode]:
        """
        Find the node with the minimum data in the binary search tree.

        Returns
        -------
        Optional[TreeNode]
            The node with the minimum data, or `None` if the tree is empty.
        """
        if self.is_empty():
            return None

        assert self.root
        curr_node = self.root
        while curr_node.left is not None:
            curr_node = curr_node.left

        return curr_node

    def find_max_node(self) -> Optional[TreeNode]:
        """
        Find the node with the maximum data in the binary search tree.

        Returns
        -------
        Optional[TreeNode]
            The node with the maximum data, or `None` if the tree is empty.
        """
        if self.is_empty():
            return None

        assert self.root
        curr_node = self.root
        while curr_node.right is not None:
            curr_node = curr_node.right

        return curr_node

    def floor(self, target: NodeData) -> Optional[NodeData]:
        """
        Find the largest key in the binary search tree less than or equal to the given target.

        Parameters
        ----------
        target : NodeData
            The data to find the floor of.

        Returns
        -------
        Optional[NodeData]
            The floor of the given data, or `None` if no such data exists.
        """
        if target is None or self.is_empty():
            return None

        floor_node = self._floor_recursive(self.root, target)
        return floor_node.data if floor_node else None

    def _floor_recursive(self, node: Optional[TreeNode], target: NodeData) -> Optional[TreeNode]:
        """
        Recursively find the floor of a data in the binary search tree.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node being examined.
        target : NodeData
            The data to find the floor of.

        Returns
        -------
        Optional[TreeNode]
            The node containing the floor of the given target, or `None` if no such target exists.
        """
        if node is None:
            return None

        # If current node's data equals the target, we found the floor
        if node.data == target:
            return node

        # If target is less than current node's data, floor must be in left subtree
        if target < node.data:
            return self._floor_recursive(node.left, target)

        # Otherwise, floor could be in right subtree or current node
        # If there is a data >= target in right subtree, that's the floor
        # Otherwise current node is the floor
        right_floor = self._floor_recursive(node.right, target)
        return right_floor if right_floor else node

    def ceiling(self, target: NodeData) -> Optional[NodeData]:
        """
        Find the smallest key in the binary search tree greater than or equal to the given target.

        Parameters
        ----------
        target : NodeData
            The target to find the ceiling of.

        Returns
        -------
        Optional[NodeData]
            The ceiling of the given target, or `None` if no such target exists
        """
        if target is None or self.is_empty():
            return None

        ceiling_node = self._ceiling_recursive(self.root, target)
        return ceiling_node.data if ceiling_node else None

    def _ceiling_recursive(self, node: Optional[TreeNode], target: NodeData) -> Optional[TreeNode]:
        """
        Recursively find the ceiling of a target in the binary search tree.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node being examined.
        target : NodeData
            The target to find the ceiling of.

        Returns
        -------
        Optional[TreeNode]
            The node containing the ceiling of the given target, or `None` if no such target exists.
        """
        if node is None:
            return None

        # If current node's data equals the target, we found the ceiling
        if node.data == target:
            return node

        # If target is greater than current node's data, ceiling must be in right subtree
        if target > node.data:
            return self._ceiling_recursive(node.right, target)

        # Otherwise, ceiling could be in left subtree or current node
        # If there is a data <= target in left subtree, that's the ceiling
        # Otherwise current node is the ceiling
        left_ceiling = self._ceiling_recursive(node.left, target)
        return left_ceiling if left_ceiling else node

    def rank(self, data: NodeData) -> int:
        """
        Return the number of keys in the binary search tree that are less than the given data.

        Parameters
        ----------
        data : NodeData
            The data to find the rank of.

        Returns
        -------
        int
            The number of keys less than the given data.
        """
        if data is None:
            return 0

        return self._rank_recursive(self.root, data)

    def _rank_recursive(self, node: Optional[TreeNode], data: NodeData) -> int:
        """
        Recursively calculate the rank of a data.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node being examined.
        data : NodeData
            The data to find the rank of.

        Returns
        -------
        int
            The number of keys less than the given data in the subtree rooted at node.
        """
        if node is None:
            return 0

        # If data is less than the current node's data, then explore left subtree
        if data < node.data:
            return self._rank_recursive(node.left, data)
        # If data is larger than current node's data, we count this node in the rank
        elif data > node.data:
            # Count the left subtree size + the current node + rank in right subtree
            left_size = self._size_recursive(node.left)
            return 1 + left_size + self._rank_recursive(node.right, data)
        # This handles the case when data == node.data
        else:
            # Count just the left subtree size
            return self._size_recursive(node.left)

    def _size_recursive(self, node: Optional[TreeNode]) -> int:
        """
        Recursively calculate the size of a subtree.

        Parameters
        ----------
        node : Optional[TreeNode]
            The root of the subtree.

        Returns
        -------
        int
            The number of nodes in the subtree.
        """
        if node is None:
            return 0

        return 1 + self._size_recursive(node.left) + self._size_recursive(node.right)

    def select(self, k: int) -> Optional[NodeData]:
        """
        Find the node of rank `k` in the binary search tree (i.e., the kth smallest key).

        Parameters
        ----------
        k : int
            The rank of the node to find.

        Returns
        -------
        Optional[NodeData]
            The node of rank `k`, or None if `k` is out of bounds.
        """
        if k < 0 or k >= len(self):
            return None

        select_node = self._select_recursive(self.root, k)
        return select_node.data if select_node else None

    def _select_recursive(self, node: Optional[TreeNode], k: int) -> Optional[TreeNode]:
        """
        Recursively find the node of rank `k`.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node being examined.
        k : int
            The rank of the key to find.

        Returns
        -------
        Optional[TreeNode]
            The node containing the key of rank `k`, or None if `k` is out of bounds.
        """
        if node is None:
            return None

        left_size = self._size_recursive(node.left)

        if k < left_size:
            return self._select_recursive(node.left, k)
        elif k > left_size:
            return self._select_recursive(node.right, k - left_size - 1)
        # Handles the case when k == left_size
        else:
            return node

    def is_valid_bst(self) -> bool:
        """
        Check if the tree satisfies the binary search tree property.

        Returns
        -------
        bool
            True if the tree is a valid binary search tree, False otherwise
        """
        return self._is_valid_bst_recursive(self.root, float("-inf"), float("inf"))

    def _is_valid_bst_recursive(
        self, node: Optional[TreeNode], min_value: float, max_value: float
    ) -> bool:
        """
        Recursively validate the binary search tree property.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node being examined.
        min_value : float
            The minimum allowed data for this subtree.
        max_value : float
            The maximum allowed data for this subtree.

        Returns
        -------
        bool
            `True` if the subtree is a valid binary search tree, `False` otherwise.
        """
        if node is None:
            return True

        assert node.data
        # Check if current node's data is within valid range, starting with [-inf, inf]
        if node.data <= min_value or node.data >= max_value:
            return False

        # All left substree nodes must be less than the current node, so max value becomes the current node's data
        valid_left: bool = self._is_valid_bst_recursive(node.left, min_value, node.data)
        # All right substree nodes must be greater than the current node, so min value becomes the current node's data
        valid_right: bool = self._is_valid_bst_recursive(node.right, node.data, max_value)
        return valid_left and valid_right

    def height(self) -> int:
        """
        Calculate the height of the tree.

        Returns
        -------
        int
            The height of the tree, -1 if the tree is empty.
        """
        return self._height_recursive(self.root)

    def _height_recursive(self, node: Optional[TreeNode]) -> int:
        """
        Recursively calculate the height of a subtree.

        Parameters
        ----------
        node : Optional[TreeNode]
            The root of the subtree.

        Returns
        -------
        int
            The height of the subtree, `-1` if the subtree is empty.
        """
        if node is None:
            return -1

        left_height = self._height_recursive(node.left)
        right_height = self._height_recursive(node.right)

        return max(left_height, right_height) + 1

    def inorder_traversal(self) -> List[NodeData]:
        """
        Perform an inorder traversal of the binary search tree.

        Returns
        -------
        List[NodeData]
            The datas in the tree in ascending order.
        """
        result: List[NodeData] = []
        self._inorder_recursive(self.root, result)
        return result

    def _inorder_recursive(self, node: Optional[TreeNode], result: List[NodeData]) -> None:
        """
        Recursively perform an inorder traversal.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node being examined.
        result : List[NodeData]
            The list to append datas to.

        Returns
        -------
        None
        """
        if node is not None:
            self._inorder_recursive(node.left, result)
            result.append(node.data)
            self._inorder_recursive(node.right, result)

    def preorder_traversal(self) -> List[NodeData]:
        """
        Perform a preorder traversal of the binary search tree.

        Returns
        -------
        List[NodeData]
            The datas in preorder traversal order.
        """
        result: List[NodeData] = []
        self._preorder_recursive(self.root, result)
        return result

    def _preorder_recursive(self, node: Optional[TreeNode], result: List[NodeData]) -> None:
        """
        Recursively perform a preorder traversal.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node being examined.
        result : List[NodeData]
            The list to append datas to.
        """
        if node is not None:
            result.append(node.data)
            self._preorder_recursive(node.left, result)
            self._preorder_recursive(node.right, result)

    def postorder_traversal(self) -> List[NodeData]:
        """
        Perform a postorder traversal of the binary search tree.

        Returns
        -------
        List[NodeData]
            The datas in postorder traversal order
        """
        result: List[NodeData] = []
        self._postorder_recursive(self.root, result)
        return result

    def _postorder_recursive(self, node: Optional[TreeNode], result: List[NodeData]) -> None:
        """
        Recursively perform a postorder traversal.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node being examined.
        result : List[NodeData]
            The list to append datas to.

        Returns
        -------
        None
        """
        if node is not None:
            self._postorder_recursive(node.left, result)
            self._postorder_recursive(node.right, result)
            result.append(node.data)

    def level_order_traversal(self) -> List[NodeData]:
        """
        Perform a level order (breadth-first) traversal of the binary search tree.

        Returns
        -------
        List[NodeData]
            The datas in level order traversal.
        """
        result: List[NodeData] = []
        if self.is_empty():
            return result

        assert self.root
        queue: Deque[TreeNode] = deque([self.root])

        while queue:
            node = queue.popleft()
            result.append(node.data)

            if node.left is not None:
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)

        return result

    def visualize(self) -> None:
        """
        Visualize the binary search tree using matplotlib and networkx.
        """
        if self.is_empty():
            print("Tree is empty, nothing to visualize")
            return

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
        assert self.root
        add_edges(graph, self.root, pos)

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
        plt.title("Binary Search Tree Visualization")
        plt.axis("off")
        plt.show()


def main() -> int:
    bst = BinarySearchTree()
    print("=== Initialization ===\n")
    print(f"Is empty: {bst.is_empty()}")
    print(f"Size: {len(bst)}")
    print(f"Height: {bst.height()}")
    print()

    print("=== Insertion ===\n")
    values = [50, 30, 70, 20, 40, 60, 80]
    print(f"Inserting values: {values}")
    for val in values:
        bst.insert(val)
    print(f"After insertion:")
    print(f"Is empty: {bst.is_empty()}")
    print(f"Size: {len(bst)}")
    print(f"Height: {bst.height()}")
    print()

    print("=== Traversals ===\n")
    print(f"Inorder traversal: {bst.inorder_traversal()}")
    print(f"Preorder traversal: {bst.preorder_traversal()}")
    print(f"Postorder traversal: {bst.postorder_traversal()}")
    print(f"Level order traversal: {bst.level_order_traversal()}")
    print()

    print("=== Search ===\n")
    value_to_search = 40
    print(f"Searching for {value_to_search}")
    node = bst.search(value_to_search)
    print(f"Found: {node is not None}")
    print(f"Contains {value_to_search}: {bst.contains(value_to_search)}")

    value_to_search = 45
    print(f"Searching for {value_to_search}")
    node = bst.search(value_to_search)
    print(f"Found: {node is not None}")
    print(f"Contains {value_to_search}: {bst.contains(value_to_search)}")
    print()

    print("=== Min & Maxs ===")
    min_node = bst.find_min_node()
    max_node = bst.find_max_node()
    print(f"Minimum value: {min_node.data if min_node else None}")
    print(f"Maximum value: {max_node.data if max_node else None}")
    print()

    print("=== Floor & Ceiling ===\n")
    test_values = [25, 30, 45, 90]
    for val in test_values:
        print(f"Floor of {val}: {bst.floor(val)}")
        print(f"Ceiling of {val}: {bst.ceiling(val)}")
    print()

    print("=== Rank & Select ===\n")
    for val in [20, 50, 80]:
        print(f"Rank of {val}: {bst.rank(val)}")

    print("\nSelect tests:")
    for k in range(len(bst)):
        print(f"Select {k}: {bst.select(k)}")
    print()

    print("=== Structure ===\n")
    print(f"Is valid BST: {bst.is_valid_bst()}")
    print()

    print("=== Deletion ===\n")
    values_to_delete = [20, 30, 50]  # Leaf, one child, root

    for val in values_to_delete:
        print(f"Before deleting {val}:")
        print(f"Size: {len(bst)}")
        print(f"Inorder traversal: {bst.inorder_traversal()}")

        deleted = bst.delete(val)

        print(f"Deleted {val}: {deleted}")
        print(f"After deleting {val}:")
        print(f"Size: {len(bst)}")
        print(f"Inorder traversal: {bst.inorder_traversal()}")
        print(f"Is valid BST: {bst.is_valid_bst()}")
        print()

    print("=== Duplicate Data ===\n")
    dup_bst = BinarySearchTree()
    dup_values = [50, 30, 70, 30, 50, 70]
    print(f"Inserting values (with duplicates): {dup_values}")
    for val in dup_values:
        dup_bst.insert(val)
    print(f"Size after inserting duplicates: {len(dup_bst)}")
    print(f"Inorder traversal: {dup_bst.inorder_traversal()}")
    print()

    print("Empty tree checks:")
    empty_bst = BinarySearchTree()
    print(f"Min of empty tree: {empty_bst.find_min_node()}")
    print(f"Max of empty tree: {empty_bst.find_max_node()}")
    print(f"Floor of 50 in empty tree: {empty_bst.floor(50)}")
    print(f"Inorder traversal of empty tree: {empty_bst.inorder_traversal()}\n")

    print("=== Visualization ===\n")
    bst.visualize()

    return 0


if __name__ == "__main__":
    main()
