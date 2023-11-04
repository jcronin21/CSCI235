#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix matrix_multiply(Matrix A, Matrix B) {
    if (A.cols != B.rows) {
        printf("not compatible for multiplication.\n");
        exit(1);
    }

    Matrix final;
    final.rows = A.rows;
    final.cols = B.cols;
    final.data = (double **)malloc(final.rows * sizeof(double *));

    if (final.data == NULL) {
        printf("Mem allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < final.rows; i++) {
        final.data[i] = (double *)malloc(final.cols * sizeof(double));
        if (final.data[i] == NULL) {
            printf("Mem allocation failed.\n");
            exit(1);
        }

        for (int j = 0; j < final.cols; j++) {
            final.data[i][j] = 0.0;
            for (int k = 0; k < A.cols; k++) {
                final.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }

    return final;
}

void free_matrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        free(mat.data[i]);
    }
    free(mat.data);
}
