#include "../include/day6.h"

void change_guard_position(map_t* original, map_t* new_map, int i, int j)
{
    if (i == new_map->guard_x && j == new_map->guard_y) {
        new_map->map[i][j] = original->init_char;
    } else if (i == original->guard_x && j == original->guard_y) {
        new_map->map[i][j] = '.';
    } else {
        new_map->map[i][j] = original->map[i][j];
    }
}

void copy_array(map_t* original, map_t* new_map)
{
    new_map->map = malloc(sizeof(char*) * new_map->rows);
    for (int i = 0; i < new_map->rows; i++) {
        new_map->map[i] = malloc(sizeof(char) * (new_map->cols + 1));
        for (int j = 0; j < new_map->cols; j++) {
            change_guard_position(original, new_map, i, j);
        }
    }
}

void copy_visited(map_t* original, map_t* new_map)
{
    new_map->visited = malloc(sizeof(visited_t*) * new_map->rows);
    for (int i = 0; i < new_map->rows; i++) {
        new_map->visited[i] = malloc(sizeof(visited_t) * new_map->cols);
        for (int j = 0; j < new_map->cols; j++) {
            new_map->visited[i][j].dir = 0;
            new_map->visited[i][j].value = 0;
        }
    }
}

map_t* copy_map(map_t* original)
{
    map_t* new_map = malloc(sizeof(map_t));
    new_map->init_char = original->init_char;
    new_map->rows = original->rows;
    new_map->cols = original->cols;
    new_map->guard_x = original->guard_x_origin;
    new_map->guard_y = original->guard_y_origin;
    new_map->guard_x_origin = original->guard_x_origin;
    new_map->guard_y_origin = original->guard_y_origin;
    copy_array(original, new_map);
    copy_visited(original, new_map);
    return new_map;
}