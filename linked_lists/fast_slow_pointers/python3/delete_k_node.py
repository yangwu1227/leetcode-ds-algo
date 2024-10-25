from node import ListNode
from singly import SinglyLinkedList


def delete_k_node(head: ListNode, k: int) -> ListNode:
    """
    Given the `head` of a singly linked list, remove the `kth` node from the end of the list.

    Parameters
    ----------
    head : ListNode
        The sentinel head of the linked list
    k : int
        The node to remove

    Returns
    -------
    ListNode
        The sentinel head of the modified linked list with the kth node from the end removed
    """
    # If the real node after the sentinel head is the only node
    if head.next.next == None:
        # Remove it since it is the only node to remove, assuming k is correctly specified as 1
        head.next = None
        return head 
    
    # Pointers initialized to point to sentinel head
    fast, slow, prev = head, head, head
    
    # Move fast k steps ahead of slow
    for _ in range(k):
        fast = fast.next
    
    # Move fast and slow at the same speed and use prev to track the (k - 1)th node
    while fast:
        fast = fast.next
        # Set previous to slow before iterating slow 
        prev = slow
        slow = slow.next

    # Remove the kth node from the end
    prev.next = slow.next

    return head

def main() -> int:

    test_cases = [([1, 2], 2), ([1, 2], 1), ([1, 2, 3, 4, 5], 2), ([1], 1), ([2, 7, 12, 5, 9, 8, 13, 17], 5)]
    for data_array, k in test_cases:
        nodes = (ListNode(data=data) for data in data_array)
        sll = SinglyLinkedList()
        for node in nodes:
            sll.add_to_end(node)

        print(f"Before removing the k = {k} node from the end")
        sll.display()
        head = delete_k_node(sll.head, k)
        print(f"After removing the k = {k} node from the end")
        sll.display()
        print('\n')

    return 0

if __name__ == "__main__":

    main()
        
