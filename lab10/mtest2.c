#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "matrix_multiplyijk.h"
#include "matrix_multiplykij.h"
#include "matrix_multiplyjki.h"
#include <time.h>



void fill_matrix(Matrix m) {
        int nRow = m.rows;
        int nCol = m.columns;

        double num = 0;

        for(int i = 0; i <nRow; i++) {
                for(int j = 0; j < nCol; j++) {
                        ++num;
                        m.data[i][j] = num;
                }
        }
}

double timed_test(Matrix m1, Matrix m2, int which_one) {
    if (m1.columns != m2.rows) {
        printf("Error: Matrix dimensions are incompatible for multiplication.\n");
        return 0;
    }

    Matrix output;

    clock_t start_time, end_time;
    start_time = clock();

    switch (which_one) {
        case 1:
            output = matrix_multiplyijk(m1, m2);
            break;
        case 2:
            output = matrix_multiplykij(m1, m2);
            break;
        case 3:
            output = matrix_multiplyjki(m1, m2);
            break;
        default:
            printf("Invalid choice for matrix multiplication function.\n");
            exit(1);
    }

    end_time = clock();

    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Time elapsed for algorithm %d: %f seconds\n", which_one, total_time);

    return total_time;
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        printf("Usage: %s <row1> <col1> <row2> <col2> <which_one>\n", argv[0]);
        return 1;
    }

    int r1 = atoi(argv[1]);
    int c1 = atoi(argv[2]);
    int r2 = atoi(argv[3]);
    int c2 = atoi(argv[4]);
    int which_one = atoi(argv[5]);

    Matrix m1 = create_matrix((unsigned)r1, (unsigned)c1);
    fill_matrix(m1);
    Matrix m2 = create_matrix((unsigned)r2, (unsigned)c2);
    fill_matrix(m2);

    printf("Matrix dimensions: %dx%d and %dx%d\n", r1, c1, r2, c2);

    double time_ijk = timed_test(m1, m2, 1);
    double time_kij = timed_test(m1, m2, 2);
    double time_jki = timed_test(m1, m2, 3);

    free_matrix(m1);
    free_matrix(m2);

    return 0;
}







