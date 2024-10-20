/*
** EPITECH PROJECT, 2022
** end
** File description:
** fail or succes
*/

#include "my.h"

int verif_o(data *data, int y, int x)
{
    if (data->base[y][x] == 'O')
        if (data->tab[y][x] != 'X')
            return (2);
    return (0);
}

int victory(data *data)
{
    int re = 0;
    for (int y = 0; data->base[y] != NULL; y++) {
        for (int x = 0; data->base[y][x] != '\0' && re == 0; x++) {
            re = verif_o(data, y, x);
        }
    }
    return (re);
}

int verif_fail(data *data, int y, int x)
{
    if (data->tab[y + 1][x] == 'X' || data->tab[y + 1][x] == '#') {
        if (data->tab[y][x + 1] == 'X' || data->tab[y][x + 1] == '#')
            return (1);
        if (data->tab[y][x - 1] == 'X' || data->tab[y][x - 1] == '#')
            return (1);
    }
    if (data->tab[y - 1][x] == 'X' || data->tab[y - 1][x] == '#') {
        if (data->tab[y][x + 1] == 'X' || data->tab[y][x + 1] == '#')
            return (1);
        if (data->tab[y][x - 1] == 'X' || data->tab[y][x - 1] == '#')
            return (1);
    }
    return (2);
}

int verif_x(data *data, int y, int x)
{
    if (data->tab[y][x] == 'X') {
        return (verif_fail(data, y, x));
    }
    return (1);
}

int fail(data *data)
{
    int re = 1;

    for (int y = 0; data->tab[y] != NULL; y++) {
        for (int x = 0; data->tab[y][x] != '\0' && re == 1; x++) {
            re = verif_x(data, y, x);
        }
    }
    return (re);
}
