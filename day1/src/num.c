#include "../include/day1.h"

int study_numbers(char* buffer, int line_count)
{
    int i = 0;

    int* left_array = malloc(sizeof(int) * line_count);
    int* right_array = malloc(sizeof(int) * line_count);

    int currentNumber = 0;
    int isLeft = 1;
    int leftCount = 0;
    int rightCount = 0;

    while (buffer[i] != '\0') {
        if (isdigit(buffer[i])) {
            currentNumber = currentNumber * 10 + (buffer[i] - '0');
        } else {
            if (buffer[i] == ' ' && isLeft == 1) {
                left_array[leftCount++] = currentNumber;
                isLeft = 0;
                currentNumber = 0;
            } else if (buffer[i] == '\n' && isLeft == 0) {
                right_array[rightCount++] = currentNumber;
                currentNumber = 0;
                isLeft = 1;
            }
        }
        i++;
    }


    int value = make_operation(left_array, right_array, leftCount, rightCount);
    free(left_array);
    free(right_array);
    return value;
}

int make_operation(int* left_array, int* right_array, int leftCount, int rightCount)
{
    int initialCount = leftCount;
    int value = 0;
    while (leftCount > 0) {
        value = value + abs(find_min(left_array, &leftCount) - find_min(right_array, &rightCount));
    }
    return value;
}

int find_min(int* array, int* size)
{
    int min_index = 0;
    int min = 0;
    
    for (int i = 1; i < *size; i++) {
        if (array[min_index] > array[i]) {
            min_index = i;
        }
    }
    
    min = array[min_index];
    
    for (int i = min_index; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }

    (*size)--;
    
    return min;
}