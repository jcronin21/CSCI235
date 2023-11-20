#include <stdio.h>
#include "matrix.h"
#include "import_data.h"
#include "write_pgm.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    Matrix matrix = import_data(argv[1]);
    if (matrix.data == NULL) {
        printf("Error reading input file.\n");
        return 1;
    }

    write_pgm(matrix, argv[2]);

    for (unsigned i = 0; i < matrix.rows; ++i) {
        free(matrix.data[i]);
    }
    
    free(matrix.data);

    return 0;
}
