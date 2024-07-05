from node import ListNode
from singly import SinglyLinkedList

def kth_node(head: ListNode, k: int) -> ListNode:
    """
    Given `head`, the sentinel head node, of a singly linked list and `k`, return the kth node from the end of the linked list. 

    Parameters
    ----------
    head : ListNode
        The sentinel head node
    k : int
        The index of the node to return

    Returns
    -------
    ListNode
        The kth node of the linked list
    """
    fast = head
    slow = head 
    # Fast forward the fast pointer
    for _ in range(k):
        fast = fast.next
    # Move both pointers at the same speed until the end
    while fast:
        fast = fast.next 
        slow = slow.next

    return slow

def main() -> int:

    test_cases = [([12, 9, 6, 8, 7, 14], 3), ([12, 4, 5, 6, 7, 23, 98, 56, 0, 34, 47, 28], 6), ([9, 7, 12, 7], 2)]

    for data_array, k in test_cases:
        nodes = [ListNode(data=data) for data in data_array]
        sll = SinglyLinkedList()
        for node in nodes:
            sll.add_to_start(node)
        kth = kth_node(sll.head, k)
        sll.display()
        print(f"The k = {k} node of the above linked list from the end is {kth}\n")

    return 0

if __name__ == "__main__":

    main()
