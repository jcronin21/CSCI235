#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "matrix_multiply.h"

void fill_matrix(Matrix m) {
    int nRow = m.rows;
    int nCol = m.columns;

    double num = 0;

    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            ++num;
            m.data[i][j] = num;
        }
    }
}

double timed_test(int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        printf("Errors occurred...exiting..\n");
        return 0;
    }

    Matrix m1 = create_matrix(r1, c1);
    fill_matrix(m1);
    Matrix m2 = create_matrix(r2, c2);
    fill_matrix(m2);

    clock_t start_time, end_time;
    start_time = clock();

    Matrix output = matrix_multiply(m1, m2);

    end_time = clock();

    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Time elapsed was %f seconds\n", total_time);

    return total_time;
}




int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <row1> <col1> <row2> <col2>\n", argv[0]);
        return 1;
    }

    char *endptr;

    double r1 = strtod(argv[1], &endptr);
    double c1 = strtod(argv[2], &endptr);
    double r2 = strtod(argv[3], &endptr);
    double c2 = strtod(argv[4], &endptr);


    if (*endptr != '\0' && *endptr != '\n') {
        printf("Invalid input. Please provide valid integers for dimensions.\n");
        return 1;
    }

    double result = timed_test((int)r1, (int)c1, (int)r2, (int)c2);

    return 0;
}
