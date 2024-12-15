#include "../include/day5.h"

int study_numbers(char* buffer, int line_count)
{
    int i = 0, j = 0, found = 0, n_upd = 0;
    
    int num_rules = get_num_rules(buffer, &i);
    int** rules = create_rules(buffer, num_rules);

    updates_t* updates = create_updates_struct(buffer, i + 1, &n_upd);
    int counter = compare_positions(n_upd, updates, num_rules, rules);
    
    free_memory(rules, num_rules, updates, n_upd);
    return counter;
}

int get_pos(int num, updates_t *updates, int i)
{
    int first = 0;
    int last = updates[i].len - 1;

    while (first <= last && first >= 0) {
        int middle = first + (last - first) / 2;
        if (middle < 0 || middle >= updates[i].len) {
            return -1;
        }
        if (updates[i].array[middle].num == num) {
            return updates[i].array[middle].pos;
        } else if (updates[i].array[middle].num > num) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }   
    }
    return -1;
}

void free_memory (int** rules, int num_rules, updates_t* updates, int n_upd)
{
    for (int i = 0; i < num_rules; i++) {
        free(rules[i]);
    }
    free(rules);
    
    for (int i = 0; i < n_upd; i++) {
        free(updates[i].array);
    }
    free(updates);
}