from node import ListNode
from singly import SinglyLinkedList

def middle_node(head: ListNode) -> ListNode:
    """
    Given the `head` of a singly linked list, return the middle node of the linked list. If there are two middle nodes,
    return the second node.

    Parameters
    ----------
    head : ListNode
        The first real node
    
    Returns
    -------
    ListNode
        The middle node of the linked list
    """
    # Pointers
    slow = head
    fast = head 
    # Iterate the pointers
    while fast and fast.next:
        slow = slow.next 
        fast = fast.next.next
    return slow

def main() -> int:

    test_cases = [[1, 2, 3, 4, 5], [1, 2, 3, 4, 5, 6, 7, 8], [12, 17], [12, 17, 8, 7]]

    for test_case in test_cases:
        sll = SinglyLinkedList()
        nodes = (ListNode(data=data) for data in test_case)
        for node in nodes:
            sll.add_to_end(node_to_add=node)
        middle = middle_node(head=sll.head.next)
        sll.display()
        print(f"The middle node of the above linked list is {middle}\n")

    return 0

if __name__ == "__main__":

    main()
