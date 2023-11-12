#include "matrix.h"
#include <stdlib.h>

Matrix create_matrix(unsigned rows, unsigned columns) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.columns = columns;

    matrix.data = (double**)malloc(rows * sizeof(double*));
    for (unsigned i = 0; i < rows; i++) {
        matrix.data[i] = (double*)malloc(columns * sizeof(double));
    }

    return matrix;
}

void free_matrix(Matrix m) {
    for (unsigned i = 0; i < m.rows; i++) {
        free(m.data[i]);
    }
    free(m.data);
}
