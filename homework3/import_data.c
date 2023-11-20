#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "import_data.h"

double help_funct(const char *str);

Matrix import_data(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        Matrix emptyMatrix = {0, 0, NULL};
        return emptyMatrix;
    }

    char line[500];
    unsigned rows = 0;
    unsigned columns = 0;
    double **data = NULL;

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, " \n");
        while (token != NULL) {
            double value = help_funct(token);

            if (columns == 0) {
                data = (double**)realloc(data, (rows + 1) * sizeof(double*));
            }

            data[rows] = (double*)realloc(data[rows], (columns + 1) * sizeof(double));
            data[rows][columns] = value;

            columns++;
            token = strtok(NULL, " \n");
        }

        rows++;
        columns = 0;
    }

    fclose(file);

    Matrix result = {rows, (data != NULL) ? columns : 0, data};
    return result;
}

double help_funct(const char *str) {
    double result = 0.0;
    double decimal = 0.1;
    int sign = 1;
    int tracker = 0;

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            result = result * 10.0 + (*str - '0');
            if (tracker) {
                decimal *= 0.1;
            }
        } else if (*str == '.') {
            tracker = 1;
        }
        str++;
    }

    return sign * result * decimal;
}
