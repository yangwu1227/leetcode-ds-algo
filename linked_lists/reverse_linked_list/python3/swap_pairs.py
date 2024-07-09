from node import ListNode
from singly import SinglyLinkedList

def swap_pairs(head: ListNode) -> ListNode:
    """
    Given a linked list, swap every two adjacent nodes. Only the nodes can be changed and not the values of the nodes.

    Parameters
    ----------
    head : ListNode
        The sentinel head of the linked list

    Returns
    -------
    ListNode
        The sentinel head of the modified linked list
    """
    # Single node or empty list
    if head.next is None:
        return head
    if head.next.next is None:
        return head
    
    prev = head
    # This points to the first real node
    current = head.next

    # Iterate as long as there are at least two nodes to swap
    while current and current.next:

        # Identify the nodes to be swapped: prev -> first -> second -> next_first -> next_second
        first = current
        second = current.next
        
        # Step 1: Link the first node to the node after second: prev -> (first & second) -> next_first -> next_second
        first.next = second.next  
        # Step 2: Link second node to first node: (second & prev) -> first -> next_first -> next_second
        second.next = first       
        # Step 3: Link prev node to second node (completing the swap): prev -> [second -> first] -> next_first -> next_second
        prev.next = second        
        
        # After the swap, update 'prev' to point to the node that was originally the first node in the pair: (prev = first) -> next_first -> next_second
        prev = first
        # Move 'current' so the next iteration starts with a new pair: (prev = first) -> (current = next_first) -> next_second
        current = first.next

    return head

def main() -> int:

    data_arrays = [[1, 2, 3, 4], [], [1], [12, 27, 7, 17, 77]]
    for data_array in data_arrays:
        nodes = (ListNode(data=data) for data in data_array)
        sll = SinglyLinkedList()
        for node in nodes:
            sll.add_to_end(node)
        
        print("Before swapping pairs")
        sll.display()
        new_head = swap_pairs(sll.head)
        print("After swapping pairs")
        sll.display()
        print('\n')

    return 0

if __name__ == "__main__":

    main()
