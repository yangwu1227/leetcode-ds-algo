# Max Depth

Given a `root` node of a binary tree, return its maximum depth. A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

## Time Complexity

The `max_depth` function has a time complexity of $O(n)$, becuase the function visits each node in the tree exactly once. 

For each node, we perform $O(1)$ operations, i.e., checking for `None` or `nullptr`. 

## Space Complexity

The space complexity of the `max_depth` function is $O(n)$, where $n$ is the number of nodes in the tree. This is because the function uses a recursive approach, which requires additional space on the call stack. The maximum depth of the call stack is equal to the height of the tree, which is $O(n)$ in the worst case. 

If the tree is complete, i.e., all nodes have zero or two children, the space complexity is $O(\log_2 n)$ as a best case scenario.

---

# Path Sum

Given the `root` of a binary tree and an integer `target`, return `true` if the tree has a root-to-leaf path such that adding up all the values along the path equals `target`; a leaf is a node with no children.

## Explanation

Consider the following binary tree with `target = 22`:

<div style="text-align: center;">
    <img src="diagrams/path_sum.png" width="50%">
</div>

<center>

| Step | Node Value | Current Sum | Target | Action |
|------|------------|-------------|--------|--------|
| **Tree:** `[5, 4, 8, 11, None, 13, 4, 7, 2, None, None, None, 1]`, Target = 22 |
| 1    | 5          | 0           | 22     | `current sum (0) + node.data (5) = 5` |
| 2    | 4          | 5           | 22     | `current sum (5) + node.data (4) = 9` |
| 3    | 11         | 9           | 22     | `current sum (9) + node.data (11) = 20` |
| 4    | 7          | 20          | 22     | `We are at a leaf node, current sum (20) + node data (7) == target (22) is False` |
| 5    | 2          | 20          | 22     | `We are at a leaf node, current sum (20) + node data (2) == target (22) is True` |
|      | **Return** |             |        | `Path found, returning True` |
|      | **Explanation**         |        |        | `A path (5 -> 4 -> 11 -> 2) has a cumulative sum of 22, matching the target` |

</center>

## Time Complexity 

Each node in the binary tree is visited once as we perform a depth-first search traversal. For each node, the function:

* Check that the current `node` is not `None` or a `nullptr`, which is $O(1)$

* Check that the left and right children of the current node are none, both of which are ($O(1)$)

    - If a leaf is encountered, a sum operation is performend `curr_sum + node.data` and it is compared
      to `target`, again $O(1)$

    - If the current node is not a leaf, then `curr_sum += node.data`, which can be considered $O(1)$

In the worst case, where no path exists, and all nodes are visited, the overall time complexity of the search algorithm is $O(n)$, where $n$ is the total number of nodes in the binary tree.

## Space Complexity

The space complexity of the algorithm is influenced by the recursion stack depth, which depends on the height of the tree:

1. **Best and Average Case (Balanced Tree):** In a balanced binary tree, the height $h$ is $O(\log_2 n)$. Thus, the recursive stack will hold up to $O(\log_2 n)$ calls at any point, resulting in a space complexity of $O(\log_2 n)$.
   
2. **Worst Case (Skewed Tree):** In an unbalanced, skewed tree (e.g., all nodes on one side), the height $h$ can be $O(n)$, leading to $O(n)$ recursive calls on the stack.

Hence, the overall space complexity is $O(h)$, where $h$ is the height of the tree, translating to:

   - $O(\log_2 n)$ in the best and average case for a balanced tree
   - $O(n)$ in the worst case for a skewed tree

---

# Count Good Nodes in Binary Tree

Given a binary tree `root`, a node `X` in the tree is considered good if the following condition is satisfied:

> From the root of the binary tree to node `X`, there is no node with a value greater than that of `X`.

Find the number of good nodes in the binary tree.

## Explanation

Consider the following binary tree:

<div style="text-align: center;">
    <img src="diagrams/good_node.png" width="50%">
</div>

<center>

| Step | Node       | Max Value So Far | Decision                           | Number of Good Nodes |
|------|------------|------------------|------------------------------------|----------------------|
| 1    | 3 (root)   | -∞               | Good Node (3 ≥ -∞)                 | +1                   |
| 2    | 1 (left)   | 3                | Not a Good Node (1 < 3)            |                      |
| 3    | 3 (left of 1) | 3             | Good Node (3 ≥ 3)                  | +1                   |
| 4    | None       | N/A              | Empty Tree Node, returning 0       |                      |
| 5    | None       | N/A              | Empty Tree Node, returning 0       |                      |
| 6    | 4 (right)  | 3                | Good Node (4 ≥ 3)                  | +1                   |
| 7    | 1 (left of 4) | 4             | Not a Good Node (1 < 4)            |                      |
| 8    | None       | N/A              | Empty Tree Node, returning 0       |                      |
| 9    | None       | N/A              | Empty Tree Node, returning 0       |                      |
| 10   | 5 (right of 4) | 4            | Good Node (5 ≥ 4)                  | +1                   |

</center>

## Time Complexity

Each node in the binary tree is visited once, and the following operations are performed at each node:

* Check if the current node is not `None` or a `nullptr`, which can be considered $O(1)$

* Add the number of good nodes that have been found from the left and right subtrees so far, which is $O(1)$

* Check if the current node is a good node, incrementing the count if it is, which is $O(1)$

The implementation uses postorder traversal. The time complexity of the algorithm is $O(n)$, where $n$ is the total number of nodes in the binary tree.

## Space Complexity

The space complexity of the algorithm is again $O(h)$, where $h$ is $\log_2 n$ for a balanced tree and $n$ for a skewed tree.

---

# Same Tree

Given the roots of two binary trees `p` and `q`, check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

## Explanation

Consider the following binary trees:

<div style="text-align: center;">
    <img src="diagrams/same_tree_1.png" width="50%">
</div>

<div style="text-align: center;">
    <img src="diagrams/same_tree_2.png" width="50%">
</div>

<center>

| Step | Node (Tree 1) | Node (Tree 2) | Action                                  | Result   | Recursiion Tree Depth |
|------|---------------|---------------|-----------------------------------------|----------|--------------|
| 1    | 1             | 1             | Comparing nodes (1 == 1). Proceed deeper. | -        | -            |
| 2    | 3             | 3             | Comparing nodes (3 == 3). Proceed deeper. | -        | -            |
| 3    | 7             | 7             | Comparing nodes (7 == 7). Proceed deeper. | -        | -            |
|      | None          | None          | Both children nodes of Tree 1 are `None`. Returning `True`.  | `True`   | Depth 3      |
|      | None          | None          | Both children nodes of Tree 2 are `None`. Returning `True`.  | `True`   | Depth 3      |
| 4    | -             | -             | Returning `True` for nodes (7, 7).        | `True`   | Depth 2      |
| 5    | 10            | 9             | Comparing nodes (10 != 9). Not equal. Returning `False`. | `False` | Depth 2      |
|      | None          | None          | Both children nodes of Tree 1 are `None`. Returning `True`.  | `True`   | Depth 3      |
|      | None          | None          | Both children nodes of Tree 2 are `None`. Returning `True`.  | `True`   | Depth 3      |
| 6    | -             | -             | Returning `False` for nodes (10, 9).      | `False`  | Depth 2      |
| 7    | -             | -             | Returning `False` for nodes (3, 3) since one of the children is `False`. | `False`  | Depth 1      |
| 8    | 5             | 5             | Comparing nodes (5 == 5). Proceed deeper. | -        | -            |
|      | None          | None          | Both children nodes of Tree 1 are `None`. Returning `True`.  | `True`   | Depth 3      |
|      | None          | None          | Both children nodes of Tree 2 are `None`. Returning `True`.  | `True`   | Depth 3      |
| 9    | -             | -             | Returning `True` for nodes (5, 5).        | `True`   | Depth 1      |
| 10   | -             | -             | Returning `False` for nodes (1, 1) since the left subtree returned `False`. | `False`  | Root         |

</center>

## Time Complexity

In any case, the algorithm visits each node in both trees once. All operations performed at each node (i.e., comparisons) can be considered $O(1)$. Thus, the overall time complexity of the algorithm is $O(n)$, where $n$ is the total number of nodes in the binary tree.

## Space Complexity

The space complexity of the algorithm is $O(h)$, where $h$ is $\log_2 n$ for a balanced tree and $n$ for a skewed tree.
