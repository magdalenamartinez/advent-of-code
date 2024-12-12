#ifndef DAY_5_H
#define DAY_5_H
    #include <stdio.h>
    #include <string.h>    
    #include <stdlib.h>    
    #include <ctype.h>    
    #define BUFFER_SIZE 1024
    int open_file(char* filename);
    char* read_file(FILE* fd, int* line_count);
    char* resize_buffer(char* final_buffer, size_t* final_buffer_size, char* buffer);
    size_t get_file_size(FILE* file);
    int study_numbers(char* buffer, int line_count);
    void free_memory (char** array_xmas, int line_count);
    //int isValid(int i, int j, int maxRows, int maxCols);
    typedef struct {
        char** array_xmas;
        int ncols;        
        int nrows;         
        int counter;
    } XmasArray;
    int find_xmas(XmasArray* xmas_data);
    void xmas_choose(int *i, int *j, int sentido);
    char getValueChar(int value);
    void recursive_xmas(XmasArray* xmas_data, int i, int j, int letter, int sentido);
    void remove_xmas(XmasArray* xmas_data, int i, int j, int sentido);
    void complete_xmas(XmasArray* xmas_data, int rows, int cols);
    int check_A(XmasArray* xmas_data, int i, int j);
    int isValid(char value, int i, int j, XmasArray* xmas_data);
    int check_pattern(XmasArray* xmas_data, int i, int j);
    void get_values(int *i, int *j, int k);
#endif /*DAY_5_H*/