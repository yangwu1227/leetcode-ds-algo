# Number of Recent Calls

The `RecentCounter` class tracks the number of requests within a `threshold`-millisecond window.

- `ping(t)`: 
  - Adds a request at time `t` (in milliseconds).
  - Returns the number of requests that have occurred in the past `threshold` milliseconds, including the new request.
  - The time `t` is guaranteed to be strictly greater than the time of the previous request.

## Time Complexity

### Python 

The internal `deque` used to store requests time stamps have $O(1)$ performance for adding and removing elements from both ends. Each call to `ping` includes a `while` loop that carries out the following operations:

* The queue is not empty, costing and that the front of the queue is less than `t - threshold`, both of which are $O(1)$  

    - If both conditions are met, the front of the queue is popped, which is $O(1)$

* Add the new request to the queue, which is $O(1)$

In the worst case, all previous time stamps are outside of the `threshold` window, and the `while` loop will run until the queue is empty. This results in a time complexity of $O(n)$, where `n` is the number of requests currently in the queue.

### C++

The `std::queue` used to store requests time stamps also have $O(1)$ performance for adding and removing elements from both ends. This is because the default container used by `std::queue` is `std::deque`. Therefore, the time complexity for the C++ implementation is the same as the Python implementation, which is $O(n)$.

## Space Complexity

The space complexity depends on the number of requests that are within the `threshold` window. During a single call to `ping`, the space complexity is $O(n)$ in the worst case, i.e., when all requests are within the `threshold` window. 

---

# Moving Average from Data Stream

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

- `next(int val)`: Returns the moving average of the last `window_size` values of the stream.

## Time Complexity

Each call to `next` involves the following operations:

* Check if the window is full, which is $O(1)$

  - If the window is full, remove the oldest element from the window by subtracting it from the running sum and popping the front of the queue, both of which are $O(1)$

* Add the new element to the window by pushing it to the back of the queue and adding it to the running sum, both are $O(1)$

The time complexity of each call to `next` is $O(1)$.

## Space Complexity

The space complexity depends on the window size. The space complexity is $O(window_size)$, as the queue will store at most `window_size` elements.

---

# Implement Stack using Queues

## Python

The `Stack` class in Python uses a `deque` from the `collections` module to implement a stack data structure, providing efficient LIFO (Last In, First Out) operations.

### Push

```python
def push(self, x: int) -> None:
    self.internal_deque.append(x)
```

The `push` method adds an element `x` to the top of the stack. 

- **Time Complexity**: $O(1)$, because the `append` operation on a `deque` is constant time from both ends. Here, we are adding to the right end of the `deque`.

### Pop

```python
def pop(self) -> int:
    if self.internal_deque:
        return self.internal_deque.pop()
    else:
        raise IndexError('Stack is empty')
```

The `pop` method removes and returns the top element of the stack.

- **Time Complexity**: $O(1)$, as `pop` from the end of a `deque` is a constant time operation.
- **Exception Handling**: Raises an `IndexError` if the stack is empty.

### Top

```python
def top(self) -> int:
    if self.internal_deque:
        return self.internal_deque[-1]
    else:
        raise IndexError('Stack is empty')
```

The `top` method returns the top element of the stack without removing it.

- **Time Complexity**: $O(1)$, because accessing the last element of a `deque` is constant time.
- **Exception Handling**: Raises an `IndexError` if the stack is empty.

### Empty

```python
@property
def empty(self) -> bool:
    return len(self.internal_deque) == 0
```

The `empty` method checks if the stack is empty. We use a property decorator to make it look like an attribute, abstracting away the fact that it is a method.

- **Time Complexity**: $O(1)$, as it only involves checking the length of the `deque`.

---

## C++

### Push

```cpp
void Stack::push(int x)
{
    this->internalDeque.push_back(x);
}
```

The `push` method adds an element `x` to the top of the stack.

- **Time Complexity**: $O(1)$, since `push_back` on `std::deque` is a constant time operation.

### Pop

```cpp
int Stack::pop()
{
    if (this->empty())
    {
        throw std::out_of_range("Stack is empty");
    }
    int popped = this->internalDeque.back();
    this->internalDeque.pop_back();
    return popped;
}
```

The `pop` method removes and returns the top element of the stack.

- **Time Complexity**: $O(1)$, as `pop_back` from `std::deque` is constant time.
- **Exception Handling**: Throws `std::out_of_range` if the stack is empty.

### Top

```cpp
int Stack::top()
{
    if (this->empty())
    {
        throw std::out_of_range("Stack is empty");
    }
    return this->internalDeque.back();
}
```

The `top` method returns the top element of the stack without removing it.

- **Time Complexity**: $O(1)$, because accessing the last element of a `std::deque` is constant time.
- **Exception Handling**: Throws `std::out_of_range` if the stack is empty.

### Empty

```cpp
bool Stack::empty()
{
    return this->internalDeque.empty();
}
```

The `empty` method checks if the stack is empty.

- **Time Complexity**: $O(1)$, as it only checks if the `deque` is empty.
