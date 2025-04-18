# Binary Search Trees (BST)

A **Binary Search Tree (BST)** is a binary tree that maintains the ordering property:

- For every node, all keys in the left subtree are **strictly less** than the node’s key.
- For every node, all keys in the right subtree are **strictly greater** than the node’s key.

## Core Properties

1. **Ordering (Search) Property** – defined above.
2. **Binary Structure** – each node has at most two children.
3. **Uniqueness** – classic BSTs assume unique keys.  Two common strategies for duplicates are
   - **Count‑in‑node**: store a multiplicity field in each node.
   - **Consistent side rule**: e.g. place `≤` keys in the left subtree, `>` in the right.
4. **In‑order Traversal** – yields keys in ascending order.

## Operations and Asymptotic Complexities

> Heights are denoted by *h*.  For balanced trees *h ≈ log₂ n*; for a degenerate (unbalanced) tree *h = n – 1*.

| Operation      | Time (average) | Time (worst) | Space |
|----------------|----------------|--------------|-------|
| Search         | Θ(log n)¹      | O(n)         | O(1)  |
| Insert         | Θ(log n)¹      | O(n)         | O(1)  |
| Delete         | Θ(log n)¹      | O(n)         | O(1)  |
| Minimum/Maximum| Θ(log n)¹      | O(n)         | O(1)  |

¹ These average costs assume either (a) keys are inserted in uniformly random order or (b) the tree is self‑balancing. If keys arrive in an adversarial (e.g. already‑sorted) sequence and the tree is not self‑balancing, every operation degrades to the worst‑case column. A BST is self‑balancing when it automatically adjusts its own shape during insertions and deletions so that the tree height stays bounded by $O(\log n)$.

## Comparison with Other Data Structures

| Structure | Search | Insert | Delete | Space | Maintains Order |
|-----------|--------|--------|--------|-------|-----------------|
| **Balanced BST** | Θ(log n) | Θ(log n) | Θ(log n) | Θ(n) | ✔ |
| **Unbalanced BST** | Θ(n) | Θ(n) | Θ(n) | Θ(n) | ✔ |
| **Array (unsorted)** | Θ(n) | Θ(1) | Θ(n) | Θ(n) | ✖ |
| **Array (sorted)** | Θ(log n) | Θ(n) | Θ(n) | Θ(n) | ✔ |
| **Hash Table** | Θ(1)* | Θ(1)* | Θ(1)* | Θ(n) | ✖ |
| **Linked List** | Θ(n) | Θ(1) | Θ(n) | Θ(n) | ✖ |

\*Average with a good hash function; worst‑case Θ(n).
