//
//  convolution.h
//  Image - processing - library
//
//  Created by PRINCE  on 22/09/24.
//
#ifndef FFT_CONVOLUTION_H
#define FFT_CONVOLUTION_H

#include <complex>
#include <vector>


// Alias for complex numbers and 2D matrices
using Complex = std::complex<double>;
using Matrix = std::vector<std::vector<Complex>>;

// Perform 1D FFT or IFFT on a vector
void fft1D(std::vector<Complex>& data, bool inverse = false);

// Perform 2D FFT or IFFT on a matrix
void fft2D(Matrix& data, bool inverse = false);

// Pad a matrix to a new size (zero-padding)
Matrix padMatrix(const Matrix& mat, size_t new_rows, size_t new_cols);

// Multiply two matrices element-wise
Matrix multiplyElementWise(const Matrix& A, const Matrix& B);

// Perform 2D convolution using FFT
Matrix fftConvolution(const Matrix& image, const Matrix& kernel);

#endif  // FFT_CONVOLUTION_H
