from collections import deque
from random import randint
from typing import Deque


class RecentCounter(object):
    """
    A class to count recent pings within a given time window.
    """

    def __init__(self, outdated_threshold: int) -> None:
        """
        Initializes the RecentCounter instance.

        Parameters
        ----------
        outdated_threshold : int
            The time window (in milliseconds) within which pings are considered recent
        """
        self.deque: Deque[int] = deque()
        self.outdated_threshold: int = outdated_threshold

    def ping(self, t: int) -> int:
        """
        Records a new ping with timestamp `t` and returns the number of pings
        within the time window.

        Parameters
        ----------
        t : int
            The timestamp of the new ping

        Returns
        -------
        int
            The number of pings within the time window [t - outdated_threshold, t]
        """
        # Remove pings that are older than the outdated threshold
        while self.deque and t - self.deque[0] > self.outdated_threshold:
            self.deque.popleft()
        # Enque to add the time stamp to the front of the que
        self.deque.append(t)
        return len(self.deque)


def main() -> int:
    threshold = randint(500, 3000)
    recent_counter = RecentCounter(threshold)
    ping_timestamp = 0
    for _ in range(10):
        ping_timestamp += randint(100, 2000)
        print(
            f"There were {recent_counter.ping(ping_timestamp)} prings within past {threshold} ms window"
        )

    return 0


if __name__ == "__main__":
    main()
