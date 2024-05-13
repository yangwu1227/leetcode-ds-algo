from typing import List
from collections import defaultdict

def find_winners(matches: List[List[int]]) -> List[List[int]]:
    """
    Given an integer array `matches` where `matches[i] = [winner_i, loser_i]` indicates that the player `winner_i` defeated player `loser_i` in a match. Return a list of two lists:
    
    1. The first list contains the players who never lose once
    2. The second list contains the players who only lost once
    
    Parameters
    ----------
    matches : List[List[int]]
        A list of lists where each inner list contains two integers `winner_i` and `loser_i`

    Returns
    -------
    List[List[int]]
        A list of two lists where the first list contains the players who never lose once and the second list contains the players who only lost once
    """
    winner_counter = defaultdict(int)
    loser_counter = defaultdict(int)
    
    # O(n)
    for winner, loser in matches:
        # These operations are O(1)
        winner_counter[winner] += 1
        loser_counter[loser] += 1
    
    # O(n) for each set comprehension
    winners = set(winner for winner in winner_counter if winner not in loser_counter)
    losers = set(loser for loser, loss_count in loser_counter.items() if loss_count == 1)
    
    # O(n log n) sorting
    return [sorted(winners), sorted(losers)]
    
def main() -> int:
    
    matches_lists = [
        [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]],
        [[2,3],[1,3],[5,4],[6,4]]
    ]
    
    for matches in matches_lists:
        result = find_winners(matches)
        print(f"Given the match results {matches}, players {result[0]} never lose once and players {result[1]} only lost once")
    
    return 0

if __name__ == "__main__":
    
    main()
