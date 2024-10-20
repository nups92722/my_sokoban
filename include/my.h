/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush3
*/

#ifndef _MY_H__
    #define _MY_H__

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <time.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stddef.h>
    #include <ncurses/curses.h>
    #include <stdlib.h>
    #include <string.h>

    int nb_line(char *s);
    int my_strlen_n(char *s);
    int my_strlen(char *s);
    int my_strlen_n_s(char *s, int l);

    typedef struct Verif {
        int p;
        int x;
        int o;
    } verif;

    typedef struct Data {
        char **map;
        char **tab;
        char **base;
        int x;
        int y;
        int x_o;
        int y_o;
        int size_x;
        int size_y;
    } data;
#endif
