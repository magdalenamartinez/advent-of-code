#include "../include/day6.h"

int is_guard(char a)
{
    if (a == '<' || a == '>' || a == 'v' || a == '^') {
        return 1;
    }
    return 0;
}
 
int is_out(map_t* map, int next_x, int next_y) 
{
    if (next_x < 0 || next_x >= map->rows || next_y < 0 || next_y >= map->cols) {
        return 1;
    }
    return 0;
}

void get_next_pos(map_t* map, int* i, int* j, int *dir)
{
    switch (map->map[map->guard_x][map->guard_y]) {
        case '^': (*i)--; *(dir) = UP; break;
        case '>': (*j)++; *(dir) = RIGHT; break;
        case 'v': (*i)++; *(dir) = DOWN; break;
        case '<': (*j)--; *(dir) = LEFT; break;
    }
}

void rotate_guard(map_t* map)
{
    switch (map->map[map->guard_x][map->guard_y]) {
        case '^': map->map[map->guard_x][map->guard_y] = '>'; break;
        case '>': map->map[map->guard_x][map->guard_y] = 'v'; break;
        case 'v': map->map[map->guard_x][map->guard_y] = '<'; break;
        case '<': map->map[map->guard_x][map->guard_y] = '^'; break;
    }
}