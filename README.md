# Matrix Multiplication SCOREC
This project is made for the SCOREC Research Submission. Created by Andrew Wang CS '29

External libraries used: Eigen, A general purpose linear algebra library

# Usage
This project utilizes CMake and GoogleTest for building and testing.
Steps to build locally on Linux with Git installed:
1. Clone into directory using **git clone https://github.com/TheAndrewWang/matrix-mul/ <dest-directory>**
2. **cd <dest_directory>/build**
5. run **ctest** to run default tests that I have made, or run **./matrixm** to multiply two matrices

# How I tested
I used Google Test and created a file with many unit tests created by Claude Opus 5 in the **matrix_tests.cc** file. This tested many edge cases such as multiplying by zero matrices, single element matrics, and other properties.
