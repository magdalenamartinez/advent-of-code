#ifndef DAY_6_H
#define DAY_6_H
    #include <stdio.h>
    #include <string.h>    
    #include <stdlib.h>    
    #include <ctype.h>    
    #define BUFFER_SIZE 1024
    #define UP 1
    #define RIGHT 2
    #define DOWN 3
    #define LEFT 4
   
    /*Visited Struct*/
    typedef struct visited {
        int dir;
        int value;
    } visited_t;
    
    /*Map Struct*/
    typedef struct map{
        char** map;
        visited_t** visited;
        int rows;
        int cols;
        int guard_x;
        int guard_x_origin;
        int guard_y_origin;
        int guard_y;
        char init_char;
    } map_t;
    
    /*file.c -> Functions to manipulate the file*/
    int open_file(char* filename);
    char* read_file(FILE* fd, int* line_count);
    char* resize_buffer(char* final_buffer, size_t* final_buffer_size, char* buffer);
    size_t get_file_size(FILE* file);
    
    /*num.c Principal Function*/
    int study_numbers(char* buffer, int line_count);
    map_t* copy_map(map_t* original);
    int try_loop(int i_obs, int j_obs, map_t* original);
    int check_loops(map_t* map);

    /*utilities.c*/
    void rotate_guard(map_t* map);
    void get_next_pos(map_t* map, int* i, int* j, int *dir);
    int is_out(map_t* map, int next_x, int next_y);
    int is_guard(char a);

    /*guard.c -> Guard Functions*/
    int move_guard(map_t* map);
    void move_one(map_t* map, int next_x, int next_y, int i, int j);

    /*memory.c -> Memory Functions*/
    void free_memory(map_t* map);
    map_t* alloc_memory(char* buffer, int line_count);
    void alloc_visited(map_t* map, char* buffer);
    void alloc_array(map_t* map, char* buffer);

    /*copy_map.c -> Copy Map Functions*/
    void change_guard_position(map_t* original, map_t* new_map, int i, int j);
    void copy_array(map_t* original, map_t* new_map);
    void copy_visited(map_t* original, map_t* new_map);
    map_t* copy_map(map_t* original);

#endif /*DAY_6_H*/