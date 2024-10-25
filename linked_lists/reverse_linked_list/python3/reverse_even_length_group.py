from typing import Optional

from node import ListNode
from singly import SinglyLinkedList


def reverse_group(start_node: ListNode, group_length: int) -> Optional[ListNode]:
    """
    Reverses the first `group_length` nodes of the linked list starting from `start_node`.

    Parameters
    ----------
    start_node : ListNode
        The starting node of the group to be reversed
    group_length : int
        The number of nodes to be reversed

    Returns
    -------
    ListNode
        The new first node of the reversed group
    """
    prev = None
    current = start_node
    # Let group_length = 3 and the current group is: (start_node = current = current_group_a) -> current_group_b -> current_group_c -> next_group_a -> ...
    while group_length > 0:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
        group_length -= 1

    # Connect current and next group: (prev = current_group_c) -> current_group_b -> (start_node = current_group_a) -> (current = next_group_a) -> ...
    start_node.next = current
    # Return the new first node of the current group, so we can connect the last node of the previous group to this node
    return prev 

def reverse_even_length_group(head: ListNode) -> ListNode:
    """
    Given the `head` of a singly linked list, where the nodes are sequentially associated to non-empty groups whose lengths from the sequence of natural numbers
    (1, 2, 3, 4, ...), reverse the nodes in each group with an even length.

    Parameters
    ----------
    head : ListNode
        The sentinel head of the linked list

    Returns
    -------
    ListNode
        The sentinel head of the modified linked list
    """
    # Single node
    if head.next.next is None:
        return head
    # Two nodes
    if head.next.next.next is None:
        return head
    
    # Initialize pointers to sentinel head and first real node
    last_node_prev_group = head 
    current = head.next 
    expected_group_length = 1
    while current:
        # Determine the actual length of the current group
        actual_group_length = 0
        # Keep a reference to the start of the current group, so we can pass it to reverse_group later
        start_node = current
        while current and actual_group_length < expected_group_length:
            current = current.next
            actual_group_length += 1

        # If the actual group length is even, reverse the group
        if actual_group_length % 2 == 0:
            # Connect the previous group to the new first node of the current group (which has been reversed)
            last_node_prev_group.next = reverse_group(start_node=start_node, group_length=actual_group_length) 

        # Move the last_node_prev_group pointer to the end of the current group
        for _ in range(actual_group_length):
            last_node_prev_group = last_node_prev_group.next
        # Iterate to the next group length in 1, 2, 3, ...
        expected_group_length += 1

    return head

def main() -> int:

    data_arrays = [[5, 2, 6, 3, 9, 1, 7, 3, 8, 4], [5, 2], [1], [1, 1, 0, 6, 5]]
    for data_array in data_arrays:
        nodes = (ListNode(data=data) for data in data_array)
        sll = SinglyLinkedList()
        for node in nodes:
            sll.add_to_end(node)
        
        print("Before reversing")
        sll.display()
        new_head = reverse_even_length_group(sll.head)
        print("After reversing")
        sll.display()
        print('\n')

    return 0

if __name__ == "__main__":

    main()
