#ifndef DAY_10_H
#define DAY_10_H
    #include <stdio.h>
    #include <string.h>    
    #include <stdlib.h>    
    #include <ctype.h>    
    #define BUFFER_SIZE 1024

    /*file.c -> Functions to manipulate the file*/
    long long open_file(char* filename);
    char* read_file(FILE* fd, int* line_count);
    char* resize_buffer(char* final_buffer, size_t* final_buffer_size, char* buffer);
    size_t get_file_size(FILE* file);

    /*numbers.c*/
    long long study_numbers(char* buffer, int line_count);

#endif /*DAY_10_H*/
