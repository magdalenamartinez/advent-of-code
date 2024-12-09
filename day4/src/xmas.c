#include "../include/day4.h"


int find_xmas(XmasArray* xmas_data)
{
    for (int i = 0; i < xmas_data->nrows; i++) {
        for (int j = 0; j < xmas_data->ncols; j++) {
            check_X(xmas_data, i, j);
        }
    }
    return xmas_data->counter;
}

void check_X(XmasArray* xmas_data, int i, int j)
{
    if (xmas_data->array_xmas[i][j] == 'X') {
        for (int k = 0; k < 8; k++) {
            recursive_xmas(xmas_data, i, j, 0, k);
        }
    }
}

void xmas_choose(int *i, int *j, int sentido)
{
    switch (sentido) {
        case 0: (*i)--; break;
        case 1: (*i)++; break;
        case 2: (*j)--; break;
        case 3: (*j)++; break;
        case 4: (*i)--; (*j)--; break;
        case 5: (*i)++; (*j)++; break;
        case 6: (*i)--; (*j)++; break;
        case 7: (*i)++; (*j)--; break;
    }
}

char getValueChar(int value)
{
    const char *array = "XMAS";
    return array[value];
}

void recursive_xmas(XmasArray* xmas_data, int i, int j, int letter, int sentido)
{
    xmas_choose(&i, &j, sentido);
    if (isValid(i, j, xmas_data->nrows, xmas_data->ncols) &&
        getValueChar(letter + 1) == xmas_data->array_xmas[i][j]) {
        if (letter + 1 == 3) {
            xmas_data->counter++;
        } else {
            recursive_xmas(xmas_data, i, j, letter + 1, sentido);
        }
    }
}

void complete_xmas(XmasArray* xmas_data, int rows, int cols)
{
    xmas_data->nrows = rows;
    xmas_data->ncols = cols;
    xmas_data->counter = 0;
    xmas_data->array_xmas = malloc(sizeof(char*) * rows);
    xmas_data->array_xmas[0] = malloc(sizeof(char) * xmas_data->ncols);
}