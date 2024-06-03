from collections import Counter

class RansomNote(object):
    """
    Given two strings `ransom_note` and `magazine`, return `True` if `ransom_note` can be constructed by using the letters from `magazine`.

    Parameters
    ----------
    ransom_note : str
        A string containing lower case english letters
    magazine : str
        A string containing lower case english letters

    Returns
    -------
    bool
        `True` if `magazine` contains a permutation of `magazine`, `False` if not
    """
    @staticmethod
    def two_hashmaps(ransom_note: str, magazine: str) -> bool:
        # O(n), where n is the length of 'magazine'
        magazine_counts = Counter(magazine)
        # O(m) where m is the length of 'ransom_note'
        ransom_note_counts = Counter(ransom_note)
        for character in ransom_note:
            # If magazine contains fewer than required counts for any characters, it is not possible to reproduce 'ransom_note'
            if magazine_counts[character] < ransom_note_counts[character]:
                return False 
        return True
    
    @staticmethod
    def one_hashmap(ransom_note: str, magazine: str) -> bool:
        # O(n), where n is the length of 'magazine'
        magazine_counts = Counter(magazine)
        for character in ransom_note:
            # Subtract from the counts
            magazine_counts[character] -= 1
            # If any count reaches below zero, it either means that 1) there is not enough that character or 2) no such character exist in 'magazine'
            if magazine_counts[character] < 0:
                return False
        return True
     
def main() -> int:

    for ransom_note_, magazine in [("a", "b"), ("aa", "ab"), ("aag", "gagaz"), ("fffbfg", "effjfggbffjdgbjjhhdegh")]:
        two_hashmaps = RansomNote.two_hashmaps(ransom_note_, magazine)
        one_hashmap = RansomNote.one_hashmap(ransom_note_, magazine)
        assert one_hashmap == two_hashmaps
        print(f"Ransom note = '{ransom_note_}' {'can' if one_hashmap else 'cannot'} be constructed from magazine = '{magazine}'")

    return 0

if __name__ == "__main__":
    
    main()