#include "../include/day5.h"

int compare_positions(int n_upd, updates_t* updates, int num_rules, int** rules)
{
    int found = 0, counter = 0, j = 0;
    for (int i = 0; i < n_upd; i++) {
        found = 0;
        j = 0;
       while (j < num_rules && found == 0) {
           int pos1 = get_pos(rules[j][0], updates, i); 
           int pos2 = get_pos(rules[j][1], updates, i);
           if (pos1 > pos2 && pos1 != -1 && pos2 != -1) {
                found = 1;
           }
           j++;
        }
        if (found == 1) {
            int value =  set_correct(updates, i, num_rules, rules);
            counter = counter + value;
        }
    }
    return counter;
}

void swipe_pos(updates_t* updates, int i, int p1, int p2)
{
    int temp = updates[i].array[p1].pos;
    updates[i].array[p1].pos = updates[i].array[p2].pos;
    updates[i].array[p2].pos = temp;
}

int get_middle(updates_t* updates, int i)
{
    int j = 0;
    while (updates[i].array[j].pos != (updates[i].len/2) && j < updates[i].len) {
        j++;
    }
    return updates[i].array[j].num;
}

int set_correct(updates_t* updates, int i, int num_rules, int** rules)
{
    int j = 0, p1 = 0, p2 = 0, sorted = -1;
    
    while (sorted == -1) {
        j = 0;
        while (j < num_rules) {
            int pos1 = change_pos(rules[j][0], updates, i, &p1); 
            int pos2 = change_pos(rules[j][1], updates, i, &p2);
            if (pos1 > pos2 && pos1 != -1 && pos2 != -1) {
                swipe_pos(updates, i, p1, p2);
                sorted = 0;
            } else if (sorted == -1 && j == num_rules - 1) {
                sorted = 1;
            }
            j++;
        }
        sorted = (sorted == 0) ? -1 : 1;
    }
    return (get_middle(updates, i));
}

int change_pos(int num, updates_t *updates, int i, int* k)
{
    int first = 0;
    int last = updates[i].len - 1;

    while (first <= last && first >= 0) {
        int middle = first + (last - first) / 2;
        if (middle < 0 || middle >= updates[i].len) {
            return -1;
        }
        if (updates[i].array[middle].num == num) {
            *k = middle;
            return updates[i].array[middle].pos;
        } else if (updates[i].array[middle].num > num) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }   
    }
    return -1;
}
