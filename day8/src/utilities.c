#include "../include/day8.h"

int notRead(char value, char* read, int size)
{   
    int i = 0;
    while (i < size) {
        if (value == read[i]) {
            return 0;
        }
        i++;
    }
    return 1;
    
}

int posRead(char value, char* read, int size)
{
    int i = 0;
    while (i < size) {
        if (value == read[i]) {
            return i;
        }
        i++;
    }
    return -1;
}

int get_cols(char* buffer)
{
    int i = 0;
    while (buffer[i] != '\n') {
        i++;
    }
    return i;
}


void set_value(general_t* general, char value, int row, int col)
{
    if (row < general->rows && col < general->cols && row >= 0 && col >=0) {
        general->antinodes_map[row][col] = 0;
        general->map[row][col] = value;
    }
    
}