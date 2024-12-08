#include "../include/day2.h"

int study_numbers(char* buffer, int line_count)
{
    int i = 0;
    int** row_num;
    int count = 0;
    int row = 0;
    int col = 0;
    int currentNumber = 0;

    row_num = malloc(sizeof(int*) * line_count);
    int* row_lengths = malloc(sizeof(int) * line_count);
    while (buffer[i] != '\0' && row < line_count) {
        if (isdigit(buffer[i]) && !isdigit(buffer[i + 1])) {
            count++;
        }
        if (buffer[i] == '\n') {
            row_num[row++] = malloc(sizeof(int) * count);
            row_lengths[row - 1] = count;
            if (!row_num[row-1]) {
                exit(EXIT_FAILURE);
            }
            count = 0;
        }
        i++;
    }

    i = 0;
    row = 0;
    while (buffer[i] != '\0' && row < line_count)
    {
        if (isdigit(buffer[i])) {
            currentNumber = currentNumber * 10 + (buffer[i] - '0');
            if (!isdigit(buffer[i + 1]) || buffer[i + 1] == '\n' || buffer[i + 1] == '\0') {
                row_num[row][col++] = currentNumber;
                currentNumber = 0; 
            }
        } 
        if (buffer[i] == '\n') {
            col = 0;
            row++;
        }
        i++;
    }

    int value = make_operation(row_num, row_lengths, line_count);
    free_memory(row_num, row_lengths, line_count);
    return value;
}

int make_operation(int** row_num, int* row_lengths, int line_counts)
{
    int i = 0;
    int counter = 0;
    while (i < line_counts) {
        if (check_row(row_num[i], row_lengths[i])) {
            counter++;
        }
        i++;
    }
    return counter;
}

int is_row_valid (int* row_num, int size)
{
    int is_increasing = (row_num[1] > row_num[0]);
    for (int i = 1; i < size; i++) {
        if ((row_num[i] > row_num[i - 1]) != is_increasing) {
            return 0;
        }
        if (!is_safe_dif(abs(row_num[i] - row_num[i - 1]))) {
            return 0;
        }
    }
    return 1;
}

int is_row_removable(int* row_num, int size, int index)
{
    if (size <= 2) return 0;

    int temp[size - 1];
    int k = 0;

    for (int i = 0; i < size; i++) {
        if (i != index) {
            temp[k++] = row_num[i];
        }
    }

    return is_row_valid(temp, size - 1);
}

int check_row(int* row_num, int size)
{
    if (size < 2) {
        return 0;
    }
    if (is_row_valid(row_num, size)) {
        return 1;
    }
    for (int i = 0; i < size; i++) {
        if (is_row_removable(row_num, size, i)) {
            return 1;
        }
    }
    return 0;
}

int is_safe_dif(int dif) 
{
    return dif >= 1 && dif <= 3;
}

void free_memory (int** row_num, int *row_lengths, int line_count)
{
    for (int r = 0; r < line_count; r++) {
        free(row_num[r]);
    }
    free(row_num);
    free(row_lengths);
}