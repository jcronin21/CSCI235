#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix matrix_multiply(Matrix A, Matrix B) {
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

/*
main()
{
	Matrix m1 = create_matrix(2, 2);
	m1.data[0][0] = 2;
	m1.data[0][1] = 4;
	m1.data[1][0] = 6;
	m1.data[1][1] = 8;

	printf("Printing input matrix 1..\n");
	print_matrix(m1);

	Matrix m2 = create_matrix(2, 2);
	m2.data[0][0] = 1;
	m2.data[0][1] = 2;
	m2.data[1][0] = 3;
	m2.data[1][1] = 4;

	printf("Printing input matrix 2..\n");
	print_matrix(m2);

	printf("Printing output matrix r1..\n");
	Matrix r1 = matrix_multiply(m1, m2);
	print_matrix(r1);

	Matrix m3 = create_matrix(2, 3);
	m3.data[0][0] = 1;
	m3.data[0][1] = 2;
	m3.data[0][2] = 3;
	m3.data[1][0] = 4;
	m3.data[1][1] = 5;
	m3.data[1][2] = 6;

	printf("Printing input matrix m3..\n");
	print_matrix(m3);

	Matrix r2 = matrix_multiply(m1, m3);
	printf("Printing output matrix r2..\n");
	print_matrix(r2);
}
*/
