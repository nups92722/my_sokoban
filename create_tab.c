/*
** EPITECH PROJECT, 2022
** create tab
** File description:
** create tab
*/

#include "my.h"

int preparation_game(data *data);

int verification_caractere(char *s)
{
    int i = 0;
    for (int x = 0; s[x] != '\0'; x++) {
        if (s[x] != 'P' && s[x] != ' ' && s[x] != 'O'
            && s[x] != 'X' && s[x] != '#')
            return (84);
    }
    return (0);
}

char **create(char *buffer, data *data)
{
    int i = 0;
    int x = 0;
    data->size_y = nb_line(buffer);
    char **tab = malloc(sizeof(char *) * data->size_y + 1);

    for (int y = 0; y < data->size_y; y++) {
        tab[y] = malloc(sizeof(char) * my_strlen_n_s(buffer, y) + 1);
        if (data->size_x < my_strlen_n_s(buffer, y))
            data->size_x = my_strlen_n_s(buffer, y);
        for (x = 0; buffer[i] != '\n'; x++) {
            tab[y][x] = buffer[i];
            i++;
        }
        tab[y][x] = '\0';
        i++;
    }
    tab[data->size_y] = NULL;
    return (tab);
}

int create_tab(char *buffer, data *data)
{
    data->map = create(buffer, data);
    data->tab = create(buffer, data);
    data->base = create(buffer, data);
    for (int y = 0; data->tab[y] != NULL; y++)
        if (verification_caractere(data->tab[y]) == 84)
            return (84);
    return (preparation_game(data));
}
