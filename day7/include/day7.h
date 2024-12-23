#ifndef DAY_7_H
#define DAY_7_H
    #include <stdio.h>
    #include <string.h>    
    #include <stdlib.h>    
    #include <ctype.h>    
    #define BUFFER_SIZE 1024
    
    /*struct numbers*/
    typedef struct num_row {
        long result;
        long* numbers;
        int length;
    } num_row_t;

    typedef struct list_numbers
    {
        num_row_t* num_row;
        int line_count;
    }list_numbers_t;
    

    /*file.c -> Functions to manipulate the file*/
    long long open_file(char* filename);
    char* read_file(FILE* fd, int* line_count);
    char* resize_buffer(char* final_buffer, size_t* final_buffer_size, char* buffer);
    size_t get_file_size(FILE* file);

    /*numbers.c*/
    long long study_numbers(char* buffer, int line_count);
    void set_numbers(list_numbers_t* list_numbers, char* buffer);

    /*utilities.c*/
    int try_operation(int i, int j);
    long long is_the_number(list_numbers_t* list_numbers, int row);
    long long make_comparison(list_numbers_t* list_numbers); 
    
    /*memory.c -> Functions to allocate memory*/
    void free_list_numbers(list_numbers_t* list_numbers);
    list_numbers_t* alloc_memory(char* buffer, int line_count);
    void alloc_num_row(list_numbers_t* list_numbers, char* buffer);


#endif /*DAY_7_H*/

//14634335617
//14634335617