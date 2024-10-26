# Max Depth

Given a `root` node of a binary tree, return its maximum depth. A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

## Time Complexity

The `max_depth` function has a time complexity of `O(n)`, becuase the function visits each node in the tree exactly once. 

For each node, we perform $O(1)$ operations, i.e., checking for `None` or `nullptr`. 

## Space Complexity

The space complexity of the `max_depth` function is `O(n)`, where `n` is the number of nodes in the tree. This is because the function uses a recursive approach, which requires additional space on the call stack. The maximum depth of the call stack is equal to the height of the tree, which is `O(n)` in the worst case. 

If the tree is complete, i.e., all nodes have zero or two children, the space complexity is $O(\log n)$ as a best case scenario.
