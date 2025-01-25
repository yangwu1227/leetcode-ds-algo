# TreeNode Class

This `TreeNode` class represents a single node in a binary tree. Each node can contain data and may have references to a left and right child. Additionally, the class provides a static method to construct a binary tree from a level-order list representation.

---

# Python Implementation

## Class Definition

```python
class TreeNode(object)
```

### Attributes

- **data**: `Optional[Union[int, float, str]]`  
  Stores the data value for this node (e.g., `int`, `float`, `str`).
- **left**: `Optional[TreeNode]`  
  Reference to the left child node.
- **right**: `Optional[TreeNode]`  
  Reference to the right child node.

---

## Initializer

```python
__init__(self, data: Optional[Union[int, float, str]] = None, left: Optional[TreeNode] = None, right: Optional[TreeNode] = None) -> None
```

### Parameters

- **data**: `Optional[Union[int, float, str]]`  
  The value to store in the node. Defaults to `None`.
- **left**: `Optional[TreeNode]`  
  A reference to the left child. Defaults to `None`.
- **right**: `Optional[TreeNode]`  
  A reference to the right child. Defaults to `None`.

---

## Methods

### `__repr__`

Returns a string representation of the `TreeNode` instance.

```python
__repr__(self) -> str
```

**Returns**: `str`  
A string in the format: `TreeNode(data = <data>)`.

---

### `construct_binary_tree`

Constructs a binary tree from a list of values in level-order (breadth-first) format. `None` values represent missing nodes.

```python
@staticmethod
construct_binary_tree(values: List[Optional[Union[int, float, str]]]) -> Optional[TreeNode]
```

#### Parameters

- **values**: `List[Optional[Union[int, float, str]]]`  
  A list of node values in level-order.  
  - `values[i]` represents the node at the `i`-th position in a complete binary tree.
  - `None` represents a missing node (e.g., for trees that are not perfect or complete).

#### Returns

- **TreeNode**: The root node of the constructed binary tree. If the input list is empty or starts with `None`, it returns `None`.

#### Example Usages

##### Example 1

```python
values = [1, 2, 3, None, 4, 5, None]
root = TreeNode.construct_binary_tree(values)
```

```python
         1
       /   \
      2     3
       \   / 
        4 5
```

##### Example 2

```python
values = [1, 2, 3, None, 4, None, 5]
root = TreeNode.construct_binary_tree(values)
```

```python
        1
      /   \
     2     3
      \     \
       4     5
```

#### Implementation Details

1. The method initializes a root node from the first element and uses a queue to manage nodes at each level.
2. It iteratively assigns left and right children to each node in a breadth-first manner, progressing through the `values` list.
3. If a node is missing (i.e., `None`), it skips assigning children to that node.

#### Complexity Analysis

- **Time Complexity**: $O(n)$  
  Each node is created and processed once.
  
- **Space Complexity**: $O(n)$  
  The queue may hold up to `n/2` nodes in a complete binary tree, where $n$ is the total number of elements in `values`.

---

### `visualize_binary_tree`

This static method visualizes a binary tree using `matplotlib` and `networkx`. It draws the tree structure, placing each node at the appropriate level and adding edges to represent parent-child relationships.

---

# C++ Implementation

The header file `tree_node.hpp` defines the `TreeNode` class structure, data members, and public methods. It also includes key type aliases and uses `std::variant` to store various types of data.

## Class Definition

```cpp
class TreeNode
```

### Type Aliases

- **ptr**: `std::unique_ptr<TreeNode>`  
  A unique pointer type to manage `TreeNode` instances automatically. Using `unique_ptr` ensures that each `TreeNode` object has one owner, allowing safe memory management without manual deletion.

- **datatype**: `std::variant<std::monostate, int, double, std::string>`  
  A variant type that can hold one of several types (`int`, `double`, `std::string`, or `std::monostate`). This provides flexibility for node data types:
  - **`std::monostate`** represents a "null" value, indicating an empty or missing node.

### Attributes

- **data**: `datatype`  
  The data value for this node, which can be an `int`, `double`, `std::string`, or `null`.

- **left**: `ptr`  
  A unique pointer to the left child node.

- **right**: `ptr`  
  A unique pointer to the right child node.

---

## Constructor

```cpp
explicit TreeNode(datatype data = std::monostate{}, ptr left = nullptr, ptr right = nullptr);
```

### Parameters

- **data**: `datatype`  
  The value to store in the node. Defaults to `std::monostate`, which represents `null`.

- **left**: `ptr`  
  A unique pointer to the left child node, initialized to `nullptr`.

- **right**: `ptr`  
  A unique pointer to the right child node, initialized to `nullptr`.

This constructor initializes `data`, `left`, and `right` attributes for a `TreeNode`. Defaulting to `std::monostate` supports creating empty nodes with no data. The `explicit` keyword prevents implicit conversions such as `TreeNode node = 5` (i.e., from `int` to `TreeNode`).

---

## Operator Overload `operator<<`

Overloading the stream insertion `<<` operator provides an easy way to print a `TreeNode`'s data. This is achieved by using `std::visit` to process each variant type in `data`.

```cpp
friend std::ostream &operator<<(std::ostream &os, const TreeNode &tree_node);
```

- **`std::ostream &os`**: The output stream where the data will be written (e.g., `std::cout`).

- **`const TreeNode &tree_node`**: A constant reference to the `TreeNode` being printed. It is passed as `const` to ensure the function does not modify the object.

- The function returns `os` to allow chaining, so you can write expressions like: `std::cout << node1 << node2`.

**Implementation Details**

**1. Using `std::visit` to Handle `std::variant`**

```cpp
std::visit(
    [&os](auto &&arg) { /* lambda body */ },
    tree_node.data
);
```

- **`std::visit`**: A standard library function used to access and process the value inside a `std::variant`. It takes:

  - A **visitor**: A callable object (in this case, a lambda function).

  - The `std::variant` instance (`tree_node.data`).

`std::visit` ensures that the correct type inside the `std::variant` is processed.

### **3. The Lambda Visitor**

```cpp
[&os](auto &&arg)
```

- **`[&os]`**: Captures the `os` output stream by reference so it can be accessed inside the lambda without copying.

- **`auto &&arg`**: A **forwarding reference** (or universal reference) that allows the lambda to generically handle any type and value category stored in the `std::variant`. This means:
  - If the variant holds an lvalue (e.g., `int&` or `std::string&`), `arg` will be deduced as an lvalue reference.
  - If the variant holds an rvalue (e.g., `int&&` or `std::string&&`), `arg` will be deduced as an rvalue reference.
  - This avoids unnecessary copies and ensures efficient handling of both temporary (rvalue) and persistent (lvalue) data.

- **Why use `auto &&arg`?**
  - **Generic**: Supports any type stored in the `std::variant` (`int`, `double`, `std::string`, `std::monostate`).
  - **Efficient**: Avoids unnecessary copies by binding directly to the value in the variant.
  - **Flexible**: Preserves the value category ([lvalue/rvalue](https://www.youtube.com/watch?v=fbYknr-HPYE)) of the data.

In this context, `auto &&arg` ensures the lambda seamlessly processes all possible data types stored in the `TreeNode`'s `data` member. It's the most efficient and generic choice for this use case.

**4. Handling Each Type in `std::variant`**

The lambda processes each possible type stored in the `std::variant` instance `data`. The `std::variant` in `TreeNode` is defined as:

```cpp
using datatype = std::variant<std::monostate, int, double, std::string>;
```

This means `data` can hold one of the following:

- `std::monostate`: Represents a "null" or empty value.
- `int`: An integer.
- `double`: A floating-point number.
- `std::string`: A string.

The lambda uses `if constexpr` and type traits to differentiate between these types.

**5. Type Deduction**

```cpp
using T = std::decay_t<decltype(arg)>;
```

- **`decltype(arg)`**: Determines the exact type of `arg`, including references and `const` qualifiers.
- **`std::decay_t`**: Removes references, `const`, and `volatile` qualifiers, leaving the "base type." For example:
  - If `arg` is `const int&`, `std::decay_t<decltype(arg)>` resolves to `int`.

`T` is used to perform compile-time checks on the type of `arg`.

**6. Checking for `std::monostate`**

```cpp
if constexpr (std::is_same_v<T, std::monostate>)
{
    os << "null";
}
```

- **`if constexpr`**: A compile-time conditional that enables branching based on type traits.
- **`std::is_same_v<T, std::monostate>`**: Checks if `T` is `std::monostate`, which indicates a "null" value in the `std::variant`.
- If `T` is `std::monostate`, the lambda writes `"null"` to the output stream.

**7. Handling Other Types**

```cpp
else
{
    os << arg;
}
```

- For all other types (`int`, `double`, `std::string`), the lambda directly writes `arg` to the output stream.
- Since the `<<` operator is already overloaded for these types, the lambda simply delegates to the existing functionality.

**8. Returning the Stream**

```cpp
return os;
```

---

## `constructBinaryTree`

Constructs a binary tree from a vector of values in level-order. Uses `std::queue` to manage node levels as children are added.

```cpp
static ptr constructBinaryTree(const std::vector<datatype> &values);
```

### Parameters

- **values**: `std::vector<datatype>`  
  A list representing node values in level-order:
  - `std::monostate` represents missing nodes.

### Returns

- **ptr**: A unique pointer to the root of the constructed binary tree. Returns `nullptr` if the list is empty or starts with `std::monostate`.

### Implementation Steps

1. **Initialize Root**:  
   - Checks if `values` is empty or starts with `std::monostate`. If true, returns `nullptr`.
   - Creates the root node and initializes a `std::queue` to handle nodes at each level.

2. **Level-by-Level Construction**:
   - Uses `queue` to manage the order in which nodes receive children. It pops nodes as it assigns their children.
   - **Left and Right Children**:
     - If the next value is not `std::monostate`, it creates a new child node, assigns it to the current node's left or right pointer, and adds the child to the queue.

3. **Complexity Analysis**:
   - **Time Complexity**: $O(n)$, where $n$ is the number of elements in `values`.
   - **Space Complexity**: $O(n)$, since `queue` holds up to $\frac{n}{2}$ nodes at any point.

### Example Usage

```cpp
std::vector<TreeNode::datatype> values = {1, 2, 3, std::monostate{}, 4, std::monostate{}, 5};
TreeNode::ptr root = TreeNode::construct_binary_tree(values);
```

Resulting binary tree:

```
        1
      /   \
     2     3
      \     \
       4     5
```
