# Image Processing Library

A small C++ library of image-processing / CNN building blocks, implemented from scratch: FFT-based 2D convolution, pooling layers, and activation functions.

## What's here

- **FFT convolution** (`fft_convolution.cpp`) -- a recursive 1D FFT (Cooley-Tukey), extended to 2D via row/column passes, used to perform 2D convolution in the frequency domain (zero-pad, FFT both operands, multiply element-wise, inverse FFT) instead of naive spatial convolution.
- - **Pooling** (`Pooling.cpp`) -- max pooling and average pooling over a 2D matrix with configurable pool size and stride.
  - - **Activation functions** (`activation.cpp`) -- ReLU, tanh, and softmax, plus helpers to apply them elementwise over a matrix.
   
    - Together these are the core primitives behind a convolutional layer, built and tested independently of any ML framework.
   
    - ## Structure
   
    - ```
      Image - processing - library/
      |-- include/    # headers for each module
      |-- src/
      |   |-- fft_convolution.cpp
      |   |-- Pooling.cpp
      |   `-- activation.cpp
      `-- test/
      ```

      ## Running it

      Each source file has a commented-out `main()` with a small example (e.g. a 3x3 image convolved with a 2x2 kernel, or a sample matrix run through ReLU/tanh). Uncomment and compile the file you want to try, e.g.:

      ```bash
      g++ -std=c++17 src/fft_convolution.cpp -Iinclude -o fft_demo
      ./fft_demo
      ```

      ---

      Built with Yeatrix, Raunit, and Yuvraj.
      
