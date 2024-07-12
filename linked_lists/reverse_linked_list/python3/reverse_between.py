from node import ListNode
from singly import SinglyLinkedList

def reverse_between(head: ListNode, left: int, right: int) -> ListNode:
    """
    Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`.

    Parameters
    ----------
    head : ListNode
        The sentinel head of the linked list
    left : int 
        The start of the section of the linked list to be reversed
    right : int
        The end of the section of the linked list to be reversed

    Returns
    -------
    ListNode
        The sentinel head of the modified linked list
    """
    # Single node case
    if head.next.next is None:
        return head
    # Special case where left = right
    if left == right:
        return head

    current = head
    # Let left = 3 and right = 5, move 'current' to the node right before 'left': head -> 1 -> [2] -> 3 -> 4 -> 5 -> 6 -> 7
    for _ in range(left - 1):
        current = current.next
    
    # At this point, 'current' is at 2, keep reference before moving it to 'left' which is 3
    node_before_left = current
    # Set current = left_node = 3 
    current = current.next
    left_node = current
    prev = None

    # Reverse the nodes from 'left' to 'right'
    for _ in range(right - left + 1):
        next_node = current.next 
        current.next = prev 
        prev = current
        current = next_node
        
    # Pointer 'prev' now points to right_node = 5, so set the next pointer of (node_before_left = 2) -> (prev = 5) -> 4 -> (left_node = 3) -> None
    node_before_left.next = prev
    # Also, 'current' now points to (node_after_right = current = 6), so set the next pointer of (left_node = 3) -> (current = node_after_right = 6)
    left_node.next = current

    return head

def main() -> int:

    data_arrays= [(range(1, 7), 2, 4), ([5], 1, 1), (range(1, 12), 5, 10), (range(12, 20), 3, 5), (range(2, 7), 4, 4)]
    for data_array, left, right in data_arrays:
        nodes = (ListNode(data=data) for data in data_array)
        sll = SinglyLinkedList()
        for node in nodes:
            sll.add_to_end(node)
        
        print("Before reversing")
        sll.display()
        new_head = reverse_between(sll.head, left, right)
        print(f"After reversing between node = {left} and node = {right}")
        sll.display()
        print('\n')

    return 0

if __name__ == "__main__":

    main()
