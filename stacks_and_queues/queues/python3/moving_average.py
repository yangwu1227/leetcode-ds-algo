from collections import deque
from typing import Deque

from numpy.random import randint


class MovingAverage(object):
    """
    A class to calculate the moving average of a data stream. 
    """
    def __init__(self, window_size: int) -> None:
        """
        Initialize the MovingAverage instance.

        Parameters
        ----------
        window_size : int
            The size of the moving window
        """
        self.window_size: int = window_size 
        self.data_stream: Deque[int] = deque()
        self.running_sum: float = 0.0
    
    def next(self, val: int) -> float:
        """
        Adds a new value to the data stream and returns the current moving average.

        Parameters
        ----------
        val : int
            The new value to add to the data stream

        Returns
        -------
        float
            The current moving average of the data stream
        """
        # If the length of the data stream is up to the window size capacity, subtract the first value of the queue from the running sum
        if len(self.data_stream) == self.window_size:
            self.running_sum -= self.data_stream.popleft()
        # Add the next data value to the stream and add to the running sum
        self.data_stream.append(val)
        self.running_sum += val
        return self.running_sum / len(self.data_stream)

def main() -> int:

    window_size = randint(low=1, high=6, size=1)[0]
    moving_average = MovingAverage(window_size=window_size)
    for _ in range(12):
        val = randint(low=-10**5, high=10**5)
        print(f"The moving average is the current window of size = {window_size} is {moving_average.next(val)}")

    return 0

if __name__ == "__main__":

    main()
