#include "../include/day5.h"

void selection_sort(updates_t* update)
{
    for (int i = 0; i < update->len; i++) {
        int min_index = i;
        for (int j = i + 1; j < update->len; j++) {
            if (update->array[j].num < update->array[min_index].num) {
                min_index = j;
            }
        }
        values_t temp = update->array[min_index];
        update->array[min_index] = update->array[i];
        update->array[i] = temp;
    }
}


void sort_updates(updates_t* updates, int n_upd)
{
    for (int i = 0; i < n_upd; i++) {
        selection_sort(&updates[i]);
    }
}
