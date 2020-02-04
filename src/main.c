/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "bsq.h"

int **fill_square(b_square square)
{
    int x = square.x, j, d, n = square.count;
    while (n > 0 ) {
        j = square.count, d = square.y;
        while (j > 0 ) {
            square.map[x - 1][d] = square.count;
            d--, j--;
        }
        x--, n--;
    }
    return (square.map);
}

b_square change_square(buff file)
{
    b_square square;
    int count, x = 0, y, **map = map_to_array(file);
    if (check_first(map) == 0)
        count = 0;
    else
        count = find_square(map);
    while (map[x] != NULL) {
        if (x > 0 && map[x - 1][y] == count)
            break;
        y = 0;
        while (map[x][y] != -1 && map[x][y] != count) {
            y++;
        }
        x++;
    }
    square.x = x, square.y = y, square.count = count;
    square.map = map;
    square.map = fill_square(square);
    return (square);
}

char **change_map(b_square square, int columns, int lines)
{
    int x = 0, y;
    char **new_map = malloc(sizeof(char *) * (lines + 1));
    while (square.map[x] != NULL) {
        new_map[x] = malloc(sizeof(char) * columns + 1);
        y = 0;
        while (square.map[x][y] != -1) {
            if (square.map[x][y] == 0)
                new_map[x][y] = 'o';
            else if (square.map[x][y] == square.count && x < square.x
            && y <= square.y)
                new_map[x][y] = 'x';
            else
                new_map[x][y] = '.';
            y++;
        }
        new_map[x][y] = '\n';
        x++;
    }
    new_map[x] = NULL;
    return (new_map);
}

char **output_map(buff file)
{
    b_square square = change_square(file);
    int lines = file.lines;
    int columns = (file.bytes - file.a) / file.lines;
    char **new_map = change_map(square, columns, lines);
    free_int(square.map);

    return (new_map);
}

int main(int ac, char **av)
{
    char **new_map;
    char *str;
    if (ac == 2) {
        int bytes = get_bytes(av[1]);
        buff file = get_map(av[1], bytes);
        check_end(file);
        check_lines(file.str);
        new_map = output_map(file);
        str = map_to_arr(bytes, new_map);
        print_array(bytes, str, file);
        free(str);
        free_char(new_map);
        return (0);
    }
    else {
        write(2, "wrong use, only filepath as argument\n", 37);
        exit(84);
    }
}