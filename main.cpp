/*
Author: Ethan Doughty
Class: EECS 348
Created: 10/12/2023
*/

#include <iostream>
#include <fstream>

// Maximumn amount of rows and columns that the matrices can hold
const int MAX_SIZE = 10;

//Recieves the filename from main and assigns values to each matrix A and B 
void read_matrix(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int &size, const char *filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> A[i][j];
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> B[i][j];
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
}

//Simple print function for a single matrix
void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int &size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

//Recieves matrix A and B and calculates the sum and assigns it to matrix C
void matrix_sum(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int &size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

//Recieves matrix A and B and calculates the product and assigns it to matrix C
void matrix_multiplication(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int &size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

//Recieves matrix A and B and calculates the difference and assigns it to matrix C
void matrix_subtraction(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int &size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

int main() {
    int size;
    //Initialize 3 matrices using 2D arrays with MAX_SIZE x MAX_SIZE as the max dimensions
    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int C[MAX_SIZE][MAX_SIZE];

    //Header
    std::cout << "Name: Ethan Doughty" << std::endl;
    std::cout << "Lab #6: Matrix Manipulation" << std::endl;

    //Read matrix values from file and assign them to matrix A and B
    read_matrix(A, B, size, "matrix.txt");  

    //Print values from matrix A
    std::cout << "Matrix A: " << std::endl;
    print_matrix(A, size);

    //Print values from matrix B
    std::cout << "Matrix B: " << std::endl;
    print_matrix(B, size);

    //Calculate the sum of matrix A and B, and print the result
    std::cout << "Matrix Sum (A + B): " << std::endl;
    matrix_sum(A, B, C, size);
    print_matrix(C, size);

    //Calculate the product of matrix A and B, and print the result
    std::cout << "Matrix Product (A * B): " << std::endl;
    matrix_multiplication(A, B, C, size);
    print_matrix(C, size);

    //Calculate the difference of matrix B from matrix A, and print the result
    std::cout << "Matrix Difference (A - B): " << std::endl;
    matrix_subtraction(A, B, C, size);
    print_matrix(C, size);

    return 0;
}