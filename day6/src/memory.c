#include "../include/day6.h"

void alloc_array(map_t* map, char* buffer)
{
    int i = 0, row = 0, col = 0;
    map->map = malloc(sizeof(char*) * map->rows);
    map->map[0] = malloc(sizeof(char) * (map->cols + 1));

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            map->map[row][col] = '\0';
            row++;
            map->map[row] = malloc(sizeof(char) * (map->cols + 1));
            col = 0;
        } else {
            if (is_guard(buffer[i])) {
                map->guard_x_origin = row, map->guard_y_origin = col;
                map->guard_x = row, map->guard_y = col;
                map->init_char = buffer[i];
            }
            map->map[row][col] = buffer[i];
            col++;
        }
        i++;
    }
}

void alloc_visited(map_t* map, char* buffer)
{
    map->visited = malloc(sizeof(visited_t*) * map->rows);
    for (int i = 0; i < map->rows; i++) {
        map->visited[i] = malloc(sizeof(visited_t) * map->cols);
    }
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            if (map->map[i][j] == '#' || is_guard(map->map[i][j] )) {
                map->visited[i][j].dir = 0;
                map->visited[i][j].value = 7;
            } else {
                map->visited[i][j].dir = 0;
                map->visited[i][j].value = 0;
            }
        }
    }
}

map_t* alloc_memory(char* buffer, int line_count)
{
    int i = 0;
    map_t* map = malloc(sizeof(map_t));
    map->rows = line_count, map->cols = 0;
    map->guard_x = 0, map->guard_y = 0;
    while (buffer[i] != '\n') {
        map->cols++;
        i++;
    }
    alloc_array(map, buffer);
    return map;
}

void free_memory(map_t* map)
{
    for (int i = 0; i < map->rows; i++) {
        free(map->visited[i]);
        free(map->map[i]);
    }
    free(map->map);
    free(map->visited);
    free(map);
} 