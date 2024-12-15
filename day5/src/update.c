#include "../include/day5.h"

int get_n_upd(char* buffer, int i)
{
    int n_upd = 1, counter = 1;
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            n_upd++;
        }
        i++;
    }
    return n_upd;
}

int get_n_elements_update(char* buffer, int* i, int num)
{
    while (buffer[*(i)] != '\n' && buffer[*(i)] != '\0') {
        if (buffer[*(i)] == ','){
            num++;
        }
        (*i)++;
    }
    return num;
}

updates_t* create_updates_struct(char* buffer, int init, int* n_upd)
{   
    *n_upd = get_n_upd(buffer, init);
    updates_t* updates = malloc(sizeof(updates_t) * (*n_upd));
    if (updates == NULL) {
        exit(EXIT_FAILURE);
    }
    set_mem_elements(buffer, init, updates);
    get_numbers(buffer, init, updates);
    sort_updates(updates, *(n_upd));
    return updates;
}

void set_mem_elements(char* buffer, int i, updates_t* updates) {
    int n_upd = 0, counter = 1;
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            updates[n_upd].array = malloc(sizeof(values_t) * counter);
            if (updates[n_upd].array == NULL) {
                exit(EXIT_FAILURE);
            }
            updates[n_upd].len = counter;
            counter = 1;
            n_upd++;
        } else if (buffer[i] == ',') {
            counter++;
        }
        i++;
    }
    updates[n_upd].array = malloc(sizeof(values_t) * counter);
    if (updates[n_upd].array == NULL) {
        exit(EXIT_FAILURE);
    }
    updates[n_upd].len = counter;
}

void get_numbers(char* buffer, int i, updates_t* updates)
{
    int n_upd = 0, n = 0, pos = 0;
    updates[n_upd].array[n].num = 0;
    while (buffer[i] != '\0') {
        if (isdigit(buffer[i])) {
            updates[n_upd].array[n].num = updates[n_upd].array[n].num * 10 + (buffer[i] - '0');
            updates[n_upd].array[n].pos = pos;
        } else if (buffer[i] == ',') {
            n++;
            pos++;
            updates[n_upd].array[n].num = 0;
        } else if (buffer[i] == '\n') {
            n_upd++;
            n = 0;
            pos = 0;
            updates[n_upd].array[n].num = 0;
        }
        i++;
    }
}