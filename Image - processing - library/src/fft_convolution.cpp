//
//  fft_convolution.cpp
//  Image - processing - library
//
//  Created by PRINCE  on 22/09/24.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include "../include/fft_convolution.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

// Perform 1D FFT or IFFT on a vector
void fft1D(vector<Complex>& data, bool inverse){
    size_t n = data.size();
    
    if( n <=1 ){
        return;
    }
    
    vector<Complex> even(n/2), odd(n/2);
    for(size_t i =0 ; i<n/2;i++){
        even[i]=data[2*i];
        odd[i]=data[2*i +1];
    }
    
    fft1D(even);
    fft1D(odd);
    
    double sign = inverse ? 1 : -1;
    for(size_t k=0;k<n/2;k++){
        Complex t = polar(1.0, sign * 2 * M_PI * k / n) * odd[k];
        data[k] = even[k] + t;
        data[k + n / 2] = even[k] - t;
    }
    
    // if doing inverse FFT
        if (inverse) {
            for (auto& x : data) x /= n; // normalising by size n
        }
}

// Perform 2D FFT or IFFT on a matrix
void fft2D(Matrix& data, bool inverse){
    size_t rows = data.size();
    size_t cols = data[0].size();
    // apply fft to each row
       for (size_t i = 0; i < rows; i++) {
           fft1D(data[i], inverse);
       }
        // apply fft to each column
       for (size_t j = 0; j < cols;j++) {
           std::vector<Complex> column(rows);
           for (size_t i = 0; i < rows;i++) {
               column[i] = data[i][j];
           }
           fft1D(column, inverse);
           for (size_t i = 0; i < rows; ++i) {
               data[i][j] = column[i];
           }
       }
}

// Pad a matrix to a new size (zero-padding)
Matrix padMatrix(const Matrix& mat, size_t new_rows, size_t new_cols){
    Matrix padded(new_rows, vector<Complex>(new_cols, 0));
    size_t rows = mat.size();
    size_t cols = mat[0].size();

    // Copy the original matrix into the padded matrix
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            padded[i][j] = mat[i][j];
        }
    }
    return padded;
}

// Multiply two matrices element-wise
Matrix multiplyElementWise(const Matrix& A, const Matrix& B){
    size_t rows = A.size();
    size_t cols = A[0].size();
    Matrix result(rows,vector<Complex>(cols));

    // Multiply each element of A and B
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] * B[i][j];
        }
    }
    return result;
}

// Perform 2D convolution using FFT
Matrix fftConvolution(const Matrix& image, const Matrix& kernel){
    size_t image_rows = image.size();
    size_t image_cols = image[0].size();
    size_t kernel_rows = kernel.size();
    size_t kernel_cols = kernel[0].size();
    // New size for the result (zero-padding)
    size_t new_rows = image_rows + kernel_rows - 1;
    size_t new_cols = image_cols + kernel_cols - 1;

    // Pad the image and kernel to the new size
    Matrix padded_image = padMatrix(image, new_rows, new_cols);
    Matrix padded_kernel = padMatrix(kernel, new_rows, new_cols);

    // Compute the FFT of both the padded image and kernel
    fft2D(padded_image, false);
    fft2D(padded_kernel, false);

    // Multiply the results in the frequency domain
    Matrix result_freq = multiplyElementWise(padded_image, padded_kernel);
    
    // Perform Inverse FFT to get the result back in the spatial domain
    fft2D(result_freq, true);

    return result_freq;
}


// to test convolution

// int main() {
//    // Define a simple 3x3 image matrix
//    Matrix image = {
//        {1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9}
//    };

//    // Define a simple 2x2 kernel
//    Matrix kernel = {
//        {0, 1},
//        {1, 0}
//    };

//    // Perform FFT convolution
//    Matrix result = fftConvolution(image, kernel);

//    // Output the convolved image
//    std::cout << "Convolved Image:" << std::endl;
//    for (const auto& row : result) {
//        for (const auto& val : row) {
//            std::cout << val.real() << " "; // Display only the real part
//        }
//        std::cout << std::endl; // New line for each row
//    }

//    return 0;
// }
