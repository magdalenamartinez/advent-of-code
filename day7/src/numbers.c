#include "../include/day7.h" 

void set_numbers(list_numbers_t* list_numbers, char* buffer) 
{
    int i = 0, row = 0, col = 0, found = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            found = 0;
            row++;
            col = 0;
        } else if (isdigit(buffer[i]) && !found) {
            list_numbers->num_row[row].result = list_numbers->num_row[row].result * 10 + (buffer[i] - '0'); 
            if (!isdigit(buffer[i + 1])) {
                found = 1;
            }
        } else if (isdigit(buffer[i]) && found) {
            list_numbers->num_row[row].numbers[col] = list_numbers->num_row[row].numbers[col] * 10 + (buffer[i] - '0'); 
            if (!isdigit(buffer[i + 1])) {
                col++;
            } 
        }
        i++;
    }

}

long long study_numbers(char* buffer, int line_count)
{
    list_numbers_t* list_numbers = alloc_memory(buffer, line_count);
 
    long long counter = make_comparison(list_numbers);

    free_list_numbers(list_numbers);
    return counter;
}
