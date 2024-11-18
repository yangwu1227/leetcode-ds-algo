from node import ListNode
from singly import SinglyLinkedList


def pair_sum(head: ListNode) -> int:
    """
    Given the `head` of a linked list with even length, return the maximum twin sum of the linked list.

    Parameters
    ----------
    head : ListNode
        The sentinel head of the linked list

    Returns
    -------
    int
        The maximum twin sum
    """
    # Two node case
    if head.next.next.next is None:
        return head.next.data + head.next.next.data

    # Find middle: head -> a -> b -> [c] -> d -> e -> f
    fast = head
    slow = head
    length = 0
    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next
        length += 1
    # Get the full length
    length *= 2

    # Reverse the second half of the list to head -> a -> b -> c -> f -> e -> d
    prev = None
    last_node_second_half = fast
    last_node_first_half = slow
    current = slow.next
    while current:
        # Keep a reference to the next node
        next_node = current.next
        # Reverse the direction
        current.next = prev
        # The current node should now be considered the previous node
        prev = current
        # Keep the loop going
        current = next_node
    # To connect the first and reversed second half
    last_node_first_half.next = last_node_second_half

    # All pairs are (length / 2) steps apart: [a + f], [b + e], [c + d]
    fast = head
    slow = head
    # Move fast (length / 2) steps head
    for _ in range(length // 2):
        fast = fast.next
    max_sum = 0
    while fast and fast.next:
        # Since slow and fast are initialized to sentinal head, add their next nodes
        max_sum = max(slow.next.data + fast.next.data, max_sum)
        fast = fast.next
        slow = slow.next

    return max_sum


def main() -> int:
    data_arrays = [[5, 4, 2, 1], [4, 2, 2, 3], [1, 2], [7, 12, 27, 17, 77, 27]]
    for data_array in data_arrays:
        nodes = (ListNode(data=data) for data in data_array)
        sll = SinglyLinkedList()
        for node in nodes:
            sll.add_to_end(node)

        print("Before reversing")
        sll.display()
        max_sum = pair_sum(sll.head)
        print("After reversing")
        sll.display()
        print(f"The maximum twin sum is {max_sum}")
        print("\n")

    return 0


if __name__ == "__main__":
    main()
