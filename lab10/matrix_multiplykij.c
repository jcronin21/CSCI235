#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "matrix_multiplykij.h"

Matrix matrix_multiply_kij(Matrix A, Matrix B) {
    if (A.columns != B.rows) {
        printf("Matrices are not compatible for multiplication.\n");
        exit(1);
    }

    // Create the output matrix
    Matrix final = create_matrix(A.rows, B.columns);

    // Perform matrix multiplication using the kij algorithm
    for (int k = 0; k < A.columns; k++) {
        for (int i = 0; i < final.rows; i++) {
            for (int j = 0; j < final.columns; j++) {
                final.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }

    return final;
}
