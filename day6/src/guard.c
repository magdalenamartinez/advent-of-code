#include "../include/day6.h"

void move_guard(map_t* map) 
{
    int end = 0;
    int i = map->guard_i, j = map->guard_j; 

    while (!end) {
        int next_i = i, next_j = j;
        get_next_pos(map, &next_i, &next_j);

        if (next_i < 0 || next_i >= map->rows || next_j < 0 || next_j >= map->cols) {
            end = 1;
        } else if (map->array[next_i][next_j] == '#') {
            rotate_guard(map);
        } else {
            move_one(map, next_i, next_j, i, j);
            map->visited[i][j] = 'v';
            i = next_i, j = next_j;
        }

    }
}

void rotate_guard(map_t* map)
{
    switch (map->array[map->guard_i][map->guard_j])
    {
        case '^': map->array[map->guard_i][map->guard_j] = '>'; break;
        case '>': map->array[map->guard_i][map->guard_j] = 'v'; break;
        case 'v': map->array[map->guard_i][map->guard_j] = '<'; break;
        case '<': map->array[map->guard_i][map->guard_j] = '^'; break;
    }
}

void move_one(map_t* map, int next_i, int next_j, int i, int j)
{
    map->array[next_i][next_j] = map->array[i][j];
    map->array[i][j] = '.';
    map->guard_i = next_i;
    map->guard_j = next_j;
}

void get_next_pos(map_t* map, int* i, int* j)
{
    switch (map->array[map->guard_i][map->guard_j])
    {
        case '^': (*i)--; break;
        case '>': (*j)++; break;
        case 'v': (*i)++; break;
        case '<': (*j)--; break;
    }
}
