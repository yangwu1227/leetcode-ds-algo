def check_if_pangram(sentence: str) -> bool:
    """
    A pangram is a sentence where every letter of the English alphabet appears at least once. Given a string sentence, return true if 
    sentence is a pangram, or false otherwise.

    Parameters
    ----------
    sentence : str
        A sentence containing only lowercase English letters

    Returns
    -------
    bool
        True if a pangram, otherwise False
    """
    character_set = set(sentence)   
    return len(character_set) == 26

def main() -> int:
    sentence = "thequickbrownfoxjumpsoverthelazydog"
    result = check_if_pangram(sentence)
    print(f"The sentence '{sentence}' {'is' if result else 'is not'} a pangram")
    return 0

if __name__ == "__main__":
    
    main()
