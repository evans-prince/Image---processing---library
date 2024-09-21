//
//  Pooling.hpp
//  Image - processing - library
//
//  Created by RAUNIT SINGH on 20/09/24.
//

#ifndef POOLING_HPP
#define POOLING_HPP

#include <vector>

using namespace std;

// Function declaration for Max Pooling
vector<vector<int>> MaxPooling(vector<vector<int>> &matrix, int poolsize, int stride);

// Function declaration for Average Pooling
vector<vector<int>> AvgPooling(vector<vector<int>> &matrix, int poolsize, int stride);

#endif /* POOLING_HPP */
