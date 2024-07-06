from node import ListNode
from singly import SinglyLinkedList

def delete_middle_node(head: ListNode) -> ListNode:
    """
    Given the `head` of a singly linked list, delete the middle node.

    Parameters
    ----------
    head : ListNode
        The sentinel head of the linked list

    Returns
    -------
    ListNode
        The sentinel head of the modified linked list with the middle node removed
    """
    # Handle single node (i.e., if the first real node is the only node)
    if head.next.next is None:
        # Set the first real node after the sentinel head to None to remove it
        head.next = None
        return head
    
    # Initialize pointers to the first real node
    slow, fast, prev = head.next, head.next, head.next

    while fast and fast.next:
        fast = fast.next.next
        # Previous points to the node right before slow
        prev = slow
        slow = slow.next

    # Slow points to the middl node and prev points to the node before it, remove slow
    prev.next = slow.next

    return head

def main() -> int:

    test_cases = [[1, 3, 4, 7, 1, 2, 6], [1, 2, 3, 4], [2, 1], [1]]

    for data_array in test_cases:
        nodes = (ListNode(data=data) for data in data_array)
        sll = SinglyLinkedList()
        for node in nodes:
            sll.add_to_end(node)
        print("Before removing the middle node:")
        sll.display()
        head = delete_middle_node(sll.head)
        print("After removing the middle node:")
        sll.display()
        print('\n')

    return 0

if __name__ == "__main__":

    main()
