#include "../include/day9.h"

int* get_array(size_t total_size, disk_t* disk, int* pos)
{
   
    int* array = malloc(total_size);
    if (array == NULL) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < disk->num_files; i++){
        for (int j = 0; j < disk->files[i].length; j++) {
            array[(*pos)++] = disk->files[i].id;
        }
        for (int j = 0; j < disk->files[i].free_length; j++) {
            array[(*pos)++] = -1;
        }
    } 

    int i = 0;
    return array;
}

void set_num(int* array, int numBefore, int length, int numToMove, int last)
{
    int i = 0, first_pos = -1, last_pos = -1;

    while (i < last && (first_pos == -1 || last_pos == -1)) {
        if (array[i] == numBefore && first_pos == -1) {
            first_pos = i;
            while (array[first_pos] != -1) {
                first_pos++;
            }
        } else if (array[i] == numToMove && last_pos == -1) {
            last_pos = i;
        }
        i++;
    }

    i = 0;
    while (i < length) {
        array[first_pos++] = numToMove;
        array[last_pos++] = -1;
        i++;
    }
}

void sort_array(int pos, int* array, disk_t* disk)
{
    int j = 0, found = -1;

    for (int i = disk->num_files - 1; i > 0; i--) {
        found = -1;
        j = 0;
        while (found == -1 && j < disk->num_files && i > j) {
            if (disk->files[j].free_length >= disk->files[i].length) {
                disk->files[j].free_length -= disk->files[i].length;
                found = j;
                set_num(array, j, disk->files[i].length, i, pos);
            }
            j++;
        }
    }
}

