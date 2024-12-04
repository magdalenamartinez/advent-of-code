#ifndef MINES_GAMES_H
#define MINES_GAMES_H
  
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
    int make_operation(int* left_array, int* right_array, int leftCount, int rightCount);

#endif /*MINES_GAMES_H*/