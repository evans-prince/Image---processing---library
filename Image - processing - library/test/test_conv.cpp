#include <iostream>
#include <vector>
#include "../include/fft_convolution.h" 

// Function to print a matrix
void printMatrix(Matrix& matrix) {
    for (auto& row : matrix) {
        for (auto& val : row) {
            std::cout << val.real() << " ";
        }
        std::cout << std::endl;
    }
}

// Function to compare two matrices
bool compareMatrices(Matrix mat1, Matrix& mat2) {
    if (mat1.size() != mat2.size() || mat1[0].size() != mat2[0].size()) {
        return false;
    }
    for (size_t i = 0; i < mat1.size(); ++i) {
        for (size_t j = 0; j < mat1[0].size(); ++j) {
            if (mat1[i][j] != mat2[i][j]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    // Define a simple 3x3 image matrix
    Matrix image = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Define a simple 2x2 kernel
    Matrix kernel = {
        {0, 1},
        {1, 0}
    };

    // Expected result after convolution (manual calculation)
    Matrix expected = {
        {0, 1, 2, 3},
        {1, 6, 8, 6},
        {4, 12, 14, 9},
        {7, 8, 9, 0}
    };

    // Perform FFT convolution
    Matrix result = fftConvolution(image, kernel);

    // Output the convolved image
    std::cout << "Convolved Image (Real Part):" << std::endl;
    printMatrix(result);

    // Check if the result matches the expected output
    if (compareMatrices(result, expected)) {
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}
