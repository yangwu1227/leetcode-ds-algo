from collections import Counter


class SortString(object):
    """
    Given two strings `order` and `s`, all the characters of `order` are unique and are sorted in some custom order.

    Permute the characters of `s` so that they match `order`. If a character `x` occurs before a character `y` in `order`, then `x` should occur 
    before `y` in the permuted string.

    Parameters
    ----------
    order : str
        A string consisting of lower case english letters
    s : str
        A string consisting of lower case english letters

    Returns
    -------
    str
        Any permutation of `s` that is sorted based on `order`
    """
    @staticmethod
    def loops(order: str, s: str) -> str:
        # O(n) where n is the number of characters in 's'
        s_char_counts = Counter(s)
        perm_list = []
        for order_char in order:
            # If the order character appears in 's'
            if order_char in s_char_counts:
                # Append the appropriate number of this character to the list
                perm_list.append(s_char_counts[order_char] * order_char)
                # Remove the key
                del s_char_counts[order_char]
        for s_char, count in s_char_counts.items():
            perm_list.append(s_char * count)
        # This joins 'n' characters in total, so O(n)
        return ''.join(perm_list)
    
    @staticmethod
    def generators(order: str, s: str) -> str:
        # O(n) where n is the number of characters in 's'
        s_char_counts = Counter(s)
        # Use pop to both access the count of order_char and remove it at the same time, returning 0 count if order_char does not exist in 's'
        sorted_portion = ''.join(order_char * s_char_counts.pop(order_char, 0) for order_char in order)
        non_sorted_portion = ''.join(s_char * count for s_char, count in s_char_counts.items())
        # O(n)
        sorted_portion += non_sorted_portion
        return sorted_portion

def main() -> int:

    for order, s in [("cba", "abcd"), ("bcafg", "abcd")]:
        perm_str_loops = SortString.loops(order, s)
        perm_str_dict_comps = SortString.generators(order, s)
        assert perm_str_dict_comps == perm_str_loops
        print(f"Given order = '{order}', the permuated version of s = '{s}' is '{perm_str_loops}'")

    return 0

if __name__ == "__main__":

    main()