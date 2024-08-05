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
