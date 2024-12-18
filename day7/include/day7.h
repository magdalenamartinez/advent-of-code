#ifndef DAY_7_H
#define DAY_7_H
    #include <stdio.h>
    #include <string.h>    
    #include <stdlib.h>    
    #include <ctype.h>    
    #define BUFFER_SIZE 1024
    
    /*file.c -> Functions to manipulate the file*/
    int open_file(char* filename);
    char* read_file(FILE* fd, int* line_count);
    char* resize_buffer(char* final_buffer, size_t* final_buffer_size, char* buffer);
    size_t get_file_size(FILE* file);
    
    /*num.c Principal Function*/
    int study_numbers(char* buffer, int line_count);

#endif /*DAY_7_H*/