# Tree Utils

The `tree_utils.hpp` and `tree_utils.cpp` translation (compilation) unit provides a set of utilities for binary tree traversal, visualization, and analysis. This includes level-order traversal, recursive traversals, tree comparison, height computation, and node count utilities.

This integrates with the `TreeNode` class, which represents a node in a binary tree.

## Table of Contents

- [Overview](#overview)
- [Classes and Design Patterns](#classes-and-design-patterns)
- [TreePrinter Class](#treeprinter-class)
  - [Public Functions](#public-functions)
  - [Private Functions](#private-functions)
- [Utility Namespace](#utility-namespace)
  - [Utility Functions](#utility-functions)
- [Key Design Patterns and Concepts](#key-design-patterns-and-concepts)

---

## Overview

The utility consists of:

1. **`TreePrinter` Class**: Handles tree traversal and printing in different orders.
2. **`utils` Namespace**: Provides utility functions for tree analysis (e.g., comparison, height, and node count).

The design leverages features such as `std::variant` for node data representation, smart pointers (`std::shared_ptr`), and template metaprogramming (`if constexpr`).

---

## TreePrinter Class

### Public Functions

#### 1. **`printLevelOrder`**

```cpp
void printLevelOrder(const TreeNode::ptr &root);
```

- **What**: Prints the tree in level-order traversal (breadth-first).
  - Uses a `std::queue` to process nodes level by level.
  - Displays "null" for missing children if any non-null nodes are still in the queue.

- **Why**: Level-order traversal is useful for visualizing the tree structure.

- **Implementation Details**:

  - `std::queue<const TreeNode *>` is used for level-order traversal.
  - `hasNonNullNode` checks if further non-null nodes exist in the queue, ensuring we print "null" only when needed.
  - Pushes left and right child pointers into the queue (even if `nullptr`).

#### 2. **`printPreOrder`**

```cpp
void printPreOrder(const TreeNode::ptr &root);
```

- **What**: Prints the tree in pre-order traversal (root-left-right).
  - Recursive implementation with a helper function.

- **Why**: Pre-order traversal is useful for tasks like serializing a tree.

- **Implementation Details**:

  - Calls the private `preOrderTraversal` method, which processes the root before its children.

#### 3. **`printInOrder`**

```cpp
void printInOrder(const TreeNode::ptr &root);
```

- **What**: Prints the tree in in-order traversal (left-root-right).
  - Recursive implementation with a helper function.

- **Why**: In-order traversal is particularly useful for binary search trees (BSTs) as it produces sorted output.

- **Implementation Details**:
  - Calls the private `inOrderTraversal` method, ensuring the left child is processed before the root.

#### 4. **`printPostOrder`**

```cpp
void printPostOrder(const TreeNode::ptr &root);
```

- **What**: Prints the tree in post-order traversal (left-right-root).
  - Recursive implementation with a helper function.

- **Why**: Post-order traversal is useful for evaluating expressions in expression trees.

- **Implementation Details**:
  - Calls the private `postOrderTraversal` method, processing children before the root.

---

### Private Functions

#### 1. **`nodeToString`**

```cpp
std::string nodeToString(const TreeNode::datatype &data);
```

- **What**: Converts a node’s data (`std::variant`) into a string representation.
  - Uses `std::visit` and `if constexpr` to handle multiple data types.

- **Why**: Allows for flexible data storage in tree nodes without losing the ability to print them.

- **Implementation Details**:
  - Supports `int`, `double`, and `std::string` data types.
  - Returns "null" for empty data (`std::monostate`).
  - Returns "unknown" for unsupported types.

#### 2. **`hasNonNullNode`**

```cpp
bool hasNonNullNode(const std::queue<const TreeNode *> &queue) const;
```

- **What**: Checks if a queue contains any non-null nodes.
  - Temporarily copies the queue and processes it.

- **Why**: Ensures "null" is printed only if necessary during level-order traversal.

- **Implementation Details**:
  - Iterates over the queue until a non-null node is found or it becomes empty.

---

## Utility Namespace

### Utility Functions

#### 1. **`areIdentical`**

```cpp
bool areIdentical(const TreeNode::ptr &root1, const TreeNode::ptr &root2);
```

- **What**: Compares two trees for structural and value equality.
  - Recursively checks each node’s data and structure.

- **Why**: Useful for testing and comparing trees in various scenarios.

- **Implementation Details**:
  - Returns `true` for two null roots.
  - Compares the current node's data (`==`) and recursively compares left and right subtrees.

#### 2. **`getHeight`**

```cpp
size_t getHeight(const TreeNode::ptr &root);
```

- **What**: Calculates the height (or depth) of the tree.
  - Height is defined as the number of edges on the longest path from root to leaf.

- **Why**: Helps in understanding the tree’s structure and balance.

- **Implementation Details**:
  - Recursively calculates the height of the left and right subtrees and returns the maximum, adding 1 for the current level.

#### 3. **`getNodeCount`**

```cpp
size_t getNodeCount(const TreeNode::ptr &root);
```

- **What**: Counts the total number of nodes in the tree.

- **Why**: Useful for analyzing tree size and memory requirements.

- **Implementation Details**:
  - Recursively counts nodes in the left and right subtrees, adding 1 for the current node.

---

## Key Design Patterns and Concepts

1. **Visitor Pattern with `std::variant`**
   - **What**: `nodeToString` uses the visitor pattern via `std::visit` to handle multiple data types stored in a `std::variant`.
   - **Why**: Provides a flexible way to support heterogeneous data types while maintaining type safety.
   - **How**: `std::visit` applies a lambda to determine the type of the variant at runtime.

2. **Recursive Traversals**
   - **What**: All tree traversals (pre-order, in-order, post-order) are implemented recursively.
   - **Why**: Simplifies the logic and leverages C++'s function call stack for traversal state.

3. **Template Metaprogramming with `if constexpr`**
   - **What**: Used in `nodeToString` to handle type-specific logic at compile time.

    ```cpp
    // In TreePrinter::nodeToString method
    std::string TreePrinter::nodeToString(const TreeNode::datatype &data)
    {
        return std::visit(
            [](const auto &value) -> std::string
            {
                using T = std::decay_t<decltype(value)>;
                if constexpr (std::is_same_v<T, std::monostate>)
                    return "null";
                else if constexpr (std::is_same_v<T, int> || std::is_same_v<T, double>)
                    return std::to_string(value);
                else if constexpr (std::is_same_v<T, std::string>)
                    return value;
                else
                    return "unknown";
            },
            data);
    }
    ```

    The `if constexpr` (introduced in C++17) is a compile-time conditional statement that evaluates conditions during compilation rather than at runtime. Unlike regular `if` statements, code in branches that don't match the condition is completely discarded during compilation.

    1. **Compile-Time Type Resolution**

      - Each variant type (`int`, `double`, `string`, etc.) gets exactly the code path it needs
      - Invalid operations for specific types are eliminated during compilation
      - For example, calling `std::to_string()` on a string would be a compile error, but `if constexpr` prevents that code from being compiled for string types

    2. **Performance Optimization**

      - No runtime type checking overhead - all type decisions are made at compile time
      - Generated assembly code contains only the relevant code path for each type

    3. **Type Safety**

      - Ensures type-specific operations are only compiled for compatible types
      - Prevents potential runtime errors from incompatible type operations
      - Compiler verifies each branch independently for its specific type
