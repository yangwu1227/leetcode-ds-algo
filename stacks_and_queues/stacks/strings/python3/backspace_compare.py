from typing import List


class CompareStrings(object):
    """
    A class to compare two strings that contain backspaces.
    """

    def _build_string(self, string: str) -> str:
        """
        Build a string from the given string by pushing and popping characters from a stack.

        Parameters
        ----------
        string : str
            The string to build

        Returns
        -------
        str
            The built string
        """
        char_stack: List[str] = []
        for char in string:
            # If '#' and the stack is not empty, pop the top of the stack
            if char == "#" and char_stack:
                char_stack.pop(-1)
            # Only push if char is not '#'
            elif char != "#":
                char_stack.append(char)
        return "".join(char_stack)

    def compare(self, s: str, t: str) -> bool:
        """
        Compare two strings that contain backspaces.

        Parameters
        ----------
        s : str
            The first string
        t : str
            The second string

        Returns
        -------
        bool
            `True` if the strings are the same, `False` otherwise
        """
        if len(s) == 1 and len(t) == 1:
            return s == t
        return self._build_string(s) == self._build_string(t)


def main() -> int:
    test_strings = [("y#fo##f", "y#f#o##f"), ("a#c", "b"), ("ab#c", "ad#c")]
    for s, t in test_strings:
        compare_strings = CompareStrings()
        same = compare_strings.compare(s, t)
        print(
            f"Given s = {s} and t = {t}, the built strings are {'the' if same else 'not the'} same"
        )

    return 0


if __name__ == "__main__":
    main()
