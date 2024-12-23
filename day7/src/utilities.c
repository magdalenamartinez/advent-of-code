#include "../include/day7.h"
#include <math.h>

int try_operation(int i, int j)
{
    int op = (i / (int)pow(3, j)) % 3;
    return op;
}

long long is_the_number(list_numbers_t* list_numbers, int row)
{
    int i = 0, multiply = 0;
    long long result = 0;
    int n_operations =(int)pow(3, list_numbers->num_row[row].length - 1);
    while (i < n_operations) {
        result = list_numbers->num_row[row].numbers[0];
        for (int j = 1; j < list_numbers->num_row[row].length; j++) {
            int value = try_operation(i, j - 1);
            if (value == 2) {
                result = result * list_numbers->num_row[row].numbers[j];
            } else if (value == 1) {
                result = result + list_numbers->num_row[row].numbers[j];
            } else {
                char str[200];
                sprintf(str, "%ld", list_numbers->num_row[row].numbers[j]);
                int n = 0;
                while (str[n] != '\0') {
                    result = result * 10 + (str[n] - '0');
                    n++;
                }
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