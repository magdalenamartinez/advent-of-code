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
    return array;
}

void swap_pos(int* array, int first_pos, int last_pos)
{
    int temp = array[first_pos];
    array[first_pos] = array[last_pos];
    array[last_pos] = temp;
}

void sort_array(int pos, int* array)
{
    int first = 0, last = pos - 1;
    int first_pos = -1, last_pos = -1;

    while (first < last) {
        if (array[first] == -1) {
            first_pos = first;
        } else {
            first++;
        }
        if (array[last] != -1) {
            last_pos = last;
        } else {
            last--;
        }
        if (first_pos != -1 && last_pos != -1) {
            swap_pos(array, first_pos, last_pos);
            first_pos = -1; last_pos = -1;
            first++; last--;
        }
    }
}