#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "matrix_multiplykij.h"
#include "matrix_multiplyjki.h"


Matrix matrix_multiplyijk(Matrix A, Matrix B) {
    if (A.columns != B.rows) {
        printf("not compatible for multiplication.\n");
        exit(1);
    }

        // Create output matrix
        Matrix final = create_matrix(A.rows, B.columns);

        // Perform matrix multiplication operation and populate output matrix
    for (int i = 0; i < final.rows; i++) {
        for (int j = 0; j < final.columns; j++) {
            final.data[i][j] = 0.0;
            for (int k = 0; k < A.columns; k++) {
                final.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }

    return final;
}
