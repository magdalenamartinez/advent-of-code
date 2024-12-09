#include "../include/day3.h"

int study_numbers(char* buffer)
{
    const char* search = "mul(";
    const char* currentPointer = buffer;
    int enable = 1, solution = 0;

    while (*currentPointer) {
        if (checkEnable(&currentPointer, &enable) == 1) {
        } else if (strncmp(currentPointer, search, strlen(search)) == 0) {
            solution = checkMul(&currentPointer, enable, &solution);
        } else {
            currentPointer++;
        }
    }
    return solution;
}

int getNumber (const char** currentPointer, int* i, int* counter)
{
    *counter = 0;
    *i = 0;
    int number = 0;
    while (isdigit((*currentPointer)[(*i)])) {
        number = number * 10 + (*currentPointer)[(*i)] - '0';
        (*counter)++;
        (*i)++;
    }
    *currentPointer += *i;
    return number;
}

int checkMul(const char** currentPointer, int enable, int* solution)
{
    const char* search = "mul(";
    int firstNumber = 0, secondNumber = 0;
    int counter = 0, i = 0;

    *currentPointer += strlen(search);
    if (enable) {
        i = 0;
        firstNumber = getNumber(currentPointer, &i, &counter);
        if (counter < 4 && **currentPointer == ',') {
            (*currentPointer)++;
            secondNumber = getNumber(currentPointer, &i, &counter);
        }
        if (counter < 4 && **currentPointer == ')') {
            *solution = *solution + (firstNumber*secondNumber);
            (*currentPointer)++;
        }
    } else {
        while (**currentPointer && **currentPointer != ')') {
            (*currentPointer)++;
        }
        if (**currentPointer == ')') {
            (*currentPointer)++;
        }
    }

    return *solution;
}

int checkEnable(const char** currentPointer, int* enable)
{
    const char* searchDo = "do()";
    const char* searchDont = "don't()";
    if (strncmp(*currentPointer, searchDo, strlen(searchDo)) == 0) {
        *currentPointer += strlen(searchDo);
        *enable = 1;
        return 1;
    } else if (strncmp(*currentPointer, searchDont, strlen(searchDont)) == 0) {
        *currentPointer += strlen(searchDont);
        *enable = 0;
        return 1;
    }
    return 0;
}
