# Implementation Using Deque

## Python 

### Push

```python
def push(self, x: int) -> None:
    self.internal_deque.append(x)
```

The time complexity of the `push` operation is $O(1)$ since `deque` supports append operations from both ends with approximately the same $O(1)$ performance.

### Pop

```python
def pop(self) -> int:
    try:
        return self.internal_deque.popleft()
    except IndexError as error:
        raise IndexError("The queue is empty")
```

The time complexity of the `pop` operation is $O(1)$ for the same reason as the `push` operation.

### Peek

```python
def peek(self) -> int:
    try:
        return self.internal_deque[0]
    except IndexError as error:
        raise IndexError("Cannot peek in an empty queue")
```

The time complexity of the `peek` operation is $O(1)$; for `deque`, indexed access is only $O(1)$ at both ends, which is exactly what we do in this operation.

### Empty

```python
@property
def empty(self) -> bool:
    return len(self.internal_deque) == 0
```

The time complexity of the `empty` operation is $O(1)$ since we only need to check the length of the `deque` to determine if it is empty. 

This is made into a property to more closely align with how the **emptiness** of a queue is thought of--- as a property of the queue itself.

## C++

### Push

```cpp
void QueueDeque::push(int x)
{
    this->internalDeque.push_back(x);
}
```

Similar to Python, the time complexity of the `push` operation is $O(1)$ since `std::deque` have constant insertion and removal time at both ends.

### Pop

```cpp
int QueueDeque::pop()
{
    int front = this->internalDeque.front();
    this->internalDeque.pop_front();
    return front;
}
```

Again, this operation has a time complexity of $O(1)$.

### Peek

```cpp
int QueueDeque::peek() const
{
    return this->internalDeque.front();
}
```

The time complexity of the `peek` operation is $O(1)$ since we only need to access the `front` element of the `deque`.

### Empty

```cpp
bool QueueDeque::empty() const
{
    return this->internalDeque.empty();
}
```

The time complexity of the `empty` operation is $O(1)$.

---

# Implementation Using Two Stacks

## Python

The Python implementation uses two `List` objects to simulate the queue. `List` instances support $O(1)$ amortized time complexity for append and pop operations from the end of the list.

### Push

```python
def push(self, x: int) -> None:
    if not self.stack:
        self.front = x
    self.stack.append(x)
```

The `push` operation carries out the following steps:

* If the `stack` list is empty, set the `front` attribute of the queue to the element being pushed, costing $O(1)$.

* Append the element to the `stack` list, costing $O(1)$.

The time complexity of the `push` operation is $O(1)$.

### Pop

```python
def pop(self) -> int:
    if not self.stack_reversed:
        while self.stack:
            self.stack_reversed.append(self.stack.pop(-1))
    return self.stack_reversed.pop(-1)
```

The `pop` operation carries out the following steps:

* If the `stack_reversed` list is empty, all elements are popped from the `stack` list and pushed to the `stack_reversed` list. This costs $O(n)$, where $n$ is the number of elements in the `stack` list.

* If the `stack_reversed` list is non-empty, the top element is popped from it, costing $O(1)$.

The time complexity of the `pop` operation is $O(n)$ in the worst case and $O(1)$ in the average case. The amortized time complexity of the `pop` operation is $O(1)$.

### Peek

```python
def peek(self) -> int | None:
    if self.stack_reversed:
        return self.stack_reversed[-1]
    return self.front
```

The `peek` operation carries out the following steps:

* If the `stack_reversed` list is non-empty, return the top element of the `stack_reversed` list. This costs $O(1)$.

* If the `stack_reversed` list is empty, return the `front` attribute of the queue. This costs $O(1)$.

The time complexity of the `peek` operation is $O(1)$.

### Empty

```python
@property
def empty(self) -> bool:
    return len(self.stack) == len (self.stack_reversed) == 0
```

The queue is empty if both the `stack` and `stack_reversed` lists are empty. This is because the `stack` list contains all the elements that are pushed into the queue, and the `stack_reversed` list contains all the elements in the reverse order once the first pop operation is performed. 

The time complexity of the `empty` check is $O(1)$.

## C++

### Push

```c++
void QueueStack::push(int x)
{
    if (this->stack.empty())
    {
        this->front = x;
    }
    this->stack.push(x);
}
```

The `push` operation carries out the following steps:

* If the stack is empty, set the `front` class data member of the queue to the element being pushed, costing $O(1)$.

* Push the element to the stack, costing $O(1)$.

Hence, the time complexity of the `push` operation is $O(1)$.

### Pop

```c++
int QueueStack::pop()
{
    if (this->stackReversed.empty())
    {
        while (!this->stack.empty())
        {
            this->stackReversed.push(this->stack.top());
            this->stack.pop();
        }
    }
    int poppedElement = this->stackReversed.top();
    this->stackReversed.pop();
    return poppedElement;
}
```

The `pop` operation carries out the following steps:

* If the `stackReversed` stack is empty, we need to reverse the elements in the `stack` stack. This is done by popping all elements from the `stack` stack and pushing them to the `stackReversed` stack. This costs $O(n)$, where $n$ is the number of elements in the `stack` stack.

* If the `stackReversed` stack is non-empty, we simply pop the top element from it, costing $O(1)$.

The overall time complexity of the `pop` operation is the same as that of the Python implementation, which is amortized $O(1)$.

### Peek

```c++
int QueueStack::peek() const
{
    if (this->empty())
    {
        throw std::out_of_range("Queue is empty");
    }
    if (!this->stackReversed.empty())
        return this->stackReversed.top();
    return this->front;
}
```

The `peek` operation carries out the following steps:

* If the queue is empty, throw an exception, because we cannot peek into an empty queue. This costs $O(1)$.

* If the `stackReversed` stack is non-empty, return the top element of the `stackReversed` stack. This costs $O(1)$.

* If the above conditions are not met, the `stackReversed` stack is empty, and we return the `front` class data member of the queue. This costs $O(1)$.

The overall time complexity of the `peek` operation is $O(1)$.

### Empty

```c++
bool QueueStack::empty() const
{
    return this->stack.empty() && this->stackReversed.empty();
}
```

The `empty` operation checks if both the `stack` and `stackReversed` stacks are empty. Both of these operations cost $O(1)$.
