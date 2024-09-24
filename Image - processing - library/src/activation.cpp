#include <iostream>
#include<vector>
#include <activation.h>
using namespace std;

float ReLu(float x){
    /*
        ReLu activation function 
    */
    return x > 0 ? x : 0;
}

float tanh(float x){
    /*
        tanh activation function
    */
    float activated_x = (exp(x)-exp(-x))/(exp(x)-exp(-x));
    return activated_x;
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
            matrix[i][j] = tanh(matrix[i][j]);
        }
    }
}


vector <double> softmax(vector<double> &input) {
    vector<double> softmaxOutput;
    vector<double> exponents;

    double denominator = 0;

    for (int i = 0; i < input.size(); ++i) {
        exponents.push_back(exp(input[i]));
        denominator += exp(input[i]);
    }

    for (int i = 0; i < input.size(); ++i) {
        softmaxOutput.push_back(exponents[i] / denominator);
    }
    return softmaxOutput;
}

