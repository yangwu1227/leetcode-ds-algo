from node import ListNode


class SinglyLinkedList(object):
    def __init__(self) -> None:
        """
        Initializes an empty singly linked list with a sentinel head node.
        """
        self.head: ListNode = ListNode(None)  # Sentinel node
        self.tail: ListNode = self.head  # At the beginning, head and tail are the same

    def add_to_end(self, node_to_add: ListNode) -> None:
        """
        Adds a node to the end of the singly linked list.

        Parameters
        ----------
        node_to_add : ListNode
            The node to be added to the end of the list.
        """
        self.tail.next = node_to_add
        self.tail = node_to_add

    def remove_from_end(self) -> None:
        """
        Removes a node from the end of the singly linked list.
        """
        if self.head.next is None:
            # The list is empty
            return None

        # If the list has only one element
        if self.head.next == self.tail:
            self.head.next = None
            self.tail = self.head
            return None

        current = self.head
        while current.next != self.tail:
            current = current.next

        current.next = None
        self.tail = current

    def add_to_start(self, node_to_add: ListNode) -> None:
        """
        Adds a node to the start of the singly linked list.

        Parameters
        ----------
        node_to_add : ListNode
            The node to be added to the start of the list.
        """
        node_to_add.next = self.head.next
        self.head.next = node_to_add

        # If the list was empty, update the tail
        if self.tail == self.head:
            self.tail = node_to_add

    def remove_from_start(self) -> None:
        """
        Removes a node from the start of the singly linked list.
        """
        if self.head.next is None:
            # The list is empty
            return None

        node_to_remove = self.head.next
        self.head.next = node_to_remove.next

        # If the list becomes empty after removal, update the tail
        if self.head.next is None:
            self.tail = self.head

    def add_at_index(self, index: int, node_to_add: ListNode) -> None:
        """
        Adds a node at a specific index in the singly linked list.

        Parameters
        ----------
        index : int
            The index at which the node should be added.
        node_to_add : ListNode
            The node to be added to the list.
        """
        if index < 0:
            raise IndexError("Index must be non-negative")

        current = self.head
        current_index = 0

        while current is not None and current_index < index:
            current = current.next
            current_index += 1

        if current is None:
            raise IndexError("Index out of bounds")

        node_to_add.next = current.next
        current.next = node_to_add

        # If added at the end, update the tail
        if node_to_add.next is None:
            self.tail = node_to_add

    def remove_at_index(self, index: int) -> None:
        """
        Removes a node at a specific index in the singly linked list.

        Parameters
        ----------
        index : int
            The index of the node to be removed.
        """
        if index < 0:
            raise IndexError("Index must be non-negative")

        current = self.head
        current_index = 0

        while current.next is not None and current_index < index:
            current = current.next
            current_index += 1

        if current.next is None:
            raise IndexError("Index out of bounds")

        node_to_remove = current.next
        current.next = node_to_remove.next

        # If removed the tail, update the tail
        if node_to_remove == self.tail:
            self.tail = current

    def display(self) -> None:
        """
        Displays the values in the linked list from start to end.
        """
        current = self.head.next
        while current is not None:
            print(current.data, end=" -> ")
            current = current.next
        print("None")


def main() -> int:
    sll = SinglyLinkedList()
    nodes = [ListNode(i) for i in range(1, 6)]

    for node in nodes:
        print(f"Adding {node} to the end")
        sll.add_to_end(node)

    print("Current state of the singly linked list: ")
    sll.display()

    print("Removing the first node")
    sll.remove_from_start()
    sll.display()

    print("Removing the last node")
    sll.remove_from_end()
    sll.display()

    print("Adding a new node to the start")
    sll.add_to_start(node_to_add=ListNode(9))
    sll.display()

    print("Adding a new node at index 2")
    sll.add_at_index(2, ListNode(99))
    sll.display()

    print("Removing a node at index 2")
    sll.remove_at_index(2)
    sll.display()

    return 0


if __name__ == "__main__":
    main()
