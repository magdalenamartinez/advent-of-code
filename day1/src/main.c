#include "../include/day1.h"

int main(int argc, char** argv)
{
    if (argc == 2) {
        return open_file(argv[argc - 1]);
    }
    return EXIT_FAILURE;
}