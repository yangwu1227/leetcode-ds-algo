from collections import deque
from typing import Deque, List, MutableSequence


def daily_temperatures(temperatures: MutableSequence[int]) -> List[int]:
    """
    Given an array of integers `temperatures` representing daily temperatures, return an array `output` where `output[i]` 
    indicates the number of days after the `i`-th day that a warmer temperature occurs. If no such day exists, set `out[i]` to 0.

    Parameters
    ----------
    temperatures : MutableSequence[int]
        A mutable sequence of integers representing temperatures on each day

    Returns
    -------
    List[int]
        A list of integers representing the numbers of elapsed days
    """
    if len(temperatures) == 1:
        return [0]

    output: List[int] = [0] * len(temperatures)
    days_stack: Deque[int] = deque()
    previous_day_index = -1
    for current_day_index, temperature in enumerate(temperatures):
        # As long as stack is non-empty and the current temperature is higher than the top of the stack temperature
        while days_stack and temperature > temperatures[days_stack[-1]]:
            # Pop the top of the stack
            previous_day_index = days_stack.pop()
            # Compute the nubmer of days since 'previous_day_index' before we reached a warmer temperature
            output[previous_day_index] = current_day_index - previous_day_index
        days_stack.append(current_day_index)

    return output

def main() -> int:

    temperatures_data = [
        [73, 74, 75, 71, 69, 72, 76, 73],
        [30, 35, 53, 62, 70, 90],
        [35]
    ]

    for temperatures in temperatures_data:
        output = daily_temperatures(temperatures)
        print(f"Temperatures: {temperatures} | Days until next warmer: {output}")

    return 0

if __name__ == "__main__":

    main()
