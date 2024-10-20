/*
** EPITECH PROJECT, 2022
** game
** File description:
** game of sokoban
*/

#include "my.h"

int gestion_interaction(data *data, int t);
int victory(data *data);
int fail(data *data);

int print(data *data)
{
    int y = LINES / 2 - data->size_y / 2;

    clear();
    if (LINES < data->size_y && COLS < data->size_x) {
        mvprintw(LINES / 2, COLS / 2 - 25 / 2, "please enlarge the window");
    } else {
        for (int i = 0; data->tab[i] != NULL; i++) {
            mvprintw(y, COLS / 2 - data->size_x / 2, data->tab[i]);
            printw("\n");
            y++;
        }
    }
    refresh();
}

int restart(data *data)
{
    data->x = data->x_o;
    data->y = data->y_o;
    for (int y = 0; data->tab[y] != NULL; y++)
        for (int x = 0; data->tab[y][x] != '\0'; x++)
            data->tab[y][x] = data->map[y][x];
    return (0);
}

int end(data *data)
{
    int t = 10;

    t = victory(data);
    if (t == 0)
        return (t);
    t = fail(data);
    if (t == 1)
        return (t);
    return (2);
}

int game(data *data)
{
    initscr();
    keypad(stdscr, TRUE);
    int t = -1;;
    while (true) {
        print(data);
        t = getch();
        gestion_interaction(data, t);
        if (t == 32)
            restart(data);
        t = end(data);
        if (t == 1 || t == 0) {
            print(data);
            endwin();
            return (t);
        }
        if (t == KEY_EXIT) {
            endwin();
            return (84);
        }
    }
}
