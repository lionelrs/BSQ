/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** header
*/

#ifndef _BSQ_
#define _BSQ_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct find_square
{
    int x;
    int y;
    int count;
    int **map;
} b_square;

typedef struct buffer
{
    int lines;
    int a;
    int bytes;
    char *str;
} buff;

void my_putchar(char c);
int **fill_square(b_square square);
b_square change_square(buff file);
char **change_map(b_square square, int columns, int lines);
char **output_map(buff file);
int get_bytes(char const *filepath);
buff get_map(char const *filepath, int bytes);
void check_lines(char *str);
char *map_to_arr(int bytes, char **map);
int array_size(buff file);
int **map_to_array(buff file);
int change_values1(int count, int x, int y, int **map);
int find_square(int **map);
void print_map(char **new_map, buff file);
int check_first(int **map);
void free_int(int **map);
void free_char(char **map);
void print_array(int bytes, char *str, buff file);
void check_end(buff file);

#endif