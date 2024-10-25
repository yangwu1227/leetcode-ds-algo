from collections import deque
from typing import Deque


class Stack(object):
    """
    A class representing a stack using a deque for efficient LIFO opertions.
    """
    def __init__(self) -> None:
        """
        Initialize the Stack instance.
        """
        self.internal_deque: Deque[int] = deque()

    def __repr__(self) -> str:
        """
        Returns a string representation of the stack.

        Returns
        -------
        str
            The string representation of the stack
        """
        str_repr = str(self.internal_deque)
        str_repr = str_repr[str_repr.find('['):-1]
        return f'Stack({str_repr})'

    def push(self, x: int) -> None:
        """
        Push an integer `x` onto the stack.

        Parameters
        ----------
        x : int
            The integer to be pushed onto the stack

        Returns
        -------
        None
        """
        self.internal_deque.append(x)

    def pop(self) -> int:
        """
        Remove and return the top element of the stack.

        Returns
        -------
        int
            The top element of the stack

        Raises
        ------
        IndexError
            If the stack is empty
        """
        if self.internal_deque:
            return self.internal_deque.pop()
        else:
            raise IndexError('Stack is empty')

    def top(self) -> int:
        """
        Return the top element of the stack without removing it.

        Returns
        -------
        int
            The top element of the stack

        Raises
        ------
        IndexError
            If the stack is empty
        """
        if self.internal_deque:
            return self.internal_deque[-1]
        else:
            raise IndexError('Stack is empty')

    @property 
    def empty(self) -> bool:
        """
        Check if the stack is empty.

        Returns
        -------
        bool
            `True` if the stack is empty, `False` otherwise
        """
        return len(self.internal_deque) == 0

def main() -> int:
    
    stack = Stack()
    num_elements = randint(0, 100)
    # Push random integers onto the stack
    for _ in range(num_elements):
        random_int = randint(0, 1000)
        stack.push(random_int)
    print(f"Stack after pushing {num_elements} random integers: {stack}")
    print(f"Popping the top of the stack: {stack.pop()}")
    print(f"Stack after popping the top: {stack}")
    print(f"Get the top of the stack: {stack.top()}")
    print(f"Check if the stack is empty: {stack.empty}")
    print("Popping all elements from the stack")
    while not stack.empty:
        stack.pop()
    print(f"Check if the stack is empty: {stack.empty}")

    return 0

if __name__ == "__main__":

    from random import randint

    main()
