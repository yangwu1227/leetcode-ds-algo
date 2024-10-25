from node import ListNode
from singly import SinglyLinkedList


def has_cycle(head: ListNode) -> bool:
    """
    Given `head`, the `head` of a linked list, determine if the linked list has a cycle in it.

    Parameters
    ----------
    head : ListNode
        The head node of the linked list

    Returns
    -------
    bool
        `True` if there is a cycle, `False` otherwise
    """
    slow = head 
    fast = head 

    while fast and fast.next:
        # Iterate first
        fast = fast.next.next 
        slow = slow.next
        # Check if both pointers (names) are bound to the same node
        if fast == slow:
            return True

    # If the while loop finishes, then that means there is no cycle
    return False

def main() -> int:

    sll_1 = SinglyLinkedList()
    nodes = [ListNode(i) for i in [3, 2, 0, -4]]
    for node in nodes:
        sll_1.add_to_end(node)
    # Add cycle
    sll_1.add_to_end(nodes[1])

    sll_2 = SinglyLinkedList()
    nodes = [ListNode(i) for i in range(3)]
    for node in nodes:
        sll_2.add_to_end(node)

    for sll in [sll_1, sll_2]:
        cycle = has_cycle(sll.head)
        print(f"The linked list {'has' if cycle else 'does not have'} a cycle")

    return 0

if __name__ == "__main__":

    main()
