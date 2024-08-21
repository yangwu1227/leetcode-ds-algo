from collections import deque, defaultdict
from typing import Deque, MutableMapping
from reprlib import Repr

repr_instance = Repr()
repr_instance.maxdeque = 6

class DataStream(object):
    """
    A class to represent a data stream and evaluate consecutive occurrences of a specific value.
    """
    def __init__(self, value: int, k: int) -> None:
        """
        Initialize the DataStream instance.

        Parameters
        ----------
        value : int
            The target value to monitor in the data stream
        k : int
            The number of consecutive occurrences to check for the target value
        """
        self.value = value
        self.k = k
        self._internal_deque: Deque[int] = deque()
        self._invalid_value_counts: MutableMapping[int, int] = defaultdict(int)

    @property
    def value(self) -> int:
        return self._value
    
    @value.setter
    def value(self, value: int) -> None:
        if not isinstance(value, int):
            raise TypeError('Value must be an integer')
        self._value = value

    @property
    def k(self) -> int:
        return self._k

    @k.setter
    def k(self, k: int) -> None:
        if not isinstance(k, int):
            raise TypeError('K must be an integer')
        self._k = k

    def __repr__(self) -> str:
        str_repr = repr_instance.repr(self._internal_deque)
        str_repr = str_repr[str_repr.find('['):-1]
        return f'DataStream({str_repr}])'
    
    def consec(self, num: int) -> bool:
        """
        Process a number from the stream and check if the last `k` values are equal to the target value.

        Parameters
        ----------
        num : int
            The number to process from the stream

        Returns
        -------
        bool
            `True` if the last `k` values in the stream are equal to the target value, `False` otherwise
        """
        self._internal_deque.append(num)
        n = len(self._internal_deque)
        # If the number does not match the target value, increment its count
        if num != self.value:
            self._invalid_value_counts[num] += 1
        # Return early if not enough numbers has been seen yet
        if n < self.k:
            return False
        if n > self.k:
            popped_value = self._internal_deque.popleft()
            # If the removed value does not match the target value, update its count in the invalid count map
            if popped_value != self.value:
                # If the count of this invalid value is more than 1, simply decrement its count
                if self._invalid_value_counts[popped_value] > 1:
                    self._invalid_value_counts[popped_value] -= 1
                else:
                    # If the count is not above 1, it means this was the last occurrence, so we remove it from the map
                    self._invalid_value_counts.pop(popped_value)
        # If the invalid count map is empty, it indicates the last k numbers all match the target value, so return True
        return not self._invalid_value_counts

def main() -> int:

    data = [((4, 3), [4, 4, 3, 3, 4, 4, 4, 2, 4]), ((1, 2), [1, 2, 1, 1, 1, 2, 2, 1, 1, 2])]
    for (value, k), stream in data:
        print('\nNew data stream')
        data_stream = DataStream(value, k)
        for num in stream:
            print(f"Processing num = {num} in the stream, the last {k} numbers {'do' if data_stream.consec(num) else 'do not'} all match the target = {value}")
            print(data_stream)

    return 0

if __name__ == "__main__":

    main()
