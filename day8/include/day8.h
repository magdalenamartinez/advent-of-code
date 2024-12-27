#ifndef DAY_8_H
#define DAY_8_H
    #include <stdio.h>
    #include <string.h>    
    #include <stdlib.h>    
    #include <ctype.h>    
    #define BUFFER_SIZE 1024
    
    /*struct antinode*/
    typedef struct antinode {
        int r;
        int c;
    } antinodes_t;

    /*struct frequency*/
    typedef struct frequency {
        char character;
        int counter;
        antinodes_t* antinodes;
    } frequencies_t;

    /*struct map*/
    typedef struct general
    {
        char** map;
        int** antinodes_map;
        frequencies_t* frequencies;
        int num_frequencies;
        int rows;
        int cols;
    }general_t;
    

    /*file.c -> Functions to manipulate the file*/
    int open_file(char* filename);
    char* read_file(FILE* fd, int* line_count);
    char* resize_buffer(char* final_buffer, size_t* final_buffer_size, char* buffer);
    size_t get_file_size(FILE* file);

    /*numbers.c*/
    void set_general(general_t* general, char* buffer);
    int study_numbers(char* buffer, int line_count);

    /*memory.c*/
    general_t* alloc_general(char* buffer, int line_count);
    void alloc_maps(general_t* general, int pos);
    void init_frequency(general_t* general, char value, int row, int col);
    void set_frequency(general_t* general, int f, int row, int col);
    void free_memory(general_t* general);

    /*utilities.c*/
    void set_value(general_t* general, char value, int row, int col);
    int notRead(char value, char* read, int size);
    int posRead(char value, char* read, int size);
    int get_cols(char* buffer);

    /*antinodes.c*/
    void get_antinodes_frequency(general_t* general, int freq);
    int get_antinodes(general_t* general);
    //void try_antinode(general_t* general, int x, int y, int freq); //First Part
    void try_antinode(general_t* general, int x, int difX, int y, int difY, int freq);


#endif /*DAY_8_H*/

//14634335617
//14634335617