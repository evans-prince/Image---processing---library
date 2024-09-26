#include <iostream>
#include<vector>
#include <cmath>
#include "../include/activation.h"
using namespace std;

float ReLu(float x){
    /*
        ReLu activation function 
    */
    return x > 0 ? x : 0;
}

float tanh_custom(float x){
    /*
        tanh activation function
    */
    if (x > 20.0f) return 1.0f;
    if (x < -20.0f) return -1.0f;
    return (exp(x)-exp(-x))/(exp(x)+exp(-x));
}

void apply_relu(vector<vector<float> > &matrix){
    /*
        function to apply the relu activation function on the input matrix
    */
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            matrix[i][j] = ReLu(matrix[i][j]);
        }
    }
}

void apply_tanh(vector<vector<float> > &matrix){
    /*
        function to apply the tanh activation function on the input matrix
    */
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            matrix[i][j] = tanh_custom(matrix[i][j]);
        }
    }
}


vector <float> softmax(vector<float> &input) {
    vector<float> softmaxOutput;
    vector<float> exponents;

    float denominator = 0;

    for (int i = 0; i < input.size(); ++i) {
        exponents.push_back(exp(input[i]));
        denominator += exp(input[i]);
    }

    for (int i = 0; i < input.size(); ++i) {
        softmaxOutput.push_back(exponents[i] / denominator);
    }
    return softmaxOutput;
}
                                                                         
void printMatrix(vector<vector<float>> matrix) {
    for (auto& row : matrix) {
        for (auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}


int main(){
    vector<vector<float> > matrix1 = {
        {-2,2,4},
        {5.4,2.01,-99},
        {1,2,7},
    };
    apply_relu(matrix1);
    printMatrix(matrix1);
    vector<vector<float>> matrix2 = {
        {-2,2,4},
        {5.4,2.01,-99},
        {1,2,7},
    };
    apply_tanh(matrix2);
    printMatrix(matrix2);
}
