from node import ListNode
from numpy.random import randint
from singly import SinglyLinkedList


def reverse(head: ListNode) -> ListNode:
    """
    Given the sentinel head of the node, reverse the linked list.

    Parameters
    ----------
    head : ListNode
        The sentinel head of the linked list

    Returns
    -------
    ListNode
        The sentinel head of the reversed linked list
    """
    prev = None
    # Set this to the first real node
    current = head.next
    while current:
        # Keep a reference to the next node
        next_node = current.next
        # The current node should now point to the previous node
        current.next = prev
        # The current node should now be considered the previous node
        prev = current
        # To continue with the loop, the current pointer should now point to the original next node
        current = next_node

    # The original head now points to the new first node
    head.next = prev
    return head


def main() -> int:
    for _ in range(5):
        size = randint(low=0, high=7, size=1)
        data_array = randint(low=0, high=5000, size=size)
        nodes = (ListNode(data=data) for data in data_array)
        original_sll = SinglyLinkedList()
        for node in nodes:
            original_sll.add_to_end(node)

        print("Before reversing")
        original_sll.display()
        reversed_head = reverse(original_sll.head)
        print("After reversing")
        original_sll.display()
        print("\n")

    return 0


if __name__ == "__main__":
    main()
