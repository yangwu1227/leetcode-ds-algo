// random_matrix.cpp
#include "random_matrix.hpp"
#include <vector>
#include <random>

std::vector<std::vector<double>> generateRandomMatrix(int rows, int cols, double min, double max)
{
    std::random_device rnd_device;
    std::mt19937 mersenne_engine{rnd_device()};
    std::uniform_real_distribution<double> dist{min, max};

    auto gen = [&dist, &mersenne_engine]() {
        return dist(mersenne_engine);
    };

    std::vector<std::vector<double>> matrix(rows, std::vector<double>(cols));
    for (auto& row : matrix) {
        for (auto& val : row) {
            val = gen();
        }
    }
    return matrix;
}
