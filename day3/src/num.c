#include "../include/day3.h"

int study_numbers(char* buffer, int line_count)
{
    const char* currentPointer = buffer;
    const char* search = "mul(";
    int firstNumber = 0, secondNumber = 0, solution = 0;
    int i = 0, pos = 0, counter = 0, found = 0;

    while ((currentPointer = strstr(currentPointer, search)) != NULL) {
        currentPointer += strlen(search);
        pos = currentPointer - buffer;
        i = 0;
        counter = 0;
        firstNumber = getNumber(&currentPointer, &i, &counter);
        if (counter < 4 && currentPointer[i] == ',') {
            counter = 0;
            i++;
            secondNumber = getNumber(&currentPointer, &i, &counter);
        }
        if (counter < 4 && currentPointer[i] == ')') {
            solution = solution + (firstNumber*secondNumber);
        }
    }
    return solution;
}

int getNumber (const char** currentPointer, int* i, int* counter)
{
    int number = 0;
    while (isdigit((*currentPointer)[(*i)])) {
        number = number * 10 + (*currentPointer)[(*i)] - '0';
        (*counter)++;
        (*i)++;
    }
    return number;
}
