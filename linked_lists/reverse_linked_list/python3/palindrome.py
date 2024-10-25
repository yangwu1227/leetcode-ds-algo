from node import ListNode
from singly import SinglyLinkedList


def is_palindrome(head: ListNode) -> bool:
    """
    Given the `head` of a singly linked list, determine if this is a palindrome. 

    Parameters
    ----------
    head : ListNode
        The sentinel head of the linked list

    Returns
    -------
    bool
        `True` if the list is a palindrome and `False` otherwise
    """
    # Single node case
    if head.next.next is None:
        return True
    
    # ------------------------------ Find the middle ----------------------------- #
    
    # Odd case: head -> 1 -> 2 -> [3] -> 2 -> 1
    # Even case: head -> 1 -> [2] -> 2 -> 1
    slow = head 
    fast = head
    fast_prev = head
    slow_prev = head
    length = 0
    while fast and fast.next:
        fast_prev = fast
        fast = fast.next.next
        slow_prev = slow
        slow = slow.next
        length += 1
    # Because we used sentinel nodes, if fast is None, length is odd, if fast is not None, length is even
    # Odd case: head -> 1 -> 2 -> (slow = 3) -> 2 -> 1 -> (fast = None)
    # Even case: head -> 1 -> (slow = 2) -> 2 -> (fast = 1)
    if fast is None:
        length = 2 * length - 1
    else:
        length *= 2

    # ---------------------- Reversing a section of the list --------------------- #

    # Odd case: head -> 1 -> (node_before_reverse = 2) -> [(current = slow = 3) -> (fast_prev = 2) -> (fast_prev.next = last_node = 1)]
    if length % 2 != 0:
        current = slow
        last_node = fast_prev.next 
        node_before_reverse = slow_prev
    # Even case: head -> 1 -> (node_before_reverse = slow = 2) -> [(current = 2) -> (fast = last_node = 1)]
    else:
        current = slow.next
        last_node = fast
        node_before_reverse = slow
    # This pointer is used by the reverse operations during each iteration
    prev = None
    while current:
        next_node = current.next 
        current.next = prev
        prev = current
        current = next_node
    # Odd case: head -> 1 -> (node_before_reverse = 2) -> (fast_prev.next = last_node = 1) -> 2 -> 3
    # Even case: head -> 1 -> (node_before_reverse = slow = 2) -> (fast = last_node = 1) -> 2 
    node_before_reverse.next = last_node

    # ------------------------------- Compare nodes ------------------------------ #

    # All pairs we need to compare are (length // 2) steps apart
    # Odd case: 5 // 2 = 2
    # Even case: 4 // 2 = 2
    fast = head
    slow = head 
    # Move fast (length // 2) steps head
    for _ in range(length // 2):
        fast = fast.next

    # Odd case: head -> 1 -> 2 -> 1 -> 2 -> 3
    # Even case: head -> 1 -> 2 -> 1 -> 2
    while fast and fast.next:
        # If odd, do not carry out the very last comparison, e.g., head -> 1 -> (slow = 2) -> (slow.next = 1) -> (fast = 2) -> (fast.next = 3) -> (fast.next.next = None)
        # The single middle node does not disqualify the list from being a palindrome, as reversing the second would have moved 3 to the end
        if length % 2 != 0 and fast.next.next is None:
            fast = fast.next
            slow = slow.next
            continue
        else:
            # For all other scenarios, do the comparisons
            if slow.next.data != fast.next.data:
                return False
            fast = fast.next
            slow = slow.next
        
    return True

def main() -> int:

    data_arrays = [[1, 2, 2, 3, 2, 2, 1], [1, 2, 3, 4], [1, 2, 2, 1], [1]]
    for data_array in data_arrays:
        nodes = (ListNode(data=data) for data in data_array)
        sll = SinglyLinkedList()
        for node in nodes:
            sll.add_to_end(node)

        print("Before reversing")
        sll.display()
        palindrome = is_palindrome(sll.head)
        print("After reversing")
        sll.display()
        print(f"The linked list {'is' if palindrome else 'is not'} a palindrome")
        print('\n')

    return 0

if __name__ == "__main__":

    main()
