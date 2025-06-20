# Height and Depth in Binary Trees

## Node

- **Depth of a Node:**

  - The **depth** of a node is defined as the number of edges from that node **up** to the root node of the tree.
  - The root node has a depth of `0`.

- **Height of a Node:**

  - The **height** of a node is the number of edges on the longest path from that node **down** to a leaf node.
  - A leaf node has a height of `0`.

## Tree

- **Height of a Tree:**

  - The height of a binary tree is equal to the height of its root node.
  - Alternatively, the height of a tree is equal to the depth of the deepest leaf node.

- **Diameter (Width) of a Tree:**

  - The diameter of a tree is the number of nodes on the longest path between any two leaf nodes.
  - The diameter reflects the "width" or maximum extent of the tree.

## Visual Representation

Consider the following binary tree illustration from [stackoverflow](https://stackoverflow.com/a/2603707/12923148):

<div style="text-align: center;">
    <img src="diagrams/bst_height_depth_width.png" width="35%">
</div>

In this diagram:

- The root node has a depth of `0` and height of `3`.
- The diameter (width) of this particular tree is `6` nodes.

---

# Range Sum of BST

Given the `root` of a binary search tree (BST) and two integers `low` and `high`, return the sum of values of all nodes with a value in the range `[low, high]` (inclusive).

## Time Complexity

### Iterative Approach (BFS)

The time complexity depends on the tree's structure and the given range:

- **Best Case**: If the range doesn't overlap with any values in the BST, many branches can be pruned early, resulting in $O(\log n)$ complexity for a balanced BST.

- **Worst Case**: If the range encompasses all values in the BST, every node must be visited, resulting in $O(n)$ complexity.

In the iterative implementation:

- Each node is processed at most once (dequeued, checked, and potentially added to sum)

- The pruning logic (skipping left subtree when `node.data <= low` and right subtree when `node.data >= high`) reduces the number of nodes visited.

Therefore, the general time complexity is $O(m)$ where $m$ is the number of nodes that need to be visited after pruning, with $m \leq n$.

### Recursive Approach (DFS)

The recursive implementation follows similar pruning logic:

- We only recurse into the left subtree if the current node's data is greater than `low`

- We only recurse into the right subtree if the current node's data is less than `high`

The time complexity analysis is identical to the iterative approach:

- Best case: $O(\log n)$ for a balanced BST with minimal range overlap
- Worst case: $O(n)$ when all nodes must be visited

Again, the general time complexity remains $O(m)$ where $m$ is the number of nodes visited after pruning.

## Space Complexity

### Iterative Approach (BFS)

The space complexity is dominated by the queue used for BFS:

- **Queue Storage**: Maximum size equals the maximum width of the tree after pruning.
  - Best case (skewed tree or minimal overlap): $O(1)$ space
  - Worst case (complete tree with full range): $O(w)$ space, where $w$ is the maximum width

The general space complexity is $O(w)$, which can approach $O(\frac{n}{2}) = O(n)$ in the worst case for a complete binary tree.

### Recursive Approach (DFS)

The space complexity is determined by the maximum recursion stack depth:

- **Call Stack**: Maximum depth equals the height of the tree after pruning.
  - Best case (balanced BST with minimal range overlap): $O(\log n)$
  - Worst case (skewed tree with full range overlap): $O(n)$

The general space complexity is $O(h)$, where $h$ is the height of the tree after pruning.

For different tree structures:

- Balanced BST: $O(\log n)$ space
- Skewed tree: $O(n)$ space
