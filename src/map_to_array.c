/*
** EPITECH PROJECT, 2019
** map_to_array
** File description:
** puts content of the map in 2d array
*/

#include "bsq.h"

int array_size(buff file)
{
    int i = 0;
    while (file.str[i] != '\n') {
        i++;
    }
    return (i);
}

int **map_to_array(buff file)
{
    int i = 0, j, x = 0, lines = file.lines;
    int columns = (file.bytes - file.a) / file.lines;
    int **map = malloc(sizeof(int *) * (lines + 1));
    while (file.str[x + 1] != '\0') {
        map[i] = malloc(sizeof(int) * (columns + 1));
        j = 0;
        while (file.str[x] != '\n') {
            if (file.str[x] != '.' && file.str[x] != 'o' &&
            file.str[x] != '\n') {
                write(2, "wrong characters\n", 17);
                exit(84);
            }
            map[i][j++] = (file.str[x++] == '.') ? 1 : 0;
        }
        map[i][j] = -1;
        i++, x++;
    }
    map[i] = NULL;
    free(file.str);
    return (map);
}

int change_values1(int count, int x, int y, int **map)
{
    if ((map[x][y - 1] == 0 || map[x - 1][y] == 0) && map[x][y] > 0)
        map[x][y] = 1;
    if ((map[x][y - 1] != map[x - 1][y]) &&
    map[x][y] > 0 && map[x - 1][y - 1] > 0) {
        map[x][y] = (map[x][y - 1] > map[x - 1][y]) ?
        map[x - 1][y] + 1 : map[x][y - 1] + 1;    }
    if ((map[x][y - 1] == map[x - 1][y]) && map[x][y] > 0 &&
    map[x][y - 1] > 0 && map[x - 1][y] > 0 && map[x - 1][y - 1] > 0) {
        if (map[x - 1][y - 1] < map[x - 1][y])
            map[x][y] = map[x - 1][y - 1] + 1;
        else
            map[x][y] = map[x - 1][y] + 1;
    }
    if (map[x][y] >= count)
        count = map[x][y];
    return (count);
}

int find_square(int **map)
{
    int x = 1, y;
    int count = 1;
    while (map[x] != NULL) {
        y = 1;
        while (map[x][y] != -1) {
            count = change_values1(count, x, y, map);
            y++;
        }
        x++;
    }
    return (count);
}

void check_end(buff file)
{
    int x = 0;
    char *str = file.str;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n') {
            x++;
        }
    }
    if (x != file.lines){
        write(2, "missing end\n", 12);
        exit(84);
    }
}