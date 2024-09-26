//
//  Pooling.h
//  Image - processing - library
//
//  Created by RAUNIT SINGH on 26/09/24.
//
#ifndef POOLING_H
#define POOLING_H

#include <vector>

using namespace std;

// Function declaration for Max Pooling
vector<vector<int>> MaxPooling(vector<vector<int>> &matrix, int poolsize, int stride);

// Function declaration for Average Pooling
vector<vector<int>> AvgPooling(vector<vector<int>> &matrix, int poolsize, int stride);

#endif 
