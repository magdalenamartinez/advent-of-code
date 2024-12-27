#include "../include/day8.h"

general_t* alloc_general(char* buffer, int line_count)
{
    general_t* general = malloc(sizeof(general_t));
    general->rows = line_count;
    general->cols = get_cols(buffer);
    general->num_frequencies = 0;

    general->map = malloc(sizeof(char*) * general->rows);
    general->antinodes_map = malloc(sizeof(int*) * general->rows);

    general->frequencies = NULL;

    for (int i = 0; i < general->rows; i++) {
        alloc_maps(general, i);
    }

    int c = 0;
    for (int r = 0; r < general->rows; r++) {
        for (c = 0; c < general->cols; c++) {
            general->antinodes_map[r][c] = 0;
            general->map[r][c] = '.';
        }
        general->map[r][c] = '\0';
    }

    return general;
}


void alloc_maps(general_t* general, int pos)
{
    if (pos < 0 || pos > general->rows) {
        exit(EXIT_FAILURE);
    }
    general->map[pos] = malloc(sizeof(char) * (general->cols + 1));
    if (general->map[pos] == NULL) {
        exit(EXIT_FAILURE);
        perror("There was an error allocating memory.\n");
    }
    general->antinodes_map[pos] = malloc(sizeof(int) * general->cols);
    if (general->antinodes_map[pos] == NULL) {
        exit(EXIT_FAILURE);
        perror("There was an error allocating memory.\n");
    }
}

void init_frequency(general_t* general, char value, int row, int col)
{
    general->frequencies = realloc(general->frequencies, sizeof(frequencies_t) * (general->num_frequencies + 1));
    general->frequencies[general->num_frequencies].character = value;
    general->frequencies[general->num_frequencies].counter = 1;
    general->frequencies[general->num_frequencies].antinodes = malloc(sizeof(antinodes_t));
    general->frequencies[general->num_frequencies].antinodes[0].r = row;
    general->frequencies[general->num_frequencies].antinodes[0].c = col;
    general->num_frequencies++;
}

void set_frequency(general_t* general, int f, int row, int col)
{   
    general->frequencies[f].counter++;
    int counter = general->frequencies[f].counter;
    general->frequencies[f].antinodes = realloc(general->frequencies[f].antinodes, sizeof(antinodes_t) * (counter + 1));
    general->frequencies[f].antinodes[counter-1].r = row;
    general->frequencies[f].antinodes[counter-1].c = col;
}


void free_memory(general_t* general)
{
    for (int i = 0; i < general->num_frequencies; i++) {
        free(general->frequencies[i].antinodes);
    }
    free(general->frequencies);

    for (int j = 0; j < general->rows; j++) {
        free(general->map[j]);
        free(general->antinodes_map[j]);
    }
    free(general->map);
    free(general->antinodes_map);
    free(general);
}