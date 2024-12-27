#include "../include/day8.h"

void try_antinode(general_t* general, int x, int difX, int y, int difY, int freq)
{
    int i = 0, found = 0;
    while (x >= 0 && x < general->rows && y >= 0 && y < general->cols) {
        if (x >= 0 && x < general->rows && y >= 0 && y < general->cols) {
            general->antinodes_map[x][y] = 1;
        }
        x += difX;
        y += difY;
    }
           

}

void get_antinodes_frequency(general_t* general, int freq)
{
    for (int i = 0; i < general->frequencies[freq].counter; i++) {
        int x = general->frequencies[freq].antinodes[i].r;
        int y = general->frequencies[freq].antinodes[i].c;
        for (int j = 0; j < general->frequencies[freq].counter; j++) {
            if (i != j) {
                int x2 = general->frequencies[freq].antinodes[j].r;
                int y2 = general->frequencies[freq].antinodes[j].c;
                
                try_antinode(general, x, x-x2, y, y-y2, freq);
            }
        }
    }
}

int get_antinodes(general_t* general)
{
    int counter = 0;
    for (int i = 0; i < general->num_frequencies; i++) {
        get_antinodes_frequency(general, i);

    }

    for (int r = 0; r < general->rows; r++) {
        for (int c = 0; c < general->cols; c++) {
            if (general->antinodes_map[r][c] == 1) {
                counter++;
            }
        }
    }
    return counter;
}