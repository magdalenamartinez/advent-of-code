#include "../include/day5.h"

int** init_rules(int num_rules)
{
    int** rules = malloc(sizeof(int*) * (num_rules + 1));
    for (int i = 0; i < num_rules; i++) {
        rules[i] = malloc(sizeof(int) * 2);
        if (rules[i] == NULL) {
            exit(EXIT_FAILURE);
        }
        rules[i][0] = 0;
        rules[i][1] = 0;
    }
    return rules;
}

int** create_rules(char* buffer, int num_rules)
{
    int i = 0, j = 0, row = 0;    
    int** rules = init_rules(num_rules);
    while (row < num_rules && buffer[i]) {
        if (isdigit(buffer[i])) {
            rules[row][j] = rules[row][j] * 10 + buffer[i] - '0';
        } else if (buffer[i] == '\n') {
            row++;
            j = 0;
        }
        if (isdigit(buffer[i]) && !isdigit(buffer[i + 1])) {
            j++;
        }
        i++;
    }
    return rules;
}

int get_num_rules(char* buffer, int* i)
{
    int num_rules = 0;
    int found = -1;

    while (buffer[(*i)] != '\0' && found == -1) {
        if (buffer[(*i)] == '\n' && buffer[(*i) + 1] == '\n') {
            num_rules++;
            found = *(i);
        } else if (!isdigit(buffer[(*i)]) && buffer[(*i)] != '|' && buffer[(*i)] != '\n') {
            return 0;
        } else if (buffer[(*i)] == '\n') {
            num_rules++;
        }
        (*i)++;
    }
    return num_rules;
}

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
        if (found == 0) {
            int middle = updates[i].len/2;
            int n = 0;
            while (middle != updates[i].array[n].pos && n < updates[i].len) {
                n++;
            }
            counter = counter + (updates[i].array[n].num);
        }
    }
    return counter;
}
