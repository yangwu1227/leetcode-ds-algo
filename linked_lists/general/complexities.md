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
