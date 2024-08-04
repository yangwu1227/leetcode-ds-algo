# Min Stack 

Design a stack with `push`, `pop`, `top`, and retrieving the minimum element operations in constant time.

Implement the `MinStack` class:

- `MinStack()`: Initializes the stack.
- `push(int val)`: Pushes `val` onto the stack.
- `pop()`: Removes the top element.
- `top()`: Retrieves the top element.
- `get_min()`: Retrieves the minimum element.

Each function should have $O(1)$ time complexity.

## Two Stacks

We use two stacks to implement the `MinStack`. One stack stores the data, and the other stack stores the minimum values of the stack.

The length of the two stacks is the same, and the minimum value at each index of the minimum stack is the minimum value of the stack up to that index.

## Python

For the python implementation, we use `array.array`, which is a mutable sequence supporting append and pop operations while being more memory-efficient than a list for storing large sequences of numbers.

### Push

```python
def push(self, val) -> None:
    self._data_array.append(val)
    self._min_array.append(min(val, self._min_array[-1]))
```

Pushing is $O(1)$ since we only append to the end of the arrays. We also update the minimum value array by comparing the current value with the minimum value at the previous index, which is also $O(1)$.

### Pop

```python
def pop(self) -> None:
    self._data_array.pop(-1)
    self._min_array.pop(-1)
```

Popping is $O(1)$ since we only remove the last element of the arrays.
    
### Top

```python
def top(self):
    return self._data_array[-1]
```

Indexing is $O(1)$ and so getting the top element is $O(1)$.

### Get Min

```python
def get_min(self):
    return self._min_array[-1]
```

Again, indexing is $O(1)$ and so getting the minimum value is $O(1)$.

The space complexity of `MinStack` is $O(n + n) = O(2n) = O(n)$, where $n$ is the number of elements in the stack.

## C++

For the C++ implementation, we use `std::deque` to store the data and minimum values. This decision is made because `std::deque` does not require contiguous memory, and we can grow without worrying about resizing. We assume that the size of the `MinStack` is dynamic and unknown at creation.

### Push

```cpp
void MinStack::push(int val)
{
    this->dataStack.push_back(val);
    this->minStack.push_back(std::min(val, this->minStack.back()));
}
```

### Pop

```cpp
void MinStack::pop()
{
    this->dataStack.pop_back();
    this->minStack.pop_back();
}
```

### Top

```cpp
int MinStack::top() const
{
    return this->dataStack.back();
}
```

### Get Min

```cpp
int MinStack::getMin()
{
    return this->minStack.back();
}
```

The above operations have the same time complexities as those of the Python implementation, which are $O(1)$.

Again, the space complexity of `MinStack` is $O(n)$.
