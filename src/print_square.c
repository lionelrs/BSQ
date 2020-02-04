/*
** EPITECH PROJECT, 2019
** print_square
** File description:
** print_square
*/

#include "bsq.h"

void print_map(char **new_map, buff file)
{
    int i = 0;
    int line = file.a;
    while (new_map[i] != NULL) {
        write(1, new_map[i], line);
            my_putchar('\n');
            i++;
        }
}

int check_first(int **map)
{
    int x = 0, y;

    while (map[x] != NULL) {
        y = 0;
        while (map[x][y] != -1) {
            if (map[x][y] != 0)
                return (1);
            y++;
        }
        x++;
    }
    return (0);
}

void free_int(int **map)
{
    int i = 0;

    while (map[i] != NULL) {
        free(map[i]);
        i++;
    }
    free(map);
}

void free_char(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        free(map[i]);
        i++;
    }
    free(map);
}

void print_array(int bytes, char *str, buff file)
{
    write(1, str, bytes - file.a - 1);
}