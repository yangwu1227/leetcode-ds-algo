from node import ListNode
from singly import SinglyLinkedList

def remove_duplicates(head: ListNode) -> ListNode:
    """
    Given the `head` of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 

    Parameters
    ----------
    head : ListNode
        The sentinel head of the singly linked list

    Returns
    -------
    ListNode
        The sentinel head of the sorted list with unique elements only
    """
    # Empty or single node
    if head.next is None:
        return head
    if head.next.next is None:
        return head

    # Fast is initialized to point to the second real node
    fast = head.next
    # Slow is initialized to point to the first read node
    slow = head

    while fast:
        # Move fast to the end of duplicates
        while fast.next and fast.data == fast.next.data:
            fast = fast.next
        
        # Check if slow.next is fast 
        if slow.next == fast:
            # If it is, this means that fast has not skipped any nodes due to duplicates as it is one step ahead of slow
            slow = slow.next
        else:
            # If fast is more than one step ahead of slow, duplicates were detected, skip all duplicates by moving slow directly to fast.next
            slow.next = fast.next
        
        # The fast pointer will now point to the next distinct node
        fast = fast.next

    return head

def main() -> int:

    test_cases = [(1, 1, 1, 2, 3, 3, 4), (1, 1, 1, 2, 3), [1], [1, 2, 3, 3, 4, 4, 5], [1, 1, 1]]

    for data_array in test_cases:
        nodes = (ListNode(data=data) for data in data_array)
        sll = SinglyLinkedList()
        for node in nodes:
            sll.add_to_end(node)
        print("Before removing all duplicates")
        sll.display()
        distinct_head = remove_duplicates(sll.head)
        print("After removing all duplicates")
        sll.display()
        print('\n')
    
    return 0

if __name__ == "__main__":

    main()
