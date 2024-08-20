from collections import deque 
from typing import Deque, MutableSequence

def max_bugdet(charge_times: MutableSequence[int], running_costs: MutableSequence, budget: int) -> int:
    """
    Calculate the maximum number of machines that can be run simultaneously without exceeding the budget.

    Parameters
    ----------
    charge_times : MutableSequence[int]
        A mutable sequence of integers where each element represents the charge time of a machine
    running_costs : MutableSequence[int]
        A mutable sequence of integers where each element represents the running cost of a machine
    budget : int
        The maximum allowed budget for running the machines

    Returns
    -------
    int
        The maximum number of machines that can be run simultaneously without exceeding the budget
    """
    n = len(charge_times)
    if n == 1:
        return 0 if charge_times[0] + running_costs[0] > budget else 1

    k = max_window_size = sum_running_cost = left = 0
    monotonic_nonincreasing_deque: Deque[int] = deque()
    for right in range(n):
        # Maintain the deque as a monotonically non-increasing sequence of indices
        print(f"Processing index charge_times[{right}] = {charge_times[right]} and running_costs[{right}] = {running_costs[right]}")
        print("Deque is empty") if not monotonic_nonincreasing_deque else print(f"Deque is non-empty and (back of the deque charge time: {charge_times[monotonic_nonincreasing_deque[-1]]}) < (current charge time: {charge_times[right]})? {charge_times[monotonic_nonincreasing_deque[-1]] < charge_times[right]}")
        while monotonic_nonincreasing_deque and charge_times[monotonic_nonincreasing_deque[-1]] < charge_times[right]:
            print(f"  Popping index {monotonic_nonincreasing_deque[-1]} since (back of the deque charge time: {charge_times[monotonic_nonincreasing_deque[-1]]}) < (current charge time: {charge_times[right]})")
            monotonic_nonincreasing_deque.pop()
        monotonic_nonincreasing_deque.append(right)
        print(f"Deque - Indices: {monotonic_nonincreasing_deque} - Charge times: {[charge_times[i] for i in monotonic_nonincreasing_deque]}")
        print(f"Sum of running costs = {sum_running_cost + running_costs[right]} | k = {k + 1}")
        sum_running_cost += running_costs[right]
        k += 1
        print("Deque is empty") if not monotonic_nonincreasing_deque else print(f"Deque is non-empty and (total = {(charge_times[monotonic_nonincreasing_deque[0]] + k * sum_running_cost)}) >= (budget = {budget})")
        while monotonic_nonincreasing_deque and (charge_times[monotonic_nonincreasing_deque[0]] + k * sum_running_cost) > budget:
            print(f"  Shrink current window since (total = {(charge_times[monotonic_nonincreasing_deque[0]] + k * sum_running_cost)}) >= (budget = {budget})")
            print(f"  The front of the deque is no longer in the window, pop index {monotonic_nonincreasing_deque[0]}") if monotonic_nonincreasing_deque[0] == left else print(f"  The front of the deque index {monotonic_nonincreasing_deque[0]} is still in the window, no pop")
            if monotonic_nonincreasing_deque[0] == left:
                monotonic_nonincreasing_deque.popleft()
            print(f"  Sum of running costs minus {running_costs[left]} = {sum_running_cost - running_costs[left]} | k = {k - 1} | left = {left + 1}")
            sum_running_cost -= running_costs[left]
            k -= 1
            left += 1
        max_window_size = max(max_window_size, right - left + 1)
        print(f"Update max window size = {max_window_size}")
    return max_window_size

def main() -> int:

    data = [
        ([11, 12, 19], [10, 8, 7], 19),
        ([3, 6, 1, 3, 4], [2, 1, 3, 4, 5], 25),
        ([2], [7], 12),
        ([17, 12, 12, 2, 1], [12, 5, 2, 9, 2], 1000)
    ]
    for charge_times, running_costs, budget in data:
        max_machines = max_bugdet(charge_times, running_costs, budget)
        print(f"Charge times = {charge_times} | Running costs = {running_costs} | budget = {budget} ---> Max machine(s) = {max_machines}\n")

    return 0

if __name__ == "__main__":

    main()
