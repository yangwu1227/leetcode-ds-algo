# type: ignore
from tree_node import Optional, TreeNode


class Solution(object):
    @staticmethod
    def depth_first_search(node: TreeNode, curr_sum: int, target: int) -> bool:
        """
        Recursively checks if a path from the `node` to any leaf node sums to the target.

        Parameters
        ----------
        node : TreeNode
            The current node in the binary tree.
        curr_sum : int
            The cumulative sum of the nodes' values from the root to the current node.
        target : int
            The target sum to check for a path from root to leaf.

        Returns
        -------
        bool
            True if a path from root to a leaf node with a cumulative sum equal to `target`
            exists; False otherwise.

        Notes
        -----
        This function traverses the tree using depth-first search, updating the
        cumulative sum at each node. It returns True as soon as a valid path is found.
        """
        if not node:
            print("    Empty tree node, returning False\n")
            return False
        if node.left is None and node.right is None:
            comp = curr_sum + node.data == target
            print(
                f"    We are at a leaf node, current sum ({curr_sum}) + node data ({node.data}) == target ({target}) is {comp}\n"
            )
            return comp
        print(f"current sum ({curr_sum}) + node.data ({node.data}) = {curr_sum + node.data}\n")
        curr_sum += node.data
        left_result = Solution.depth_first_search(node.left, curr_sum, target)
        right_result = Solution.depth_first_search(node.right, curr_sum, target)
        return left_result or right_result

    @staticmethod
    def path_sum(root: TreeNode, target: int) -> bool:
        """
        Initiates a search for a root-to-leaf path in the binary tree with a specified sum.

        Parameters
        ----------
        root : TreeNode
            The root node of the binary tree.
        target : int
            The target sum to find in a root-to-leaf path.

        Returns
        -------
        bool
            True if a path from root to any leaf node exists such that the sum of node values
            equals `target`; False otherwise.
        """
        path_exists = Solution.depth_first_search(root, 0, target)
        return path_exists


def main() -> int:
    test_cases = [
        ([5, 4, 8, 11, None, 13, 4, 7, 2, None, None, None, 1], 22),
        ([1, 2, 3], 5),
        ([7, 12, None, 8, 9, 12, 7, 17, None, None, 19, 27, None], 58),
    ]
    for node_data, target in test_cases:
        print("Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=node_data)
        path_exists: bool = Solution.path_sum(root, target)
        print(
            f"There exists {'a' if path_exists else 'no'} path such that sum of all data values equals target = {target}\n\n"
        )

    return 0


if __name__ == "__main__":
    main()
