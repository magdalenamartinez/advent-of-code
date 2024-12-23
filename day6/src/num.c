#include "../include/day6.h"

int study_numbers(char* buffer, int line_count)
{
    int second_part = 0;
    map_t* map = alloc_memory(buffer, line_count);
    alloc_visited(map, buffer);
    int first_part = move_guard(map);
    second_part = check_loops(map);
    printf("First Part: %i, Second Part: %i", first_part, second_part);
    free_memory(map);
    return second_part;
}


