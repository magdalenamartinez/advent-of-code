#include "../include/day7.h"

int try_operation(int i, int j)
{
    if (i & (1 << j)) { 
        return 1;
    } else {
        return 0;
    }
}

long long is_the_number(list_numbers_t* list_numbers, int row)
{
    int i = 0, multiply = 0;
    long long result = 0;
    int n_operations = 1 << (list_numbers->num_row[row].length - 1);

    while (i < n_operations) {
        result = list_numbers->num_row[row].numbers[0];
        for (int j = 1; j < list_numbers->num_row[row].length; j++) {
            if (try_operation(i, j - 1)) {
                result = result * list_numbers->num_row[row].numbers[j];
            } else {
                result = result + list_numbers->num_row[row].numbers[j];
            }
        }
        if (result == list_numbers->num_row[row].result) {
            return result;
        } 
        i++;
    }
    
    return 0;
}

long long make_comparison(list_numbers_t* list_numbers) 
{
    long long counter = 0;
    for (int i = 0; i < list_numbers->line_count; i++) {
        counter += is_the_number(list_numbers, i);
    }
    return counter;
}