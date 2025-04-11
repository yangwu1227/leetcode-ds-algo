from typing import Optional

from tree_node import TreeNode


def lowest_common_ancestor(
    p: TreeNode, q: TreeNode, root: Optional[TreeNode] = None
) -> Optional[TreeNode]:
    """
    Find the lowest common ancestor of two nodes in a binary tree.

    Parameters
    ----------
    p : TreeNode
        The first target node.
    q : TreeNode
        The second target node.
    root : TreeNode, optional
        The root of the binary tree.

    Returns
    -------
    TreeNode or None
        The lowest common ancestor of nodes `p` and `q`, or None if not found.
    """
    if not root:
        print("  The current node is empty; return None")
        return None

    if root.data == p.data or root.data == q.data:
        print(f"  Target found: root = {root} | p = {p} & q = {q}")
        return root

    left_result: Optional[TreeNode] = lowest_common_ancestor(p=p, q=q, root=root.left)
    right_result: Optional[TreeNode] = lowest_common_ancestor(p=p, q=q, root=root.right)

    if left_result and not right_result:
        print("  LCA found in the left subtree")
        return left_result
    elif right_result and not left_result:
        print("  LCA found in the right subtree")
        return right_result
    elif left_result and right_result:
        print("  LCA is the root node")
        return root
    else:
        print("  LCA not found")
        return None


def main() -> int:
    test_cases = [
        ([3, 5, 1, 6, 2, 0, 8, None, None, 7, 4], 5, 1),
        ([3, 5, 1, 6, 2, 0, 8, None, None, 7, 4], 5, 4),
        ([1, 2], 1, 2),
    ]
    for node_data, p_data, q_data in test_cases:
        print("Case " + "-" * 60, "\n")
        root: Optional[TreeNode] = TreeNode.construct_binary_tree(values=node_data)
        p: TreeNode = TreeNode(data=p_data)
        q: TreeNode = TreeNode(data=q_data)
        lca: Optional[TreeNode] = lowest_common_ancestor(p=p, q=q, root=root)
        print(f"\nThe lowest common ancester tree node is {lca}\n\n")

    return 0


if __name__ == "__main__":
    main()
