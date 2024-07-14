from node import ListNode

class DoublyLinkedList(object):
    def __init__(self):
        """
        Initializes an empty doubly linked list with sentinel head and tail nodes.
        """
        self.head: ListNode = ListNode(None) # Sentinel node
        self.tail: ListNode = ListNode(None) # Sentinel node
        self.head.next = self.tail # The next pointer of the head points to the tail
        self.tail.prev = self.head # The prev pointer of the tail points to the head

    def add_to_end(self, node_to_add: ListNode) -> None:
        """
        Adds a node to the end of the doubly linked list.

        Parameters
        ----------
        node_to_add : ListNode
            The node to be added to the end of the list.
        """
        node_to_add.next = self.tail
        node_to_add.prev = self.tail.prev
        self.tail.prev.next = node_to_add
        self.tail.prev = node_to_add

    def remove_from_end(self) -> None:
        """
        Removes a node from the end of the doubly linked list.
        """
        # If the linked list is empty
        if self.head.next == self.tail:
            return None

        node_to_remove = self.tail.prev
        node_to_remove.prev.next = self.tail
        self.tail.prev = node_to_remove.prev

    def add_to_start(self, node_to_add: ListNode) -> None:
        """
        Adds a node to the start of the doubly linked list.

        Parameters
        ----------
        node_to_add : ListNode
            The node to be added to the start of the list.
        """
        node_to_add.prev = self.head
        node_to_add.next = self.head.next 
        self.head.next.prev = node_to_add
        self.head.next = node_to_add

    def remove_from_start(self) -> None:
        """
        Removes a node from the start of the doubly linked list.
        """
        # If the linked list is empty
        if self.head.next == self.tail:
            return None

        node_to_remove = self.head.next
        node_to_remove.next.prev = self.head
        self.head.next = node_to_remove.next

    def display(self) -> None:
        """
        Displays the values in the linked list from start to end.
        """
        # Start with the first real node (the node after the head sentinel)
        current = self.head.next
        while current != self.tail:
            # Continue until the tail sentinel is reached
            print(current.data, end=" -> ")
            # Print the value of the current node followed by an arrow
            current = current.next
        print("None")

def main() -> int:

    dll = DoublyLinkedList()
    nodes = [ListNode(i) for i in range(1, 6)]

    for node in nodes:
        print(f"Adding {node} to the end")
        dll.add_to_end(node)

    print("Current state of the doubly linked list: ")
    dll.display()

    print("Removing the first node")
    dll.remove_from_start()
    dll.display() 

    print("Removing the last node")
    dll.remove_from_end()
    dll.display() 

    print("Adding a new node to the start")
    dll.add_to_start(node_to_add=ListNode(23))
    dll.display()

    return 0

if __name__ == "__main__":

    main()
