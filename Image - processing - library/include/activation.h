#ifndef ACTIVATION_H   
#define ACTIVATION_H

#include <vector> 


float ReLu(float x);

float tanh_custom(float x);

void apply_relu(std::vector<std::vector<float>>& matrix);

void apply_tanh(std::vector<std::vector<float>>& matrix);

#endif 
