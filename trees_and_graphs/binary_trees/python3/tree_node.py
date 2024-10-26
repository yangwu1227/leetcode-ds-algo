from __future__ import annotations

from collections import deque
from typing import List, Optional, Union


class TreeNode(object):
    """ 
    This class represents a node in a binary tree.
    """
    def __init__(self, data: Optional[Union[int, float, str]] = None, left: Optional[TreeNode] = None, right: Optional[TreeNode] = None) -> None:
        """
        Initializes the tree node instance.

        Parameters
        ----------
        data : Optional[Union[int, float, str]]
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
    def construct_binary_tree(values: List[Optional[Union[int, float, str]]]) -> Optional[TreeNode]:
        """
        Constructs a binary tree from a list of values representing level-order traversal.

        Parameters
        ----------
        values : List[Optional[Union[int, float, str]]]
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
