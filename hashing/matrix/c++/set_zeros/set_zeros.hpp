// set_zeros.hpp
#ifndef SET_ZEROS_HPP
#define SET_ZEROS_HPP
#include <vector>
#include <Eigen/Dense>

class SetZeros
{
public:

    /**
     * @brief Given an `m x n` integer `matrix`, if an element is 0, set its entire row and column to 0's.  
     * 
     * @param matrix A vector of vectors of integers
     */
    static void hashApproach(std::vector<std::vector<int>> &matrix);

    /**
     * @brief Given an `m x n` integer `matrix`, if an element is 0, set its entire row and column to 0's. 
     * 
     * @param matrix The matrix to be modified
     */
    static void eigenApproach(Eigen::MatrixXd &matrix);
};

#endif
