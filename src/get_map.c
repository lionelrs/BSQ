/*
** EPITECH PROJECT, 2019
** get_map
** File description:
** get_map
*/

#include "bsq.h"

int get_bytes(char const *filepath)
{
    struct stat filestat;
    stat(filepath, &filestat);
    char c;
    int fd = open(filepath, O_RDONLY);
    if (read(fd, &c, 1) < 0) {
        write(2, "wrong filepath\n", 15);
        exit(84);
    }
    close(fd);
    if (filestat.st_size > 0)
        return (filestat.st_size);
    else {
        write(2, "empty\n", 6);
        exit(84);
    }
}

buff get_map(char const *filepath, int bytes)
{
    char c;
    buff file;
    int i = 0, a = 0, fd = open(filepath, O_RDONLY);
    char *map;
    while (read(fd, &c, 1) > 0 && c != '\n') {
        if (c < '0' || c > '9'){
            write(2, "not a number\n", 13);
            exit(84);
        }
        i = i * 10 + (c - 48);
        a++;
    }
    map = malloc(sizeof(char) * bytes + 1);
    read(fd, map, bytes - a);
    close(fd);
    map[bytes - a] = '\0';
    file.lines = i, file.bytes = bytes;
    file.str = map, file.a = a;
    return (file);
}

void check_lines(char *str)
{
    int i = 0, j = 0, k = 0;
    while (str[i] != '\n') {
        i++;
        j++;
    }
    if (str[i] != '\n')
        exit(84);
    i++;
    while (str[i + 1] != '\0') {
        k = 0;
        while (str[i] != '\n') {
            k++;
            i++;
        }
        if (j != k){
            write(2, "lines not same length\n", 2);
            exit(84);
        }
        i++;
    }
}

char *map_to_arr(int bytes, char **map)
{
    int i = 0, j, k = 0;
    char *str = malloc(sizeof(char) * bytes + 1);

    while (map[i] != NULL) {
        j = 0;
        while (map[i][j] != '\n') {
            str[k] = map[i][j];
            j++;
            k++;
        }
        str[k] = '\n';
        k++;
        i++;
    }
    str[k] = '\0';
    return (str);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}