// main.cpp
#include "set_zeros.hpp"
#include <Eigen/Dense>
#include <iostream>

int main()
{
    Eigen::MatrixXd matrix(4, 4);
    matrix << 1, 2, 0, 4,
              5, 6, 7, 8,
              9, 0, 11, 12,
              13, 14, 15, 16;

    std::cout << "Original matrix:\n"
              << matrix << '\n';
    SetZeros::eigenApproach(matrix);
    std::cout << "Modified matrix:\n"
              << matrix << '\n';

    return 0;
}
