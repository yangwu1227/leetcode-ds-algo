# Reversing a Linked List

<center>
    <img src="diagrams/reverse_linked_list.gif">
</center>

## Python 

```python
def reverse(head: ListNode) -> ListNode:
    prev = None
    current = head.next
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node 

    head.next = prev
    return head
```

## C++

```cpp
ListNode::Ptr reverse(const ListNode::Ptr &head)
{
    ListNode::Ptr prev = nullptr;
    ListNode::Ptr current = head->next;
    while (current != nullptr)
    {
        ListNode::Ptr nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head->next = prev;
    return head;
}
```

## Explanation

Given a singly linked list with $n$ nodes, the algorithm that reverses it is as follows:

1. Initialize two pointers `prev` and `current` to `None` and the start of the linked list, respectively. If the sentinel `head` is used, `current` should be initialized to `head->next` or `head.next`.

2. As long as the `current` pointer is not `None` or `nullptr`, do the following:

    * Store the next node to the right of the `current` pointer in a temporary variable `next_node`. This ensures that the next node is not lost when `next` pointer of the `current` node is updated.

    * Reverse the `next` pointer of the `current` node to point to the `prev` node. Now, the node currently pointed to by `current` is pointing to the node that was previously behind it.

    * Move the `prev` pointer to the `current` node and the `current` pointer to the `next_node` node. This is done to move the pointers one step forward towards the right in the linked list as we reverse each node to point to the previous node.

3. After the loop ends, the `prev` pointer will be pointing to the last node of the original linked list. This is also the first node of the reversed linked list. Update the `next` pointer of the sentinel `head` to point to this node.

4. Return the `head` node of the reversed linked list.

<center>

| Step | List State | `current` | `prev` | `next_node` | Operations |
|------|-------------|-----------|--------|-------------|------------|
| Initial | `head -> 1 -> 2 -> 3 -> 4 -> 5 -> None` | `1` | `None` | `2` | Initialize pointers |
| 1 | `head -> 1 -> None` <br> `2 -> 3 -> 4 -> 5 -> None` | `2` | `1 -> None` | `3` | `current->next = prev` <br> Move `prev` and `current` |
| 2 | `head -> 1 -> None` <br> `2 -> 1 -> None` <br> `3 -> 4 -> 5 -> None` | `3` | `2 -> 1 -> None` | `4` | `current->next = prev` <br> Move `prev` and `current` |
| 3 | `head -> 1 -> None` <br> `2 -> 1 -> None` <br> `3 -> 2 -> 1 -> None` <br> `4 -> 5 -> None` | `4` | `3 -> 2 -> 1 -> None` | `5` | `current->next = prev` <br> Move `prev` and `current` |
| 4 | `head -> 1 -> None` <br> `2 -> 1 -> None` <br> `3 -> 2 -> 1 -> None` <br> `4 -> 3 -> 2 -> 1 -> None` <br> `5 -> None` | `5` | `4 -> 3 -> 2 -> 1 -> None` | `None` | `current->next = prev` <br> Move `prev` and `current` |
| Final | `head -> 1 -> None` <br> `2 -> 1 -> None` <br> `3 -> 2 -> 1 -> None` <br> `4 -> 3 -> 2 -> 1 -> None` <br> `5 -> 4 -> 3 -> 2 -> 1 -> None` | `None` | `5 -> 4 -> 3 -> 2 -> 1 -> None` | `None` | `current->next = prev` <br> Move `prev` and `current` |
| Update | `head -> 5 -> 4 -> 3 -> 2 -> 1 -> None` | `None` | `5 -> 4 -> 3 -> 2 -> 1 -> None` | `None` | Update `head->next` |

</center>

## Time Complexity

The algorithm traverses the linked list once, reversing the `next` pointer of each node. The time complexity is $O(n)$, where $n$ is the number of nodes in the linked list.

## Space Complexity

The algorithm uses a constant amount of extra space. The space complexity is $O(1)$.

---

# Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes. Only the nodes can be changed and not the values of the nodes.

## Explanation

Given a singly linked list with the following structure `12 -> 27 -> 7 -> 17 -> 77`:

<center>

| Step | List State | `current` | `prev` | Operations |
|------|-------------|-----------|--------|------------|
| Initial | `head -> 12 -> 27 -> 7 -> 17 -> 77 -> None` | `12` | `head` | Initialize pointers |
| 1 | `head -> 27 -> 12 -> 7 -> 17 -> 77 -> None` | `7` | `12` | Swap `12` and `27` <br> Move `prev` to `12` and `current` to `7` |
| 2 | `head -> 27 -> 12 -> 17 -> 7 -> 77 -> None` | `77` | `7` | Swap `7` and `17` <br> Move `prev` to `7` and `current` to `77` |
| Final | `head -> 27 -> 12 -> 17 -> 7 -> 77 -> None` | `None` | `7` | No more pairs to swap |

</center>

## Time Complexity

Given linked list with $n$ nodes:

* We check for two edge cases:

    - If the linked list is empty, which is $O(1)$.

    - If the linked list has only one node, which is $O(1)$.

* As long as there are at least two nodes to swap, we traverse the linked list and carry out the following operations on each pair of `first` and `second` nodes:

    - At the start of each iteration, we have: `prev -> first -> second -> next_first -> next_second`.

        **Swapping operations**:

        - Set `first.next` to `second.next` so `prev -> (first & second) -> next_first -> next_second`.

        - Set `second.next` to `first` so `(prev & second) -> first -> next_first -> next_second`.

        - Set `prev.next` to `second` so `prev -> second -> first -> next_first -> next_second`.

        **Moving pointers**:

        - Move `prev` to `first` so `second -> (prev = first) -> next_first -> next_second`.

        - Move `current` to `first.next` so `second -> (prev = first) -> (current = next_first) -> next_second`.

        The above operations cost at each iteration $O(5) = O(1)$.

Because we traverse the linked list once and perform $O(1)$ operations at each iteration, the time complexity is $O(n)$.

## Space Complexity

Becuase we only use pointers, the space complexity is $O(1)$.

---

# Maximum Twin Sum of a Linked List

Given a linked list of integers, find the maximum twin sum. A twin sum is the sum of first and last elements, second and second-to-last elements, and so on.

* `[7, 12, 27, 17, 77, 27]` has the following two sums:

    - `7 + 27 = 34`.

    - `12 + 77 = 89`.

    - `27 + 17 = 44`.

    The maximum twin sum is `89`.

## Explanation

Given a singly linked list with the following structure `7 -> 12 -> 27 -> 17 -> 77 -> 27`:

### Finding the Middle of the Linked List

<center>

| Step | `slow` | `fast` | `length` | Operations |
|------|--------|--------|----------|------------|
| Initial | `head` | `head` | `0` | Initialize pointers and `length` |
| 1 | `7` | `12` | `1` | * Move `slow` one step <br> * Move `fast` two steps <br> * Increment `length` |
| 2 | `12` | `17` | `2` | * Move `slow` one step <br> * Move `fast` two steps <br> * Increment `length` |
| 3 | `27` | `27` | `3` | * Move `slow` one step <br> * Move `fast` two steps <br> * Increment `length` |
| Final | `17` | `27.next = None` | NA | * `while` loop does not execute <br> * `length *=2` to get the length of the linked list |

</center>

After finding the middle of the linked list, we have the following:

* `length = 6`

* `last_node_second_half = fast = 27`

* `last_node_first_half = slow = 27`

### Reverse the Second Half of the Linked List

To start reversing the second half of the linked list, we create a `current` pointer and a `prev` pointer:

* `current = last_node_first_half.next = slow.next = 17`

* `prev = None = nullptr`: This ensures that the first node of the second half points to `None` or `nullptr` after reversing.

For the list `7 -> 12 -> 27 -> 17 -> 77 -> 27`:

<center>

| Step | `current` | `prev` | Operations |
|------|-----------|--------|------------|
| 1 | `17` | `None` | * `next_node = 77` <br> * `17.next = None` <br> * `prev = 17` <br> * `current = next_node = 77` |
| 2 | `77` | `17` | * `next_node = 27` <br> * `77.next = 17` <br> * `prev = 77` <br> * `current = next_node = 27` |
| 3 | `27` | `77` | * `next_node = 12` <br> * `27.next = 77` <br> * `prev = 27` <br> * `current = next_node = 12` |

</center>

To connect the reversed second half to the first half, we have:

* `last_node_first_half.next = last_node_second_half` of `27.next = 27`

This ensures that the last node of the first half points to the first node of the second half. The linked list becomes `7 -> 12 -> 27 -> 27 -> 77 -> 17`.

### Calculate the Maximum Twin Sum

Given the linked list `7 -> 12 -> 27 -> 27 -> 77 -> 17`, each twin pair is already $\frac{\text{length}}{2}$ steps apart.

* $7$ is $3$ steps away from $27$

* $12$ is $3$ steps away from $77$

* $27$ is $3$ steps away from $17$

Initialize a new set of `fast` and `slow` pointers to the sentinel `head` and move `fast` $\frac{\text{length}}{2}$ steps ahead of `slow`:

* `fast = 27`

* `slow = head`

<center>

| Step | `slow.next` | `fast.next` | Operations |
|------|--------|--------|------------|
| 1 | `7` | `27` | * $7 + 27 = 34$ <br> * Move `slow` to `12` and `fast` to `77` |
| 2 | `12` | `77` | * $12 + 77 = 89$ <br> * Move `slow` to `27` and `fast` to `17` |
| 3 | `27` | `17` | * $27 + 17 = 44$ <br> * Move `slow` to `27` and `fast` to `None` |
| Final | `27` | `None` | `while` loop does not execute |

</center>

The maximum twin sum is `89`.

## Time Complexity

The first while loop takes $\frac{n}{2}$ steps to find the middle of the linked list.

- `fast` goes from `head -> 12 -> 27 -> 17`, i.e., $3$ steps.

The second while loop starts from the first node of the second half and, again, takes $\frac{n}{2}$ steps to reach the end of the linked list.

- `current` goes from `27 -> 17 -> 77 -> 27`, i.e., $3$ steps.

- `last_node_first_half` goes from `27 -> 27`, i.e., $1$ step.

Finally, the third while loop contains $\frac{n}{2}$ addition operations to calculate each pair of twin sums.

All operations inside the loops can be considered $O(1)$. Therefore, the overall time complexity is $O(n)$.

## Space Complexity 

We only use pointers, so the space complexity is $O(1)$.

---

# Reverse Linked List II

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`.

## Explanation

Given a singly linked list with the following structure `1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7`, `left = 3`, and `right = 5`:

The first loop (`left - 1 = 3 - 1 = 2` iterations) is used to move the `current` pointer to the node right before position `left`:

<center>

| Step | List State | `current` | Operations |
|------|-------------|-----------|------------|
| Initial | `head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> None` | `head` | Initialize pointer |
| 1 | `head -> [1] -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> None` | `1` | Move `current` to `1` |
| 2 | `head -> 1 -> [2] -> 3 -> 4 -> 5 -> 6 -> 7 -> None` | `2` | Move `current` to `2` |

</center>

Initialize the following pointers:

*  `node_before_left = current = 2`

* `left_node = current = 3`

* `prev = None = nullptr`

The second loop (`right - left + 1 = 5 - 3 + 1 = 3` iterations) reverses the nodes from position `left` to position `right`:

<center>

| Step | `current` | `prev` | Operations |
|------|-----------|--------|------------|
| 1 | `3` | `None` | * `next_node = 4` <br> * `3.next = None` <br> * `prev = 3` <br> * `current = next_node = 4` |
| 2 | `4` | `3` | * `next_node = 5` <br> * `4.next = 3` <br> * `prev = 4` <br> * `current = next_node = 5` |
| 3 | `5` | `4` | * `next_node = 6` <br> * `5.next = 4` <br> * `prev = 5` <br> * `current = next_node = 6` |

</center>

After reversing the nodes from position `left` to position `right`, we connect the reversed nodes to the original linked list:

* `node_before_left.next = 2.next -> prev = 5 -> 4 -> 3 -> None`

* `left_node.next = 3.next -> current = 6 -> 7 -> None`

The linked list becomes `1 -> 2 -> 5 -> 4 -> 3 -> 6 -> 7`.

## Time Complexity

In the worst case, left and right are at the ends of the linked list `left = 1` and `right = n`, the `current` pointer moves from the start of the linked list to the end. The time complexity is $O(n)$.

## Space Complexity

The space complexity is $O(1)$ because we only use pointers.

---

# Palindrome Linked List

Given the `head` of a singly linked list, return `true` if it is a palindrome.

## Time Complexity

### Python

The python implementation uses three `while` loops and a `for` loop:

* The first `while` loop iterates the `fast` and `slow` pointers at different speeds to find the middle of the linked list.

    - With an odd number of nodes, the `fast` pointer requires $\text{Floor}(\frac{n}{2})$ steps for the `while` loop to terminate; the `fast` pointer points at `None` by the end of the loop.

    - With an even number of nodes, the `fast` pointer requires $\frac{n}{2}$ steps to reach the end of the linked list; the `fast` pointer points at the last node by the end of the loop.

* The second `while` loop reverses:

    - The second half of the linked list including the middle node if the number of nodes is odd, requiring $\text{Floor}(\frac{n}{2})$ steps.

    - The second half of the linked list in $\frac{n}{2}$ steps if the number of nodes is even.

* The third `for` loop iterates a `fast` pointer ahead of a `slow` pointer in preparation for the final comparisons of nodes.

    - For an odd number of nodes, the `fast` pointer moves Floor($\frac{n}{2}$) steps ahead of the `slow` pointer.

    - For an even number of nodes, the `fast` pointer moves $\frac{n}{2}$ steps to reach the end of the linked list.

* The final `while` loop compares the nodes on the left and right sides of the linked list.

    - For an odd number of nodes, there will be Floor($\frac{n}{2}$) comparisons.

    - For an even number of nodes, there will be $\frac{n}{2}$ comparisons.

#### Odd

$$
\begin{align*}
O(4 \times \text{Floor}(\frac{n}{2})) &= \text{Asymptotically} \; O(4 \times \frac{n}{2}) \\
&= O(2n) \\
&= O(n)
\end{align*}
$$

#### Even

$$
\begin{align*}
O(4 \times \frac{n}{2})&= O(2n) \\
&= O(n)
\end{align*}
$$

### C++

The c++ implementation differs from the python implementation in the following ways:

* The first `while` loop checks for `fast->next != nullptr` and `fast->next->next != nullptr` instead of `fast != nullptr` and `fast->next != nullptr`. The effect is that, by the end of this loop, the `slow` pointer will point to the node right before the first node of the section to be reversed, regardless of whether the number of nodes is odd or even. 

    - For odd number of nodes, the `fast` pointer requires $\text{Floor}(\frac{n}{2})$ steps to reach the end of the linked list.

    - For even number of nodes, the `fast` pointer requires $\frac{n}{2}$ steps to reach the end of the linked list.

* The second `while` loop reverses the second half of the linked list.

    - It takes $\text{Floor}(\frac{n}{2})$ steps to reverse the second half of the linked list for an odd number of nodes.

    - It takes $\frac{n}{2}$ steps to reverse the second half of the linked list.

    After reversing the second half of the linked list, we do not connect the reversed nodes to the original linked list as we do in the python implementation.

* The third `while` loop compares each pair of nodes in the first and second half of the linked list.

    - For an odd number of nodes, there will be Floor($\frac{n}{2}$) comparisons.

    - For an even number of nodes, there will be $\frac{n}{2}$ comparisons.

Again, the time complexity is $O(n)$. However, the c++ implementation differs from the python implementation:

* We do not connect the reversed nodes to the original linked list.

* No need to handle things differently for odd and even numbers of nodes.

* No need for a `for` loop to move the `fast` pointer ahead of the `slow` pointer before comparing nodes.

The runtime performance of the c++ implementation is likely to be better than the python implementation. It is trivial to implement these optimizations in the python implementation as well.

## Space Complexity

For both the python and C++ implementations, the space complexity is $O(1)$ because we only use pointers.
