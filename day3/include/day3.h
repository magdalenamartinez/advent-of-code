#ifndef DAY_3_H
#define DAY_3_H
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
    int getNumber (const char** currentPointer, int* i, int* counter);
#endif /*DAY_3_H*/