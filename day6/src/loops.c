#include "../include/day6.h"

void change_visited(map_t* map, int i, int j, int* end, int dir)
{
    if (map->visited[i][j].value == 0) {
        map->visited[i][j].value = 1;
        map->visited[i][j].dir = dir;
    } else if (map->visited[i][j].dir == dir) {
        *end = 2;
    }
}

int try_loop(int i_obs, int j_obs, map_t* original) 
{
    map_t* map = copy_map(original);
    map->map[i_obs][j_obs] = '#';
    int end = 0, rotations = 0, dir = 0;
    int i = map->guard_x_origin, j = map->guard_y_origin;

    while (end < 1) {
        int next_x = i, next_y = j;
        get_next_pos(map, &next_x, &next_y, &dir);
        if (is_out(map, next_x, next_y)){
            end = 1;
        } else if (map->map[next_x][next_y] == '#'){
            rotate_guard(map);
            rotations++;
            if (rotations > 3) {
                end = 2;
            }
        } else {
            rotations = 0;
            move_one(map, next_x, next_y, i, j);
            change_visited(map, i, j, &end, dir);
            i = next_x; j = next_y;
        }
    }
    free_memory(map); 
    return end == 2? 1:0;
}

int check_loops(map_t* map) 
{
    int counter = 0;
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            if (map->visited[i][j].value == 1) {
                counter += try_loop(i, j, map);
            }
        }
    }
    return counter;
}