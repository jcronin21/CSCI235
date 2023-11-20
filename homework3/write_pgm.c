#include <stdio.h>
#include "write_pgm.h"
#include "matrix.h"


void write_pgm(Matrix matrix, const char* filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    double max_abs = 0.0;
    for (int i = 0; i < matrix.rows * matrix.columns; ++i) {
        double abs_val = matrix.data[i / matrix.columns][i % matrix.columns];
        abs_val = abs_val < 0 ? -abs_val : abs_val;
        if (abs_val > max_abs) {
            max_abs = abs_val;
        }
    }

    fprintf(file, "P2\n");
    fprintf(file, "%d %d\n", matrix.columns, matrix.rows);
    fprintf(file, "255\n");

    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.columns; ++j) {
            double scaled_val;
            if (max_abs != 0) {
                scaled_val = 127 + (matrix.data[i][j] / max_abs) * 127;
            } else {
                scaled_val = 127;
            }
            int pixel_value = (int)scaled_val;
            fprintf(file, "%d ", pixel_value);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}
