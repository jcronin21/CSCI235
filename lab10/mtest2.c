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

Matrix pick_matrix_multiply(Matrix m1, Matrix m2, int which_one) {
    switch (which_one) {
        case 1:
            return matrix_multiplyijk(m1, m2);
        case 2:
            return matrix_multiplykij(m1, m2);
        case 3:
            return matrix_multiplyjki(m1, m2);
        default:
            printf("Invalid choice for matrix multiplication function.\n");
            exit(1);
    }
}

int str_to_int(const char *str) {
    int result = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}

double timed_test(int r1, int c1, int r2, int c2, int which_one) {
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

    Matrix output = pick_matrix_multiply(m1, m2, which_one);

    end_time = clock();

    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Time elapsed was %f seconds\n", total_time);

    return total_time;
}





/*int main(int argc, char *argv[],int which_one) {
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

    double result = timed_test((int)r1, (int)c1, (int)r2, (int)c2,(int)which_one);

    return 0;
}
*/
int main(int argc, char *argv[]) {
    if (argc != 6) {
        printf("Usage: %s <row1> <col1> <row2> <col2> <which_one>\n", argv[0]);
        return 1;
    }

    double r1 = 0, c1 = 0, r2 = 0, c2 = 0;
    int i = 0;

    while (argv[1][i] >= '0' && argv[1][i] <= '9') {
        r1 = r1 * 10 + (argv[1][i] - '0');
        i++;
    }

    i = 0;
    while (argv[2][i] >= '0' && argv[2][i] <= '9') {
        c1 = c1 * 10 + (argv[2][i] - '0');
        i++;
    }

    i = 0;
    while (argv[3][i] >= '0' && argv[3][i] <= '9') {
        r2 = r2 * 10 + (argv[3][i] - '0');
        i++;
    }

    i = 0;
    while (argv[4][i] >= '0' && argv[4][i] <= '9') {
        c2 = c2 * 10 + (argv[4][i] - '0');
        i++;
    }

    int which_one = str_to_int(argv[5]);
    timed_test((int)r1, (int)c1, (int)r2, (int)c2, 1); // ijk
    timed_test((int)r1, (int)c1, (int)r2, (int)c2, 2); // kij
    timed_test((int)r1, (int)c1, (int)r2, (int)c2, 3); // jki

    return 0;
}










