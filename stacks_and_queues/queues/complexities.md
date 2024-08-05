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

