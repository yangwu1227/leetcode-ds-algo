# Doubly Linked List

## Remove & Insert Operations

<center>
    <img src="diagrams/remove_insert.gif">
</center>

## Python

### `add_to_end`

```python
def add_to_end(self, node_to_add: ListNode) -> None:
    node_to_add.next = self.tail
    node_to_add.prev = self.tail.prev
    self.tail.prev.next = node_to_add
    self.tail.prev = node_to_add
```

* The `next` pointer of the new node should point to the tail sentinel node.
* The `prev` pointer of the new node should point to the node that is currently the last real node in the list (i.e., the node that the tail sentinel node points back to).
* The `next` pointer of the node that is currently the last real node should be updated to point to the new node, making the new node the last real node.
* The `prev` pointer of the tail sentinel node should be updated to point to the new node, making the new node the last node in the list before the tail sentinel.

### `remove_from_end`

```python
def remove_from_end(self) -> None:
    if self.head.next == self.tail:
        return None

    node_to_remove = self.tail.prev
    node_to_remove.prev.next = self.tail
    self.tail.prev = node_to_remove.prev
```

* If the list is empty (i.e., head points directly to tail), do nothing.
* The node to be removed is the one before the tail sentinel.
* The `next` pointer of the node before `node_to_remove` should now point to the tail sentinel.
* The `prev` pointer of the tail sentinel should be updated to point to the node before `node_to_remove` since it is now the last real node in the list.

### `add_to_start`

```python
def add_to_start(self, node_to_add: ListNode) -> None:
    node_to_add.prev = self.head
    node_to_add.next = self.head.next 
    self.head.next.prev = node_to_add
    self.head.next = node_to_add
```

* The `prev` pointer of the new node should point to the head sentinel.
* The `next` pointer of the new node should point to the node that is currently the first real node (i.e., the node after the head sentinel).
* The `prev` pointer of the node that is currently the first real node should be updated to point to the new node, making the new node the first real node.
* The `next` pointer of the head sentinel should be updated to point to the new node, since the new node is now the first node in the list.

### `remove_from_start`

```python
def remove_from_start(self) -> None:
    if self.head.next == self.tail:
        return None

    node_to_remove = self.head.next
    node_to_remove.next.prev = self.head
    self.head.next = node_to_remove.next 
```

* If the list is empty (i.e., head points directly to tail), do nothing.
* The node to be removed is the one after the head sentinel.
* The `prev` pointer of the node after the one being removed should point to the head sentinel.
* The `next` pointer of the head sentinel should be updated to point to the node after the one being removed.

---

## C++

### `node.hpp` & `node.cpp`

* **Smart Pointers** (`std::shared_ptr`): Used to manage the lifetime of dynamically allocated objects, i.e., `ListNode` instances. The `std::shared_ptr` automatically deletes the managed object when the last `shared_ptr` pointing to it is destroyed. This ensures that each node in the linked list, which may be pointed to by multiple pointers, is deleted only when it is no longer needed.

* **Type Aliases** (`using`): Creates a type alias for `std::shared_ptr<ListNode>`. This improves code readability and reduces the need to write `std::shared_ptr<ListNode>` repeatedly.

```cpp
using Ptr = std::shared_ptr<ListNode>;
```

* **Constructor Initialization Lists**: Used to initialize class members. This is more efficient than assignment inside the constructor body because it directly constructs the members.

* **Null Pointers**: The `next` and `prev` pointers will be null pointers as they are not explicitly initialized.

* **Explicit Keyword**: When the constructor of a class is marked as `explicit`, it cannot be used for implicit conversions or copy-initialization. This means that the compiler will not use this constructor to convert an integer (or any other type specified) to a `ListNode` object implicitly.

```cpp
explicit ListNode(int data) : data(data) {}
```

* **Friend Functions**: Declares a non-member function that can access the private and protected members of the class. In this case, `operator<<` is made a friend of `ListNode` so it can access `ListNode`'s private data members. Overloading the `<<` operator allows for custom output formatting when using `std::cout`.

```cpp
friend std::ostream& operator<<(std::ostream& os, const ListNode& node);
```

```cpp
friend class DoublyLinkedList;
```

### `doubly.hpp` & `doubly.cpp`

#### `DoublyLinkedList::DoublyLinkedList()`

* **Constructor**: The `std::make_shared<T>()` is a utility function used to create a `std::shared_ptr<T>`. It allocates memory for an object of type `T` and constructs the object in that memory. It then returns a `std::shared_ptr<T>` that manages this memory. 

* **Sentinel ListNodes**: The doubly linked list uses sentinel nodes (`head` and `tail`) to simplify the implementation. These sentinel nodes are not part of the actual data but are used to avoid special cases when adding or removing nodes from the list.

* `std::make_shared<ListNode>()` is more efficient than `std::shared_ptr<ListNode>(new ListNode())` because it avoids a separate memory allocation for the control block of the `shared_ptr`.

* `head = std::make_shared<ListNode>()`: 
    - Allocates memory for a `ListNode` object.
    - Constructs a `ListNode` object in that memory with the default constructor (`ListNode(int data = 0)`), which means data is initialized to `0`.
    - Returns a `std::shared_ptr<ListNode>` that manages this newly created `ListNode`.
    - Assigns this `std::shared_ptr<ListNode>` to the member variable `head`.
    - This node serves as the sentinel `head` node.

* `tail = std::make_shared<ListNode>()`:
    - Similar to the previous line, but this time it creates and assigns the sentinel tail node.

```cpp  
DoublyLinkedList::DoublyLinkedList() {
    head = std::make_shared<ListNode>(); // Sentinel head node
    tail = std::make_shared<ListNode>(); // Sentinel tail node
    head->next = tail;
    tail->prev = head;
}
```
#### `void DoublyLinkedList::add_to_end(ListNode::Ptr node_to_add)`

```cpp
void DoublyLinkedList::add_to_end(ListNode::Ptr node_to_add)
{
    node_to_add->next = tail;
    node_to_add->prev = tail->prev;
    tail->prev->next = node_to_add;
    tail->prev = node_to_add;
}
```

* **Pointers Used**: `node_to_add`, `tail`
* **Purpose**: Adds a new node to the end of the list.
    - **Set Pointers of the New ListNode**:
        - `node_to_add->next = tail`: The new node's `next` points to the tail sentinel.
        - `node_to_add->prev = tail->prev`: The new node's `prev` points to the node currently at the end of the list.
    - **Update Existing ListNodes**:
        - `tail->prev->next = node_to_add`: The current last node's `next` points to the new node.
        - `tail->prev = node_to_add`: The tail's `prev` points to the new node, making it the new last node.

#### `void DoublyLinkedList::remove_from_end()`

```cpp
void DoublyLinkedList::remove_from_end()
{
    if (head->next == tail)
    {
        return;
    }

    ListNode::Ptr node_to_remove = tail->prev;
    node_to_remove->prev->next = tail;
    tail->prev = node_to_remove->prev;
}
```

* **Pointers Used**: `head`, `tail`, `node_to_remove`
* **Purpose**: Removes the node at the end of the list.
    - **Check for Empty List**:
        - `if (head->next == tail)`: If the list is empty (only sentinels), do nothing.
    - **Identify ListNode to Remove**:
        - `ListNode::Ptr node_to_remove = tail->prev`: Points to the node before the tail.
    - **Update Existing ListNodes**:
        - `node_to_remove->prev->next = tail`: The node before the one being removed points to the tail.
        - `tail->prev = node_to_remove->prev`: The tail points back to the node before the one being removed.

#### `void DoublyLinkedList::add_to_start(ListNode::Ptr node_to_add)`

```cpp
void DoublyLinkedList::add_to_start(ListNode::Ptr node_to_add)
{
    node_to_add->prev = head;
    node_to_add->next = head->next;
    head->next->prev = node_to_add;
    head->next = node_to_add;
}
```

* **Pointers Used**: `node_to_add`, `head`
* **Purpose**: Adds a new node to the start of the list.
    - **Set Pointers of the New ListNode**:
        - `node_to_add->prev = head`: The new node's `prev` points to the head sentinel.
        - `node_to_add->next = head->next`: The new node's `next` points to the node currently at the start of the list.
    - **Update Existing ListNodes**:
        - `head->next->prev = node_to_add`: The current first node's `prev` points to the new node.
        - `head->next = node_to_add`: The head's `next` points to the new node, making it the new first node.

#### `void DoublyLinkedList::remove_from_start()`

```cpp
void DoublyLinkedList::remove_from_start()
{
    if (head->next == tail)
    {
        return;
    }

    ListNode::Ptr node_to_remove = head->next;
    node_to_remove->next->prev = head;
    head->next = node_to_remove->next;
}
```

* **Pointers Used**: `head`, `tail`, `node_to_remove`
* **Purpose**: Removes the node at the start of the list.
    - **Check for Empty List**:
        - `if (head->next == tail)`: If the list is empty (only sentinels), do nothing.
    - **Identify ListNode to Remove**:
        - `ListNode::Ptr node_to_remove = head->next`: Points to the node after the head.
    - **Update Existing ListNodes**:
        - `node_to_remove->next->prev = head`: The node after the one being removed points back to the head.
        - `head->next = node_to_remove->next`: The head points to the node after the one being removed.

#### `void DoublyLinkedList::display() const`

```cpp
void DoublyLinkedList::display() const
{
    ListNode::Ptr current = head->next;
    while (current != tail)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "None" << std::endl;
}
```

* **Pointers Used**: `head`, `tail`, `current`
* **Purpose**: Displays the values of all nodes in the list from start to end.
    - **Traversal**:
        - `ListNode::Ptr current = head->next`: Starts at the first real node (node after head).
        - `while (current != tail)`: Iterates through the list until the tail is reached.
        - `current = current->next`: Moves to the next node in the list.
    - **Output**:
        - `std::cout << current->data << " -> "`: Prints the data of each node followed by an arrow.
        - `std::cout << "None" << std::endl`: Prints `None` at the end to signify the end of the list.
