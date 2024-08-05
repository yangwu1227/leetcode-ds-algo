// recent_requests.hpp
#ifndef RECENT_REQUESTS_HPP
#define RECENT_REQUESTS_HPP
#include <queue>

class RecentCounter
{
public:
    /**
     * @brief Construct a new Recent Counter instance.
     *
     * @param threshold The time window (in milliseconds) within which pings are considered recent
     */
    RecentCounter(int threshold);

    /**
     * @brief Records a new ping with timestamp `t` and returns the number of pings within the time window.
     *
     * @param t The timestamp of the new ping
     * @return int The number of pings within the time window [t - outdated_threshold, t]
     */
    int ping(int t);

private:
    int threshold; // Theshold for time window in milliseconds
    std::queue<int> internalQueue; // Internal queue for FIFO operations
};

#endif
