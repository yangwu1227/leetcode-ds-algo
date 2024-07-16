from node import ListNode 
from singly import SinglyLinkedList

def get_decimal(head: ListNode) -> int:
    """
    Given the `head` of a singly-linked list, the value of each node in the linked list is either 0 or 1. 
    The list holds the binary (base 2) representation of a decimal (base 10) number.

    Parameters
    ----------
    head : ListNode
        The sentinel head of the linked list

    Returns
    -------
    int
        The decimal value of the number
    """
    decimal_value = 0
    current = head.next 
    while current:
        # Left shift by one bit and bitwise or to append the next binary digit
        decimal_value = (decimal_value << 1) | current.data
        current = current.next
    return decimal_value

def main() -> int:

    data_arrays = [[1, 0, 1], [1, 0, 0, 0, 1], [0], [1, 0]]
    for data_array in data_arrays:
        nodes = (ListNode(data=data) for data in data_array)
        sll = SinglyLinkedList()
        for node in nodes:
            sll.add_to_end(node)
        
        print(f"Binary representation:")
        sll.display()
        decimal_value = get_decimal(sll.head)
        print(f"Decimal value: {decimal_value}")
        print('\n')

    return 0

if __name__ == "__main__":

    main()
