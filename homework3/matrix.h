#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix{
     unsigned rows;
     unsigned columns;
     double **data;

}Matrix;

typedef struct matrix Matrix;

Matrix create_matrix(unsigned rows, unsigned columns);
void print_matrix(Matrix matrix);
void free_matrix(Matrix matrix);




#endif
