#include "../include/day6.h"

void move_one(map_t* map, int next_x, int next_y, int i, int j)
{
    map->map[next_x][next_y] = map->map[i][j];
    map->map[i][j] = '.';
    map->guard_x = next_x;
    map->guard_y = next_y;
}

int move_guard(map_t* map)
{
    int dir = 0, end = 0, counter = 1, rotations = 0;
    int i = map->guard_x, j = map->guard_y;
    while (!end) {
        int next_x = i, next_y = j;
        get_next_pos(map, &next_x, &next_y, &dir);
        if (is_out(map, next_x, next_y)){
            end = 1;
        } else if (map->map[next_x][next_y] == '#'){
            rotate_guard(map);
            if (rotations > 3) {
                exit(EXIT_FAILURE);
            } 
            rotations++;
        } else {
            rotations = 0;
            move_one(map, next_x, next_y, i, j);
            if (map->visited[next_x][next_y].value == 0) {
                counter++;
                map->visited[next_x][next_y].value = 1;
            } 
            i = next_x; j = next_y;
        }
    } 
    return counter;
}