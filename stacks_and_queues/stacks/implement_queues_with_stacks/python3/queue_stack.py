from reprlib import Repr
from typing import List

repr_instance = Repr()
repr_instance.maxdeque = 4


class Queue(object):
    """
    A class representing a queue using two stacks for efficient FIFO operations.
    """

    def __init__(self) -> None:
        """
        Initializes the queue instance.
        """
        self.stack: List[int] = []
        self.stack_reversed: List[int] = []
        self.front: int | None = None

    def push(self, x: int) -> None:
        """
        Push an element to the back of the queue.

        Parameters
        ----------
        x : int
            The element to be added to the queue
        """
        # If self.stack is empty, keep a refence to the front of the queue
        if not self.stack:
            self.front = x
        self.stack.append(x)

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
        # If self.stack_reversed is empty
        if not self.stack_reversed:
            # Keep poping the top of self.stack and pushing each popped element to the top of self.stack_reversed
            while self.stack:
                self.stack_reversed.append(self.stack.pop(-1))
        # Now, the top of self.stack_revesed is the original front of self.stack
        return self.stack_reversed.pop(-1)

    def peek(self) -> int | None:
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
        # If self.stack_reversed is non-empty, its top is the front of the queue
        if self.stack_reversed:
            return self.stack_reversed[-1]
        # If self.stack_reversed is empty, then return self.front, which may be None if the queue is empty
        return self.front

    @property
    def empty(self) -> bool:
        """
        Predicate method that checks if the queue is empty.

        Returns
        -------
        bool
            `True` if the queue is empty, `False` otherwise.
        """
        return len(self.stack) == len(self.stack_reversed) == 0

    def __repr__(self) -> str:
        """
        Returns a string representation of the queue.

        Returns
        -------
        str
            The string representation of the queue
        """
        # Before the first pop operation, self.stack is non-empty, after the first pop operation, self.stack_reversed becomes non-empty
        queue = self.stack if self.stack else self.stack_reversed[::-1]
        str_repr = repr_instance.repr(queue)
        str_repr = str_repr[str_repr.find("[") : -1]
        return f"Queue({str_repr}])"


def main() -> int:
    queue = Queue()
    num_elements = randint(0, 1000)
    for _ in range(num_elements):
        random_int = randint(0, 1000)
        queue.push(random_int)
    print(f"Queue after pushing {num_elements} random integers: {queue}")
    print(f"Popping the front of the queue: {queue.pop()}")
    print(f"Queue after popping the front: {queue}")
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
