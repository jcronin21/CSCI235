#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "matrix_multiplyjki.h"

Matrix matrix_multiply_jki(Matrix A, Matrix B) {
    if (A.columns != B.rows) {
        printf("Matrices are not compatible for multiplication.\n");
        exit(1);
    }

    // Create the output matrix
    Matrix final = create_matrix(A.rows, B.columns);

    // Perform matrix multiplication using the jki algorithm
    for (int j = 0; j < final.columns; j++) {
        for (int k = 0; k < A.columns; k++) {
            for (int i = 0; i < final.rows; i++) {
                final.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }

    return final;
}
