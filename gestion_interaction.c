/*
** EPITECH PROJECT, 2022
** game of sokoban
** File description:
** game of sokoban
*/

#include "my.h"

int verif_down(data *data)
{
    if (data->tab[data->y + 1][data->x] == 'X') {
        if (data->tab[data->y + 2][data->x] == ' ' ||
            data->tab[data->y + 2][data->x] == 'O') {
            data->tab[data->y + 2][data->x] = 'X';
            data->tab[data->y + 1][data->x] = 'P';
            data->tab[data->y][data->x] = data->base[data->y][data->x];
            data->y++;
        }
    } else {
        data->tab[data->y + 1][data->x] = 'P';
        data->tab[data->y][data->x] = data->base[data->y][data->x];
        data->y++;
    }
    return (0);
}

int verif_right(data *data)
{
    if (data->tab[data->y][data->x + 1] == 'X') {
        if (data->tab[data->y][data->x + 2] == ' ' ||
            data->tab[data->y][data->x + 2] == 'O') {
            data->tab[data->y][data->x + 2] = 'X';
            data->tab[data->y][data->x + 1] = 'P';
            data->tab[data->y][data->x] = data->base[data->y][data->x];
            data->x++;
        }
    } else {
        data->tab[data->y][data->x + 1] = 'P';
        data->tab[data->y][data->x] = data->base[data->y][data->x];
        data->x++;
    }
    return (0);
}

int verif_up(data *data)
{
    if (data->tab[data->y - 1][data->x] == 'X') {
        if (data->tab[data->y - 2][data->x] == ' ' ||
            data->tab[data->y - 2][data->x] == 'O') {
            data->tab[data->y - 2][data->x] = 'X';
            data->tab[data->y - 1][data->x] = 'P';
            data->tab[data->y][data->x] = data->base[data->y][data->x];
            data->y--;
        }
    } else {
        data->tab[data->y - 1][data->x] = 'P';
        data->tab[data->y][data->x] = data->base[data->y][data->x];
        data->y--;
    }
    return (0);
}

int verif_left(data *data)
{
    if (data->tab[data->y][data->x - 1] == 'X') {
        if (data->tab[data->y][data->x - 2] == ' ' ||
            data->tab[data->y][data->x - 2] == 'O') {
            data->tab[data->y][data->x - 2] = 'X';
            data->tab[data->y][data->x - 1] = 'P';
            data->tab[data->y][data->x] = data->base[data->y][data->x];
            data->x--;
        }
    } else {
        data->tab[data->y][data->x - 1] = 'P';
        data->tab[data->y][data->x] = data->base[data->y][data->x];
        data->x--;
    }
    return (0);
}

int gestion_interaction(data *data, int t)
{
    if (t == KEY_DOWN) {
        if (data->tab[data->y + 1][data->x] != '#')
            verif_down(data);
    }
    if (t == KEY_RIGHT) {
        if (data->tab[data->y][data->x + 1] != '#')
            verif_right(data);
    }
    if (t == KEY_UP) {
        if (data->tab[data->y - 1][data->x] != '#')
            verif_up(data);
    }
    if (t == KEY_LEFT) {
        if (data->tab[data->y][data->x - 1] != '#')
            verif_left(data);
    }
    return (0);
}
