#ifndef DAY_2_H
#define DAY_2_H
    #include <stdio.h>
    #include <string.h>    
    #include <stdlib.h>    
    #include <ctype.h>    
    #define BUFFER_SIZE 1024
    int open_file(char* filename);
    char* read_file(FILE* fd, int* line_count);
    char* resize_buffer(char* final_buffer, size_t* final_buffer_size, char* buffer);
    int study_numbers(char* buffer, int line_count);
    int find_min(int* array, int* size);
    size_t get_file_size(FILE* file);
    int check_row(int* row_num, int size);
    int make_operation(int** row_num, int* row_lengths, int line_counts);
    int is_safe_dif(int dif);
    void free_memory (int** row_num, int line_count);
#endif /*DAY_2_H*/