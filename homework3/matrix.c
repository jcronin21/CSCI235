#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix create_matrix(unsigned rows, unsigned columns) {
    Matrix final;
    final.rows = rows;
    final.columns = columns;
    final.data = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        final.data[i] = (double *)calloc(columns, sizeof(double));
    }
    return final;
}

void print_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.columns; j++) {
            if (j == (matrix.columns - 1)) {
                printf("%.6f\n", matrix.data[i][j]);
            } else {
                printf("%.6f ", matrix.data[i][j]);
            }
        }
    }
}

void free_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        free(matrix.data[i]);
    }
    free(matrix.data);
}

int main() {
    Matrix final1 = create_matrix(3, 3);
    print_matrix(final1);
    free_matrix(final1);
    return 0;
}
