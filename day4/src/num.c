#include "../include/day4.h"


int study_numbers(char* buffer, int line_count)
{
    int i = 0;
    char** array_xmas;
    int count = 0;
    int row = 0;
    int col = 0;
    int currentNumber = 0;
    while (buffer[i] != '\n' && buffer[i] != '\0') {
        i++;
    }
    
    XmasArray xmas_data;
    complete_xmas(&xmas_data, line_count, i);
    
    i = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] != '\n') {
            xmas_data.array_xmas[row][col++] = buffer[i];
        } else {
            xmas_data.array_xmas[++row] = malloc(sizeof(char) * xmas_data.ncols);
            col = 0;
        }
        i++;
    }
    find_xmas(&xmas_data);
    int counter = xmas_data.counter;
    free_memory(xmas_data.array_xmas, line_count);
    return counter;
}


void free_memory (char** array_xmas, int line_count)
{
    for (int r = 0; r < line_count; r++) {
        free(array_xmas[r]);
    }
    free(array_xmas);
}