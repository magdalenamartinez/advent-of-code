#include "../include/day8.h"

void set_general(general_t* general, char* buffer)
{
    int i = 0, row = 0, col = 0, size = 0;
    char* read = NULL;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            row++;
            col = 0;
        } else {
            if (buffer[i] != '.' && notRead(buffer[i], read, size)) {
                read = realloc(read, sizeof(char) * (size + 2));
                read[size] = buffer[i];
                size++;
                init_frequency(general, buffer[i], row, col);
            } else if (buffer[i] != '.' && !notRead(buffer[i], read, size)) {
                int f = posRead(buffer[i], read, size);
                set_frequency(general, f, row, col);
            }
            set_value(general, buffer[i], row, col);
            col++;
        }
        i++;
    }
}

int study_numbers(char* buffer, int line_count)
{
    general_t* general = alloc_general(buffer, line_count);

    set_general(general, buffer);

    int counter = get_antinodes(general);
    free_memory(general);
    return counter;
}
