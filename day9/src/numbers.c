#include "../include/day9.h"

long long study_numbers(char* buffer, int line_count)
{
    int counter = 0;
    int i = 0;
    /*
    Tenemos que leer todos los caracteres, los impares van a ser los discos
    entonces guardamos en un struct tres cosas
        id -> que va incrementando con un contador
        quantity -> que sera el numero impar
        points -> que sera el numero par
        de forma que 12345
        0..111....22222
        SI no hay numero siguiente pues se entiende que el ultimo pues tendra el otro numero como cero
        una vez que tengamos eso construimos un array con ello y vamos luego haciendo la operacion de quitar
        los puntos y poner el numero correspondiente en esa posicion q sera el ult numero existente
        o sea se cambia ult numero por primer punto y asi
    */
    disk_t* disk = malloc(sizeof(disk_t));
    disk->files = malloc(sizeof(file_t));
    disk->num_files = 0;
    int num = 0;
    while (buffer[i] != '\0') {
        if (i % 2 == 0) {
            disk->files[disk->num_files].id= num;
            disk->files[disk->num_files].length = buffer[i] - '0';
        } else {
            if (!isdigit(buffer[i])) {
                disk->files[disk->num_files].free_length = 0;    
                num++;
                disk->num_files++;
            } else {
                disk->files[disk->num_files].free_length = buffer[i] - '0';
                num++;
                disk->num_files++;
                disk->files = realloc(disk->files, sizeof(file_t) * (disk->num_files + 1));
            }
        }
        i++;
    }
    for (int i = 0; i < disk->num_files; i++) {
        printf("id:%i length:%i free:%i\n",disk->files[i].id, disk->files[i].length, disk->files[i].free_length);
    }
    int j = 0;
    
    int pos = 0;
    size_t total_size = 0;
    for (int i = 0; i < disk->num_files; i++) {
        total_size += sizeof(char) * (disk->files[i].length + disk->files[i].free_length);
    }
    char* array = malloc(total_size + 1);
    if (array == NULL) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < disk->num_files; i++){
        for (int j = 0; j < disk->files[i].length; j++) {
            array[pos++] = disk->files[i].id + '0';
        }
        for (int j = 0; j < disk->files[i].free_length; j++) {
            array[pos++] = '.';
        }
    } 

    for (int i = 0; i < pos; i++) {
        printf("%c",array[i]);
    }
   
    int last = pos;
    int first = 0;
    int first_pos = -1;
    int last_pos = -1;
    while (first < last) {
        if (array[first] == '.') {
            first_pos = first;
        } else {
            first++;
        }
        if (isdigit(array[last])) {
            last_pos = last;
        } else {
            last--;
        }
        if (first_pos != -1 && last_pos != -1) {
            char temp = array[first_pos];
            array[first_pos] = array[last_pos];
            array[last_pos] = temp;
            first_pos = -1;
            last_pos = -1;
            first++;
            last--;
        }

    }
    i = 0;
    counter = 0;
    while (array[i] != '.' && i < pos) {
        counter += ((array[i] - '0') * i);
        i++;
    }
    printf("\n");
    
    return counter;
}
