from typing import List, Optional

from tree_node import TreeNode


class SymmetricTree(object):
    """
    A class to check if a binary tree is symmetric.
    """

    @staticmethod
    def depth_first_search(
        node_1: Optional[TreeNode], node_2: Optional[TreeNode], depth: int
    ) -> bool:
        """
        Perform a depth-first search to compare two nodes for symmetry.

        Parameters
        ----------
        node_1 : Optional[TreeNode]
            The first node to compare.
        node_2 : Optional[TreeNode]
            The second node to compare.
        deoth: int
            Depth of the call stack used for indenting the print statements.

        Returns
        -------
        bool
            True if the nodes and their subtrees are symmetric, False otherwise.
        """
        if not node_1 and not node_2:
            print(f"{'  ' * depth}Both nodes are None -> returning True")
            return True
        if not node_1 or not node_2:
            print(f"{'  ' * depth}One of the nodes is None: {node_1} & {node_2} -> returning False")
            return False
        print(f"{'  ' * depth}Comparing Node 1: {node_1.data} | Node 2: {node_2.data}")
        if node_1.data != node_2.data:
            print(f"{'  ' * depth}Values do not match -> returning False")
            return False
        left_side: bool = SymmetricTree.depth_first_search(node_1.left, node_2.right, depth + 1)
        right_side: bool = SymmetricTree.depth_first_search(node_1.right, node_2.left, depth + 1)
        return left_side and right_side

    @staticmethod
    def check(root: Optional[TreeNode]) -> bool:
        """
        Check if a binary tree is symmetric.

        Parameters
        ----------
        root : Optional[TreeNode]
            The root node of the binary tree.

        Returns
        -------
        bool
            True if the binary tree is symmetric, False otherwise.
        """
        if not root:
            return False
        return SymmetricTree.depth_first_search(root, root, 0)


def main() -> int:
    test_cases: List[List[Optional[int]]] = [
        [1, 2, 2, 3, 4, 4, 3],
        [1, 2, 2, 8, 4, 4, 7],
        [1, 2, 2, None, 3, None, 3],
    ]

    for node_data in test_cases:
        print("Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(node_data)
        symmetric: bool = SymmetricTree.check(root)
        print(f"\nThe tree {'is' if symmetric else 'is not'} symmetric\n")

    return 0


if __name__ == "__main__":
    main()
