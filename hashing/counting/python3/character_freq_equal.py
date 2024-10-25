from collections import Counter, defaultdict


class CharFrequency(object):
    """
    Given a string `s`, determine if all characters have the same frequency.

    Parameters
    ----------
    s : str
        A string containing english characters

    Returns
    -------
    bool
        True if all characters have the same number of occurrences otherwise False
    """
    @staticmethod
    def defaultdict_approach(s: str) -> bool:
        counts = defaultdict(int)
        # O(n) to build this hash map
        for char in s:
            counts[char] += 1
        # O(n) to build a set
        freq_set = set(count for count in counts.values())
        return len(freq_set) == 1

    @staticmethod
    def counter_approach(s: str) -> bool:
        # O(n) to build this counter
        counter = Counter(s)
        # O(n) to build a set
        freq_set = set(count for count in counter.values())
        return len(freq_set) == 1

def main() -> int:
    
    for s in ["abacbc", "aaabb"]:
        defaultdict_ans = CharFrequency.defaultdict_approach(s)
        counter_ans = CharFrequency.counter_approach(s)
        assert defaultdict_ans == counter_ans
        print(f"Given the string {s}, each character {'has' if counter_ans else 'does not have'} the same number of occurrences")
        
    return 0

if __name__ == "__main__":
    
    main()
