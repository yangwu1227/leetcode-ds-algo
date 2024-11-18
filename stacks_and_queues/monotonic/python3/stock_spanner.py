from collections import deque
from typing import Deque, Tuple


class StockSpanner(object):
    """
    A class for calculating the stock span for each day.

    The stock span on a given day represents the maximum number of consecutive days (including the current day)
    where the stock price was less than or equal to the stock price on that day.
    """

    def __init__(self) -> None:
        """
        Initializes the StockSpanner instance.
        """
        # Stack to store pairs of (price, span)
        self.stack: Deque[Tuple[int, int]] = deque()

    def next(self, price: int) -> int:
        """
        Calculates the stock span for the given price.

        Parameters
        ----------
        price : int
            The current day's stock price

        Returns
        -------
        int
            The span of stock prices less than or equal to the current price
        """
        span = 1
        print(f"Current Price = {price} | Initialized span to {span}")
        print(f"Current Price = {price} | Current state of the stack {self.stack}")
        # Pop elements from the stack if the current price is greater than or equal to the price at the top of the stack
        while self.stack and self.stack[-1][0] <= price:
            print(
                f"Current Price = {price} | The pair {self.stack[-1]} will be popped since its price is lower than {price}"
            )
            span += self.stack.pop()[1]
            print(f"Current Price = {price} | Current state of the stack {self.stack}")
        # Push the current price and its span to the stack
        print(f"Current Price = {price} | Append ({price}, {span}) to the stack")
        self.stack.append((price, span))
        print(f"Current Price = {price} | Current state of the stack {self.stack}")
        return span


def main() -> int:
    prices = [100, 80, 60, 40, 30, 13, 102]
    stock_spanner = StockSpanner()
    for price in prices:
        print(
            f"The current prices is {price}, and its span is {stock_spanner.next(price)}"
        )

    return 0


if __name__ == "__main__":
    main()
