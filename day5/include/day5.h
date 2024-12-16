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
    typedef struct values {
        int num;
        int pos;
    } values_t;
    typedef struct updates {
        values_t* array;
        int len;
    } updates_t;
    int** init_rules(int num_rules);
    int** create_rules(char* buffer, int num_rules);
    void free_memory (int** rules, int num_rules, updates_t* updates, int n_upd);
    void sort_updates(updates_t* updates, int n_upd);
    updates_t* create_updates_struct(char* buffer, int init, int* n_upd);
    int get_n_elements_update(char* buffer, int* i, int num);
    int get_pos(int num, updates_t *updates, int i);
    void read(int n_upd, updates_t* updates);
    void get_numbers(char* buffer, int i, updates_t* updates);
    int get_n_upd(char* buffer, int i);
    int get_n_elements_update(char* buffer, int* i, int num);
    updates_t* create_updates_struct(char* buffer, int init, int* n_upd);
    void set_mem_elements(char* buffer, int i, updates_t* updates);
    int compare_positions(int n_upd, updates_t* updates, int num_rules, int** rules);
    int get_num_rules(char* buffer, int* i);
    int set_correct(updates_t* updates, int i, int num_rules, int** rules);
    int change_pos(int num, updates_t *updates, int i, int* k);
    int get_middle(updates_t* updates, int i);
    void swipe_pos(updates_t* updates, int i, int p1, int p2);

#endif /*DAY_5_H*/