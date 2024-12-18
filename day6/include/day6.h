#ifndef DAY_6_H
#define DAY_6_H
    #include <stdio.h>
    #include <string.h>    
    #include <stdlib.h>    
    #include <ctype.h>    
    #define BUFFER_SIZE 1024
   
    /*Map Struct*/
    typedef struct map{
        char** array;
        char** visited;
        int rows;
        int cols;
        int guard_i;
        int guard_j;
    } map_t;
    
    /*file.c -> Functions to manipulate the file*/
    int open_file(char* filename);
    char* read_file(FILE* fd, int* line_count);
    char* resize_buffer(char* final_buffer, size_t* final_buffer_size, char* buffer);
    size_t get_file_size(FILE* file);
    
    /*num.c Principal Function*/
    int study_numbers(char* buffer, int line_count);

    /*guard.c -> Guard Functions*/
    void rotate_guard(map_t* map);
    void move_guard(map_t* map);
    void get_next_pos(map_t* map, int* i, int* j);
    void move_one(map_t* map, int next_i, int next_j, int i, int j);

    /*memory.c -> Memory Functions*/
    map_t* alloc_map(char* buffer);
    void alloc_array(map_t* map, char* buffer);
    void free_memory(map_t* map);



void check_others(map_t* map, int i, int j);
    

#endif /*DAY_6_H*/