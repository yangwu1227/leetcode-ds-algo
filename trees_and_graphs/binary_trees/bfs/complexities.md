# Right Side View of Binary Tree

Given the `root` of a binary tree, find the value of the rightmost node at each level of the tree.

## Explanation

Consider the binary tree `[1, 2, 3, 4, None, None, None, 5]`:

<div style="text-align: center;">
    <img src="diagrams/right_side_view.png" width="50%">
</div>

The breadth-first search (BFS) algorithm explores each level, enqueuing children nodes from left to right and capturing the last node in the queue at each level.

<center>

| Level | Nodes at Level | Queue Before Processing          | Rightmost Node Added | Queue After Processing     |
|-------|----------------|---------------------------------|----------------------|----------------------------|
| 1     | 1              | `[1]`                           | `1`                  | `[2, 3]`                   |
| 2     | 2, 3           | `[2, 3]`                        | `3`                  | `[4]`                      |
| 3     | 4              | `[4]`                           | `4`                  | `[5]`                      |
| 4     | 5              | `[5]`                           | `5`                  | `[]` (Empty)               |

</center>

The rightmost nodes at each level are `[1, 3, 4, 5]`. These are the nodes that are visible when the tree is viewed from the right side.

## Time Complexity

The algorithm uses a breadth-first traversal:

- **Queue Operations:**

  - Every node is enqueued and dequeued exactly once.
  - Enqueue (`append`) and dequeue (`popleft`) operations are each $O(1)$.

- **Node Processing:**

  - Each node is processed exactly once: checked for left and right children.
  - Operations per node (enqueueing children, appending rightmost nodes) are $O(1)$.

Hence, the overall time complexity of the BFS algorithm is $O(n)$, where $n$ is the number of nodes in the binary tree.

## Space Complexity

The algorithm's space complexity is dominated by the maximum size of the queue at any point during traversal:

- **Worst Case (Complete Binary Tree):** Maximum queue size is at the last level, roughly $\frac{n}{2}$, resulting in $O(n)$ space complexity.

    A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.

    In a complete (or nearly complete) binary tree, about half of its nodes can reside at the last level. To see why, consider a perfect binary tree with height $h$. Such a tree has exactly $2^{h+1}-1$ nodes in total, and its last level contains $2^h$ nodes. Since $2^h$ is roughly half of $2^{h+1}-1$, that last level alone can hold about half of the entire node count.

    ```
    # The queue may contain all nodes at the last level 2^2 = 4
          1
         / \
        2   3
       / \ / \
      4  5 6  7
    ```

- **Best Case (Skewed Tree):** Only one node is present at each level, giving an $O(1)$ queue size.

    ```
    # The queue may contain only one node at each level
          1
           \
            2
             \
              3
               \
                4
                 \
                  5
    ```

Therefore, the general space complexity is:

$$
O(w)
$$

where $w$ is the maximum width (number of nodes at the widest level) of the binary tree. In the worst case of a complete tree, $w$ can be proportional to $n$, making the space complexity $O(n)$.
