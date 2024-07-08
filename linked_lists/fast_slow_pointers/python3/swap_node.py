from node import ListNode
from singly import SinglyLinkedList

def swap_node(head: ListNode, k: int) -> ListNode:
    """
    Given the `head` node of a linked list and an integer `k`, swap the values of the `kth` node from the start and the `kth` node from the end.

    Parameters
    ----------
    head : ListNode
        The sentinel head of the linked list
    k : int
        The index of the node for swapping the data values

    Returns
    -------
    ListNode 
        The sentinel head of the modified linked list
    """
    # Single node case
    if head.next.next is None:
        return head
    
    # Fast is used to move k steps ahead
    fast = head 
    slow = head 
    for _ in range(k):
        fast = fast.next 

    # Keep a reference to the kth node from the start
    kth_from_start = fast
    while fast:
        slow = slow.next 
        fast = fast.next

    # Swap the data values
    kth_from_start.data, slow.data = slow.data, kth_from_start.data 

    return head

def main() -> int:

    test_cases = [([1, 2, 3, 4, 5], 2), ([7, 9, 6, 6, 7, 8, 3, 0, 9, 5], 5), ([7], 1)]
    for data_array, k in test_cases:
        nodes = (ListNode(data=data) for data in data_array)
        sll = SinglyLinkedList()
        for node in nodes:
            sll.add_to_end(node)
        
        print(f"Before swapping data values betweem the k = {k} nodes from the start and end")
        sll.display()
        new_head = swap_node(sll.head, k)
        print("After swapping data values")
        sll.display()
        print('\n')

    return 0
    
if __name__ == "__main__":

    main()
