#ifndef DAY_9_H
#define DAY_9_H
    #include <stdio.h>
    #include <string.h>    
    #include <stdlib.h>    
    #include <ctype.h>    
    #define BUFFER_SIZE 1024

    typedef struct file {
        int id;
        int length; //numbers
        int free_length; //points
    } file_t;


    typedef struct disk {
        file_t* files;
        int num_files;
    } disk_t;

    /*file.c -> Functions to manipulate the file*/
    long long open_file(char* filename);
    char* read_file(FILE* fd, int* line_count);
    char* resize_buffer(char* final_buffer, size_t* final_buffer_size, char* buffer);
    size_t get_file_size(FILE* file);

    /*numbers.c*/
    long long study_numbers(char* buffer, int line_count);

    /*memory.c*/
    disk_t* alloc_disk(char* buffer);
    void read_disk(char* buffer, disk_t* disk);
    size_t get_total_size(disk_t* disk);

    /*array.c*/
    int* get_array(size_t total_size, disk_t* disk, int* pos);
    void swap_pos(int* array, int first_pos, int last_pos);
    void sort_array(int pos, int* array);


#endif /*DAY_9_H*/
