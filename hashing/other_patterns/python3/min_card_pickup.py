from sys import maxsize
from collections.abc import Sequence
from collections import defaultdict

def min_card_pickup(cards: Sequence[int]) -> int:
    """
    Given a deck of `cards`, where `cards[i]` represents the value of the `ith` card, a pair of cards are matching
    if the cards have the same values.

    Parameters
    ----------
    cards : Sequence[int]
        A sequence of non-negative integers representing the value of the the `ith` card

    Returns
    -------
    int
        Minimum number of consecutive cards picked in order to find a pair of matching cards or -1 if it is impossible
    """
    if len(cards) == 1:
        return -1
    card_indices = defaultdict(int)
    min_distance = maxsize
    # 0(n) to compute and check
    for index, card in enumerate(cards):
        # If card has already been seen before
        if card in card_indices:
            # Compute the distance between the current index and the previous index where 'card' was observed
            dist = index - card_indices[card] + 1
            # Check to see if we have found a even smaller minimum number of pickups
            min_distance = min(min_distance, dist)
        # Record the index of most recent occurrence of 'card'
        card_indices[card] = index
        
    return min_distance if min_distance < maxsize else -1
        
def main() -> int:
    
    for cards in [[3, 4, 2, 3, 4, 7], [1, 0, 5, 3], [95, 11, 8, 65, 5, 86, 30, 27, 30, 73, 15, 91, 30, 7, 37, 26, 55, 76, 60, 43, 36, 85, 47, 96, 6]]:
        min_pickups = min_card_pickup(cards)
        message = f"we need a minimum of {min_pickups} pickups to find matching pair" if min_pickups != -1 else "there are no matching pairs"
        print(f"Given the deck of cards {cards}, {message}")
    
    return 0

if __name__ == "__main__":
    
    main()
