#include "../include/day6.h"

map_t* alloc_map(char* buffer)
{
    map_t* map = malloc(sizeof(map_t));
    map->guard_i = 0, map->guard_j = 0;
    map->rows = 0, map->cols = 0;
    int i = 0;
    
    while (buffer[i++] != '\n') {
        map->cols++;
    }

    i = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            map->rows++;
        }
        i++;
    }
    map->rows++;
    alloc_array(map, buffer);
    return map;
}


void alloc_array(map_t* map, char* buffer)
{
    int row = 0, col = 0, i = 0;

    map->array = malloc(sizeof(char*) * map->rows);
    map->visited = malloc(sizeof(char*) * map->rows);
    map->array[row] = malloc(sizeof(char) * (map->cols + 1));
    map->visited[row] = malloc(sizeof(char) * (map->cols + 1));

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            map->array[row][col] = '\0';
            row++;
            map->array[row] = malloc(sizeof(char) * (map->cols + 1));
            map->visited[row] = malloc(sizeof(char) * (map->cols + 1));
            col = 0;
        } else {
            if (buffer[i] == 'v' || buffer[i] == '^' || buffer[i] == '<' || buffer[i] == '>') {
                map->guard_i = row, map->guard_j = col;
            }
            map->array[row][col] = buffer[i];
            map->visited[row][col] = '.';
            col++;
        }
        i++;
    }

}

void free_memory(map_t* map)
{
    for (int i = 0; i < map->rows; i++) {
        free(map->visited[i]);
        free(map->array[i]);
    }
    free(map->array);
    free(map->visited);
    free(map);
}
   