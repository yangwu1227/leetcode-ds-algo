from typing import MutableSequence, Deque, List, MutableMapping
from collections import deque, defaultdict

class FinalPrices(object):
    """
    Compute the final prices after applying discounts using a deque 
    and a hash map to track the next smaller price.

    The discount for each item is calculated based on the next item 
    in the sequence that has a price less than or equal to the current item.
    """
    @staticmethod
    def no_hash_approach(prices: MutableSequence[int]) -> List[int]:
        if len(prices) == 1:
            return list(prices)
        price_deque: Deque[int] = deque()
        for i in range(len(prices)):
            # While the deque is non-empty and the current prices maintains the montonic non-increasing property
            while price_deque and prices[i] <= prices[price_deque[-1]]:
                # Apply discount
                prices[price_deque.pop()] -= prices[i]
            price_deque.append(i)
        return list(prices)

    @staticmethod
    def hash_approach(prices: MutableSequence[int]) -> List[int]:
        if len(prices) == 1:
            return list(prices)
        price_deque: Deque[int] = deque()
        next_smaller_map: MutableMapping[int, int] = defaultdict(lambda: -1)
        for i in range(len(prices)):
            # While the deque is non-empty and the current prices maintains the montonic non-increasing property
            while price_deque and prices[i] <= prices[price_deque[-1]]:
                # Store the top of the deque as the key and its next smaller element as the value
                next_smaller_map[price_deque.pop()] = i
            price_deque.append(i)
        # If any price does not have a mapping, -1 is return, i.e., no discount
        output = [prices[i] - prices[next_smaller_map[i]] if next_smaller_map[i] != -1 else prices[i] for i in range(len(prices))]
        return output

def main() -> int:

    price_data = [[10, 1, 1, 6], [8, 4, 6, 2, 3], [1, 2, 3, 4, 5], [10, 7, 4, 2, 1]]
    for prices in price_data:
        final_prices_hash = FinalPrices.hash_approach(prices)
        # This modifies the input in-place
        final_prices_no_hash = FinalPrices.no_hash_approach(prices)
        assert final_prices_hash == final_prices_no_hash
        print(f"Given prices = {prices}, the final prices are {final_prices_hash}")

    return 0

if __name__ == "__main__":

    main()
