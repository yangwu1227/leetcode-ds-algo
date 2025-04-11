from typing import Optional, Union

from tree_node import TreeNode


class Solution(object):
    @staticmethod
    def depth_first_search(node: Optional[TreeNode], max_val_so_far: Union[int, float]) -> int:
        """
        Perform a postorder traversal to count 'good' nodes in a binary tree.

        A 'good' node is defined as a node whose value is greater than or equal
        to the maximum value encountered on the path from the root to that node.

        Parameters
        ----------
        node : Optional[TreeNode]
            The current node being traversed in the tree.
        max_val_so_far : Union[int, float]
            The maximum value encountered from the root to this node.

        Returns
        -------
        int
            The total number of 'good' nodes encountered in the subtree rooted at 'node'.
        """
        if not node or not node.data:
            print("    Empty tree node, returning 0\n")
            return 0
        current_max_val_so_far = max(max_val_so_far, node.data)
        left = Solution.depth_first_search(node=node.left, max_val_so_far=current_max_val_so_far)
        right = Solution.depth_first_search(node=node.right, max_val_so_far=current_max_val_so_far)
        num_good_nodes: int = left + right
        if node.data >= max_val_so_far:
            num_good_nodes += 1
            print(
                f"   Current node: {node} | Good Node | Updated number of good nodes: {num_good_nodes}\n"
            )
        else:
            print(
                f"   Current node: {node} | Not a good Node | Number of good nodes: {num_good_nodes}\n"
            )
        return num_good_nodes

    @staticmethod
    def good_node(root: Optional[TreeNode]) -> int:
        """
        Count the number of 'good' nodes in the binary tree rooted at 'root'.

        Parameters
        ----------
        root : Optional[TreeNode]
            The root node of the binary tree.

        Returns
        -------
        int
            Total number of 'good' nodes in the binary tree.
        """
        if not root:
            return 0
        if root.left is None and root.right is None:
            return 1
        Solution.depth_first_search(node=root, max_val_so_far=float("-inf"))
        return Solution.depth_first_search(node=root, max_val_so_far=float("-inf"))


def main() -> int:
    test_cases = [[3, 1, 4, 3, None, 1, 5], [3, 3, None, 4, 2], [1]]
    for node_data in test_cases:
        print("Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=node_data)
        total_num_good_nodes: int = Solution.good_node(root)
        print(f"Total number of good nodes: {total_num_good_nodes}\n\n")

    return 0


if __name__ == "__main__":
    main()
