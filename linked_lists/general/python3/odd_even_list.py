from node import ListNode
from singly import SinglyLinkedList


def odd_even_list(head: ListNode) -> ListNode:
    """
    Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices. The first node is considered odd,
    and the second is considered even, and so on.

    Parameters
    ----------
    head : ListNode
        The sentinel head of the singly linked list

    Returns
    -------
    ListNode
        The sentinel head of the modified linked list
    """
    # Empty case
    if head.next is None:
        return head
    # Single node case or two nodes
    if head.next.next is None or head.next.next.next is None:
        return head 
    
    prev = head 
    current = head.next 
    # Keep a reference to the second node, first node of the even section
    first_even_node = head.next.next
    length = 0
    while current.next:
        # Keep a reference to the next node
        next_node = current.next
        # Skip a node to connect odd with odd and even with even
        current.next = current.next.next
        prev = current
        # Iteraterate and increment length
        current = next_node
        length += 1
    # When the loop finishes, length = (n - 1) since the last node is not counted due to the current.next condition
    length += 1

    # If length is odd, then current is pointing at the last odd node
    if length % 2 != 0:
        current.next = first_even_node
    else:
        # If length is even, then prev is pointing at the last odd node
        prev.next = first_even_node
    
    return head

def main() -> int:

    data_arrays = [range(1, 5), range(1, 10), [1], [12, 27]]
    for data_array in data_arrays:
        nodes = (ListNode(data=data) for data in data_array)
        sll = SinglyLinkedList()
        for node in nodes:
            sll.add_to_end(node)
        
        print(f"Before reordering")
        sll.display()
        new_head = odd_even_list(sll.head)
        print(f"After reordering")
        sll.display()
        print('\n')

    return 0

if __name__ == "__main__":

    main()
