from array import array
from typing import MutableSequence

def remove_k_digits(num: str, k: int) -> str:
    """ 
    Remove k digits from the given number to produce the smallest possible number.

    Parameters
    ----------
    num : str
        The original number given as a string of digits
    k : int
        The number of digits to remove from the original number

    Returns
    -------
    str
        The smallest possible number as a string after removing k digits; if the resulting number is empty or only contains zeros, '0' is returned
    """
    n = len(num)
    if n == 1 or n == k:
        return '0'
    digit_stack: MutableSequence[str] = array('u')
    for digit in num:
        print(f"Processing digit = {digit} | Stack is empty") if not digit_stack else print(f"Processing digit = {digit} | Stack empty? {not bool(digit_stack)} | k > 0? {k > 0} | (top of stack: {digit_stack[-1]}) > (current digit: {digit})? {digit_stack[-1] > digit}")
        while digit_stack and k > 0 and digit_stack[-1] > digit:
                print(f"  Popping digit = {digit_stack[-1]} from stack since (top of stack: {digit_stack[-1]}) > (current digit: {digit}) | Decrement k = {k} -> {k - 1}")
                digit_stack.pop()
                k -= 1
        digit_stack.append(digit) 
        print(f"Push digit = {digit} to the top of the stack | Stack {digit_stack}")
    while k > 0:
        print(f"  Popping digit = {digit_stack[-1]} since (k = {k}) > 0 | Decrement k = {k} -> {k - 1}")
        digit_stack.pop()
        print(f"  Stack {digit_stack}")
        k -= 1
    # Join the results back to a string and strip leading zeros
    output = ''.join(digit_stack).lstrip('0')
    return output if output else '0'

def main() -> int:

    data = [("100000", 1), ("964310", 5), ("13579", 4), ("1432219", 3), ("12", 2), ("14957283", 6)]
    for num, k in data:
        output = remove_k_digits(num, k)
        print(f"Given num = {num}, the smallest possible number after removing {k} digits is {output}\n")

    return 0

if __name__ == "__main__":

    main()
