from collections.abc import MutableSequence
from array import array
from sys import maxsize
from reprlib import Repr
from numpy.random import choice
from random import uniform, randint

repr_instance = Repr()
repr_instance.maxdeque = 4

class MinStack(object):
    """
    MinStack is a stack data structure that supports push, pop, top, and retrieving the minimum element in constant time.
    """
    # Default type code for 4-byte signed integer
    default_type_code: str = 'l'

    def __init__(self, type_code: str = default_type_code) -> None:
        """
        Initializes the MinStack instance.

        Parameters
        ----------
        type_code : str, optional
            The type code of the elements in the stack; default is 'l' for 4-byte signed integers; 
            use 'd' for double precision floating point numbers
        """
        self.type_code = type_code 
        self._data_array: MutableSequence = array(self.type_code)
        self._min_array: MutableSequence = array(self.type_code, [maxsize if self.type_code == 'l' else float('inf')])

    @property
    def type_code(self) -> str:
        return self._type_code

    @type_code.setter
    def type_code(self, type_code: str) -> None:
        if not isinstance(type_code, str) or type_code not in ('d', 'l'):
            raise TypeError("The type code must be a string and either 'd' (for 8-byte double precision float) or 'l' (for 4-byte signed integers)")
        self._type_code = type_code

    def __repr__(self) -> str:
        """
        Returns a string representation of the min stack.

        Returns
        -------
        str
            The string representation of the min stack.
        """
        str_repr = repr_instance.repr(self._data_array)
        str_repr = str_repr[str_repr.find('['):-1]
        return f'MinStack({str_repr}])'

    def push(self, val) -> None:
        """
        Pushes an element onto the stack.

        Parameters
        ----------
        val : int or float
            The value to push onto the stack
        """
        self._data_array.append(val)
        self._min_array.append(min(val, self._min_array[-1]))

    def pop(self) -> None:
        """
        Removes the element on the top of the stack.
        """
        self._data_array.pop(-1)
        self._min_array.pop(-1)
        
    def top(self):
        """
        Gets the top element of the stack.

        Returns
        -------
        int or float
            The top element of the stack
        """
        return self._data_array[-1]

    def get_min(self):
        """
        Retrieves the minimum element in the stack.

        Returns
        -------
        int or float
            The minimum element in the stack
        """
        return self._min_array[-1]

def main() -> int:

    num_elements = 4
    type_code = choice(['d', 'l'])[0]
    min_stack = MinStack(type_code=type_code)
    for _ in range(num_elements):
        random_val = uniform(0, 1000) if type_code == 'd' else randint(0, 1000)
        min_stack.push(random_val)
    print(f"Min stack after pushing {num_elements} random numbers: {min_stack}")
    print(f"Top of the stack: {min_stack.top()}")
    print(f"Minimum element in the stack: {min_stack.get_min()}")
    min_stack.pop()
    print(f"Min stack after popping the top element: {min_stack}")
    print(f"Top of the stack: {min_stack.top()}")
    print(f"Minimum element in the stack: {min_stack.get_min()}")   
    min_stack.pop()
    print(f"Min stack after popping the top element: {min_stack}")
    print(f"Top of the stack: {min_stack.top()}")
    print(f"Minimum element in the stack: {min_stack.get_min()}")
    print('\n')

    return 0

if __name__ == "__main__":

    main()
