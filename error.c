/*
** EPITECH PROJECT, 2022
** error
** File description:
** error
*/

#include "my.h"

int game(data *data);
int fail(data *data);
int verif_fail(data *data, int y, int x);

int preparation_map(data *data, verif *verif, int y, int x)
{
    if (data->tab[y][x] == 'P') {
        data->x_o = x;
        data->y_o = y;
        data->base[y][x] = ' ';
        verif->p++;
    }
    if (data->tab[y][x] == 'O') {
        verif->o++;
    }
    if (data->tab[y][x] == 'X') {
        data->base[y][x] = ' ';
        if (verif_fail(data, y, x) == 2)
            verif->x++;
    }
    return (0);
}

int verification(verif *verif)
{
    if (verif->p != 1)
        return (84);
    if (verif->x < 1 || verif->x < verif->o)
        return (84);
    return (0);
}

int preparation_game(data *data)
{
    verif Verif;
    verif *verif = &Verif;
    verif->p = 0;
    verif->o = 0;
    verif->x = 0;

    for (int y = 0; data->tab[y] != NULL; y++) {
        for (int x = 0; data->tab[y][x] != '\0'; x++) {
            preparation_map(data, verif, y, x);
        }
    }
    data->x = data->x_o;
    data->y = data->y_o;
    if (verification(verif) == 84)
        return (84);
    return (game(data));
}
