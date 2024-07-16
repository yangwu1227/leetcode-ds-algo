#  Remove Linked List Elements

Given the `head` of a linked list and an integer `data`, remove all the nodes of the linked list that has `data` as its value, and return the new `head`.

## Explanation

Conisder the singly linked list witht the following structure: `head -> 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6 -> None`. If we want to remove all the nodes with value `6`, the new linked list should look like this: `head -> 1 -> 2 -> 3 -> 4 -> 5 -> None`:

<center>

| Iteration | `prev` | `current` | `current.next` | `current.data` | `data` | Action |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | `head` | `1` | `2` | `1` | `6` | * `1 != 6`  <br> * `prev = 1` <br> * `current = 2` |
| 2 | `1` | `2` | `6` | `2` | `6` | * `2 != 6`  <br> * `prev = 2` <br> * `current = 6` |
| 3 | `2` | `6` | `3` | `6` | `6` | * `6 == 6`  <br> * Skip `current` via `prev.next = current.next` <br> * `current = 3` |
| 4 | `2` | `3` | `4` | `3` | `6` | * `3 != 6`  <br> * `prev = 3` <br> * `current = 4` |
| 5 | `3` | `4` | `5` | `4` | `6` | * `4 != 6`  <br> * `prev = 4` <br> * `current = 5` |
| 6 | `4` | `5` | `6` | `5` | `6` | * `5 != 6`  <br> * `prev = 5` <br> * `current = 6` |
| 7 | `5` | `6` | `None` | `6` | `6` | * `6 == 6`  <br> * Skip `current` via `prev.next = current.next` <br> * `current = None` |

</center>

## Time Complexity

The time complexity of this algorithm is $O(n)$ as we need to traverse the entire linked list to check and remove nodes. All operations inside the `while` loop can be considered $O(1)$.

## Space Complexity

The space complexity is $O(1)$ as we are using a constant amount of extra space, i.e., two pointers `prev` and `current`, regardless of the input size.

---

# Convert Binary Number in a Linked List to Integer

Given the `head` of a singly linked list, whose nodes represent a binary number, return the decimal value of the number in the linked list.

The most significant bit is at the head of the list.

## Left Shift and Bitwise OR

To convert the binary number to decimal, we can iterate through the linked list and calculate the decimal value by left-shifting the current value by 1 bit and then bitwise OR with the current node's value to set the new least significant bit.

### << Operator

<center>
    <img src="diagrams/left_shift_by_one.gif">
</center>

In general, shifting the left operand by $n$ bits is equivalent to:

$$
\begin{align*}
a << n = a \times 2^n
\end{align*}
$$

### | Operator 

The bit OR operator `|` is used to set a bit to 1 if it is 1 in either of the operands. For example, `1010 | 0010 = 1010`. This operation is used to set the least significant bit to the current node's value.

## Explanation

Consider the linked list `head -> 1 -> 0 -> 1 -> None`. The binary number represented by this linked list is `101`. The decimal value of this binary number is $5$.

<center>

| Step | Current Node Value | Decimal Value (Before Shift and OR) | Decimal Value (Binary) (Before Shift and OR) | Decimal Value (After Shift and OR) | Decimal Value (Binary) (After Shift and OR) |
|------|---------------------|-------------------------------------|----------------------------------------------|------------------------------------|---------------------------------------------|
| 1    | 1                   | 0                                   | 000                                          | 1                                  | 001                                         |
| 2    | 0                   | 1                                   | 001                                          | 2                                  | 010                                         |
| 3    | 1                   | 2                                   | 010                                          | 5                                  | 101                                         |

</center>

## Time Complexity

The time complexity of this algorithm is $O(n)$ as we need to traverse the entire linked list to calculate the decimal value. All operations inside the `while` loop can be considered $O(1)$.

## Space Complexity

The space complexity is $O(1)$ as we are using a constant amount of extra space, i.e., a single variable `decimal`, regardless of the input size.

---

# Odd Even Linked List

Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices. The first node is considered odd and the second node is even, and so on.

## Explanation

The following pointers are initialized:

* `current` points to the first node of the linked list.
* `prev` points to the sentinel head node.
* `first_even_node` points to the first even node.

### Odd Number of Nodes

Consider the linked list `head -> 1 -> 2 -> 3 -> 4 -> 5 -> None`. The odd-even linked list should look like `head -> 1 -> 3 -> 5 -> 2 -> 4 -> None`.

<center>

| Iteration | `prev` | `current` | `current.next` | `length` | Action |
| --- | --- | --- | --- | --- | --- |
| 1 | `head` | `1` | `2` | `1` | * `current.next = current.next.next` so `1 -> 3` <br> * `prev = 1` <br> * `current = next_node = 2` |
| 2 | `1` | `2` | `3` | `2` | * `current.next = current.next.next` so `2 -> 4` <br> * `prev = 2` <br> * `current = next_node = 3` |
| 3 | `2` | `3` | `4` | `3` | * `current.next = current.next.next` so `3 -> 5` <br> * `prev = 3` <br> * `current = next_node = 4` |
| 4 | `3` | `4` | `5` | `4` | * `current.next = current.next.next` so `4 -> None` <br> * `prev = 4` <br> * `current = next_node = 5` |
| 5 | `4` | `5` | `None` | `5` | Not executed since `current.next` is `None` |

</center>

The `length` is currently $n - 1$, so we need to increment it by $1$ to get the total number of nodes in the linked list.

At this point, we have two disconnected linked lists:

1. `head -> 1 -> 3 -> (current = 5) -> None`
2. `(first_even_node = 2) -> 4 -> None`

Connect the last node of the odd linked list to the first node of the even linked list, `current.next = first_even_node`, to get the final linked list: `head -> 1 -> 3 -> 5 -> 2 -> 4 -> None`.

### Even Number of Nodes

Consider the linked list `head -> 1 -> 2 -> 3 -> 4 -> None`. The odd-even linked list should look like `head -> 1 -> 3 -> 2 -> 4 -> None`.

<center>

| Iteration | `prev` | `current` | `current.next` | `length` | Action |
| --- | --- | --- | --- | --- | --- |
| 1 | `head` | `1` | `2` | `1` | * `current.next = current.next.next` so `1 -> 3` <br> * `prev = 1` <br> * `current = next_node = 2` |
| 2 | `1` | `2` | `3` | `2` | * `current.next = current.next.next` so `2 -> None` <br> * `prev = 2` <br> * `current = next_node = 3` |
| 3 | `2` | `3` | `4` | `3` | * `current.next = current.next.next` so `3 -> None` <br> * `prev = 3` <br> * `current = next_node = 4` |
| 4 | `3` | `4` | `None` | `4` | Not executed since `current.next` is `None` |

</center>

After the loop, increment the `length` by $1$.

Again, we have two disconnected linked lists, and the only difference is that the `prev` instead of the `current` pointer points to the last node of the odd linked list:

1. `head -> 1 -> (prev = 3) -> None`
2. `(first_even_node = 2) -> 4 -> None`

We connect the two linked lists via `prev.next = first_even_node` to get the final linked list: `head -> 1 -> 3 -> 2 -> 4 -> None`.

## Time Complexity

Each node is visited once, so the time complexity of this algorithm is $O(n)$, where $n$ is the number of nodes in the linked list. All operations inside the `while` loop can be considered $O(1)$.

## Space Complexity

This algorithm modifies the input linked list in-place, so the space complexity is $O(1)$. The only space used are for the pointers `prev`, `current`, and `first_even_node` as well as the `length` variable.
