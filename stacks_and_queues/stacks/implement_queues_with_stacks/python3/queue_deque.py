from collections import deque
from reprlib import Repr
from typing import Deque

repr_instance = Repr()
repr_instance.maxdeque = 4

class Queue(object):
    """
    A class representing a queue using a deque for efficient FIFO operations.
    """
    def __init__(self) -> None:
        """
        Initializes the queue instance.
        """
        self.internal_deque: Deque[int] = deque(maxlen=None)

    def push(self, x: int) -> None:
        """
        Push an element to the back of the queue.

        Parameters
        ----------
        x : int
            The element to be added to the queue
        """
        self.internal_deque.append(x)

    def pop(self) -> int:
        """
        Removes and returns the element from the front of the queue.

        Returns
        -------
        int
            The element at the front of the queue

        Raises
        ------
        IndexError
            If the queue is empty
        """
        try:
            return self.internal_deque.popleft()
        except IndexError as error:
            raise IndexError("The queue is empty")

    def peek(self) -> int:
        """
        Returns the element at the front of the queue without removing it.

        Returns
        -------
        int
            The element at the front of the queue

        Raises
        ------
        IndexError
            If the queue is empty
        """
        try:
            return self.internal_deque[0]
        except IndexError as error:
            raise IndexError("Cannot peek in an empty queue")
    
    @property
    def empty(self) -> bool:
        """
        Predicate method that checks if the queue is empty.

        Returns
        -------
        bool
            `True` if the queue is empty, `False` otherwise.
        """
        return len(self.internal_deque) == 0
    
    def __repr__(self) -> str:
        """
        Returns a string representation of the queue.

        Returns
        -------
        str
            The string representation of the queue
        """
        str_repr = repr_instance.repr(self.internal_deque)
        str_repr = str_repr[str_repr.find('['):-1]
        return f'Queue({str_repr}])'
    
def main() -> int:

    queue = Queue()
    num_elements = randint(0, 1000)
    for _ in range(num_elements):
        random_int = randint(0, 1000)
        queue.push(random_int)
    print(f"Queue after pushing {num_elements} random integers: {queue}")
    print(f"Popping the front of the queue: {queue.pop()}")
    print(f"Queue after popping the front: {queue}")
    print(f"Peek the front of the queue: {queue.peek()}")
    print(f"Check if the queue is empty: {queue.empty}")
    print("Popping all elements at the front")
    while not queue.empty:
        queue.pop()
    print(f"Check if the queue is empty: {queue.empty}")

    return 0

if __name__ == "__main__":

    from random import randint

    main()
