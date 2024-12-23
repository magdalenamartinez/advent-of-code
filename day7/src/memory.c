#include "../include/day7.h"

list_numbers_t* alloc_memory(char* buffer, int line_count)
{
    list_numbers_t* list_numbers = malloc(sizeof(list_numbers_t));
    if (list_numbers == NULL) {
        exit(EXIT_FAILURE);
    }
    list_numbers->line_count = line_count;
    list_numbers->num_row = malloc(sizeof(num_row_t) * line_count);
    if (list_numbers->num_row == NULL) {
        free_list_numbers(list_numbers);
        exit(EXIT_FAILURE);
    }

    alloc_num_row(list_numbers, buffer);
    set_numbers(list_numbers, buffer);

    return list_numbers;
}

void alloc_num_row(list_numbers_t* list_numbers, char* buffer)
{
    int i = 0, found = 0, row = 0, col = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            found = 0;
            list_numbers->num_row[row].result = 0;
            list_numbers->num_row[row].length = col;
            list_numbers->num_row[row].numbers = malloc(sizeof(long) * col);
            if (list_numbers->num_row[row].numbers == NULL) {
                free_list_numbers(list_numbers);
                exit(EXIT_FAILURE);
            }
            row++;
            col = 0;
        } else if (isdigit(buffer[i]) && !isdigit(buffer[i + 1]) ) {
            if (!found) {
                found = 1;
            } else {
                col++;
            }
        }
        i++;
    }

    for (int r = 0; r < list_numbers->line_count; r++) {
        for (int c = 0; c < list_numbers->num_row[r].length; c++) {
            list_numbers->num_row[r].numbers[c] = 0;
        }
    }
    
}

void free_list_numbers(list_numbers_t* list_numbers)
{
    for (int i = 0; i < list_numbers->line_count; i++) {
        free(list_numbers->num_row[i].numbers);
    }
    free(list_numbers->num_row);
    free(list_numbers);
}