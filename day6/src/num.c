#include "../include/day6.h"

int study_numbers(char* buffer, int line_count)
{
    int counter = 0;
    map_t* map = alloc_map(buffer);
    move_guard(map);
    
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            if (map->visited[i][j] == 'v') {
                counter++;
            }
        }
    }
    
    free_memory(map);
    return counter;
}
