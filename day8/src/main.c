#include "../include/day8.h"

int main (int argc, char** argv)
{
    if (argc == 2) {
        int value = open_file(argv[argc - 1]);
        printf("answer: %i\n", value);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}