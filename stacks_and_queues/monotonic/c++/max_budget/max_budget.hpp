// max_budget.hpp
#ifndef MAX_BUDGET_HPP
#define MAX_BUDGET_HPP
#include <vector>

/**
 * @brief Calculate the maximum number of machines that can be run simultaneously without exceeding the budget.
 *
 * @param chargeTimes An `std::vector` of integers where each element represents the charge time of a machine
 * @param runningCosts An `std::vector` of integers where each element represents the running cost of a machine
 * @param budget The maximum allowed budget for running the machines
 *
 * @return int The maximum number of machines that can be run simultaneously without exceeding the budget
 */
int maxBudget(const std::vector<int> &chargeTimes, const std::vector<int> &runningCosts, long long budget);

#endif
