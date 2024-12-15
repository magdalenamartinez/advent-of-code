#include "../include/day5.h"


int find_xmas(XmasArray* xmas_data)
{
    for (int i = 0; i < xmas_data->nrows; i++) {
        for (int j = 0; j < xmas_data->ncols; j++) {
            xmas_data->counter += check_A(xmas_data, i, j);
        }
    }
    return xmas_data->counter;
}

int check_A(XmasArray* xmas_data, int i, int j)
{
    if (xmas_data->array_xmas[i][j] == 'A') {
        return check_pattern(xmas_data, i, j);
    }
    return 0;
}

int check_pattern(XmasArray* xmas_data, int i, int j)
{
    if (i <=0 || j<=0 || i > xmas_data->nrows || j > xmas_data->ncols) {
        return 0;
    }
    char value1_1 = xmas_data->array_xmas[i - 1][j - 1];
    char value1_2 = xmas_data->array_xmas[i + 1][j + 1];
    char value2_1 = xmas_data->array_xmas[i - 1][j + 1];
    char value2_2 = xmas_data->array_xmas[i + 1][j - 1];

    if (!isValid(value1_1, i - 1, j - 1, xmas_data) || !isValid(value1_2, i + 1, j + 1, xmas_data)) {
        return 0;
    }
    if (!isValid(value2_1, i - 1, j + 1, xmas_data) || !isValid(value2_2, i + 1, j - 1, xmas_data)) {
        return 0;
    }

    if (value1_1 != value1_2 && value2_1 != value2_2) {
        return 1;
    }

    return 0;
}

int isValid(char value, int i, int j, XmasArray* xmas_data)
{
    if (i >=0 && j>=0 && i < xmas_data->nrows && j < xmas_data->ncols) {
        if (value == 'M' || value == 'S') {
            return 1;
        }
    }
    return 0;
}

void complete_xmas(XmasArray* xmas_data, int rows, int cols)
{
    xmas_data->nrows = rows;
    xmas_data->ncols = cols;
    xmas_data->counter = 0;
    xmas_data->array_xmas = malloc(sizeof(char*) * rows);
    xmas_data->array_xmas[0] = malloc(sizeof(char) * xmas_data->ncols);
}