#include "../include/day1.h"

int main(int argc, char** argv)
{
    if (argc == 2) {
        int value = open_file(argv[argc - 1]);
        printf("SUMA FINAL %i\n",value);
        return EXIT_SUCCESS;    
    }
    return EXIT_FAILURE;
}