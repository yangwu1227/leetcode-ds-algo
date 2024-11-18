from typing import List


def asteroid(data: List[int]) -> List[int]:
    """
    Simulates the collision of asteroids based on their size and direction. Each asteroid moves at the same speed. If
    two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Asteroids moving in
    the same direction will never meet.

    Parameters
    ----------
    data : List[int]
        A list of integers representing asteroids in a row. The absolute value
        represents the size of the asteroid, and the sign represents its direction
        (positive for right, negative for left)

    Returns
    -------
    List[int]
        The state of the asteroids after all collisions
    """
    data_stack: List[int] = []
    for val in data:
        # Push if the stack is empty OR the current value is moving to the right OR the top of the stack is moving to the left
        if not data_stack or val > 0 or data_stack[-1] < 0:
            data_stack.append(val)
        # If the complement is true -> stack is not empty and current value is moving left and top of the stack is moving right
        else:
            # Keep checking if stack is non-empty and top of the stack is moving right
            while data_stack and data_stack[-1] > 0:
                top_abs = abs(data_stack[-1])
                val_abs = abs(val)
                # If top of the stack is smaller in size, pop it and use continue to run the while condition check again
                if top_abs < val_abs:
                    data_stack.pop()
                    continue
                # If the top of the stack is equal in size, pop it and break out of the loop
                elif top_abs == val_abs:
                    data_stack.pop()
                    break
                # If the top of the stack is larger in size, simply break out of the loop
                else:
                    break
            else:
                # If the loop is not exited by a break, it means all possible collisions are resolved, push the current value
                data_stack.append(val)
    return data_stack


def main() -> int:
    test_data = [[-2, 1, 1, -1], [10, 2, -5], [-2, -2, -2, -1], [8, -8]]
    for data in test_data:
        processed_data = asteroid(data)
        print(f"Given data = {data}, the processsed data is {processed_data}")

    return 0


if __name__ == "__main__":
    main()
