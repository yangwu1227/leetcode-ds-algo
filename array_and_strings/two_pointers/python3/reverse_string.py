from typing import List


def reverse_string(s: List[str]) -> None:
    """
    Given a list of characters, reverse the order of the characters in-place.

    Parameters
    ----------
    s : List[str]
        A list of characters.

    Returns
    -------
    None
        Modify s in place.
    """
    # Point to start and end of array
    left_index = 0
    right_index = len(s) - 1
    
    # Loop goes until left_index becomes greater than right_index, because we have reached the middle of the array and we don't need to swap anymore
    while (left_index < right_index):
        s[left_index], s[right_index] = s[right_index], s[left_index]
        # Move pointers towards each other
        left_index += 1
        right_index -= 1

    return None

def main() -> int:
    
    s_1 = ["h", "e", "l", "l", "o"]
    s_2 = ["H", "a", "n", "n", "a", "h"]
    s_3 = ["y", "a", "n", "g", "w", "u"]
    
    for s in [s_1, s_2, s_3]:
        
        print(f'Before reversing {s}')
        reverse_string(s)
        print(f'After reversiong {s}\n')
    
    return 0

if __name__ == "__main__":
    
    main()
