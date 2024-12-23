#include "../include/day7.h"


int main (int argc, char** argv)
{
    if (argc == 2) {
        long long value = open_file(argv[argc - 1]);
        printf("answer: %lld\n", value);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}