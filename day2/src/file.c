#include "../include/day2.h"


int open_file(char* filename) 
{
    FILE *fd = fopen(filename, "r");
    if (fd == NULL) {
        exit(EXIT_FAILURE);
    }
    int line_count = 0;
    char *buffer = read_file(fd, &line_count);
    return study_numbers(buffer, line_count);
}

char* read_file(FILE* fd, int *line_count)
{
    ssize_t read;
    size_t len = 0;
    char* buffer = NULL;
    size_t final_buffer_size = BUFFER_SIZE;

    size_t size = get_file_size(fd);
    char* final_buffer = malloc(size + 1);
    if (final_buffer == NULL) {
        exit(EXIT_FAILURE);
    }

    size_t offset = 0;
    while ((read = getline(&buffer, &len, fd)) != -1) {
        memcpy(final_buffer + offset, buffer, read);
        offset += read;
        (*line_count)++;
    }
    final_buffer[offset] = '\0';
    free(buffer);

    return final_buffer;
}

char* resize_buffer(char* final_buffer, size_t* final_buffer_size, char* buffer) 
{
    if (strlen(final_buffer) + strlen(buffer) + 1 > *final_buffer_size) {
            *final_buffer_size += strlen(buffer) + BUFFER_SIZE;
            final_buffer = realloc(final_buffer, *final_buffer_size);
    }
    return final_buffer;
} 


size_t get_file_size(FILE* file) 
{
    fseek(file, 0, SEEK_END);  
    size_t size = ftell(file);
    rewind(file);
    return size;
}

    


