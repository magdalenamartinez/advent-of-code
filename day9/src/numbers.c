#include "../include/day9.h"

long long study_numbers(char* buffer, int line_count)
{
    long long counter = 0;
    int pos = 0, i = 0;
    
    disk_t* disk = alloc_disk(buffer);
    size_t total_size = get_total_size(disk);
    int* array = get_array(total_size, disk, &pos);
    sort_array(pos, array);
   
    while (array[i] != -1 && i < pos) {
        counter += ((array[i]) * i);
        i++;
    }
    return counter;
}
