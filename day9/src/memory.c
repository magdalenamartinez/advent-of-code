#include "../include/day9.h"

disk_t* alloc_disk(char* buffer)
{
    disk_t* disk = malloc(sizeof(disk_t));
    disk->files = malloc(sizeof(file_t));
    disk->num_files = 0;

    read_disk(buffer, disk);
    return disk;
}

void read_disk(char* buffer, disk_t* disk)
{
    int num = 0, i = 0;
    while (buffer[i] != '\0') {
        if (i % 2 == 0) {
            disk->files[disk->num_files].id= num;
            disk->files[disk->num_files].length = buffer[i] - '0';
        } else {
            if (!isdigit(buffer[i])) {
                disk->files[disk->num_files].free_length = 0;    
                num++; disk->num_files++;
            } else {
                disk->files[disk->num_files].free_length = buffer[i] - '0';
                num++; disk->num_files++;
                disk->files = realloc(disk->files, sizeof(file_t) * (disk->num_files + 1));
            }
        }
        i++;
    }
}

size_t get_total_size(disk_t* disk)
{
    size_t total_size = 0;
    for (int i = 0; i < disk->num_files; i++) {
        total_size += sizeof(int) * (disk->files[i].length + disk->files[i].free_length);
    }
    return total_size;
}

