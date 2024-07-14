from node import ListNode 
from singly import SinglyLinkedList

def remove_elements(head: ListNode, data: int) -> ListNode:
    """
    Given the `head` of a linked list and an integer `date`, remove all the nodes of the linked list that has `ListNode.data == data`.

    Parameters
    ----------
    head : ListNode
        The sentinel head of the linked list

    Returns
    -------
    ListNode
        The sentinel head of the modified linked list
    """
    # Empty list
    if head.next is None:
        return head
    
    # Initialize prev to the sentinel head and current to the first real node
    prev = head
    current = head.next 
    while current:
        if current.data == data:
            # Remove the current node by performing a skip: prev -> [current] -> current.next
            prev.next = current.next
        else:
            # If no match, move the previous pointer
            prev = prev.next 
        # Move the current pointer for next iteration
        current = current.next

    return head

def main() -> int:

    data_arrays = [([1, 2, 6, 3, 4, 5, 6], 6), ([5, 2], 2), ([1], 0), ([7, 7, 7, 7, 7], 7)]
    for data_array, data in data_arrays:
        nodes = (ListNode(data=data) for data in data_array)
        sll = SinglyLinkedList()
        for node in nodes:
            sll.add_to_end(node)
        
        print(f"Before removing {data}")
        sll.display()
        new_head = remove_elements(sll.head, data)
        print(f"After removing {data}")
        sll.display()
        print('\n')

    return 0

if __name__ == "__main__":

    main()
