/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#include "my.h"

int create_tab(char *buffer, data *data);

int open_map(char *argv, data *data)
{
    int re = 0;
    int fd = open(argv, O_RDONLY);
    struct stat Info;
    struct stat *info = &Info;

    if (fd == -1)
        return (84);
    re = stat(argv, info);
    if (re == 0) {
        char buffer[info->st_size];
        read(fd, buffer, info->st_size);
        re = create_tab(buffer, data);
        close(fd);
        return (re);
    }
    return (84);
}

int main(int argc, char **argv)
{
    data Data;
    data *data = &Data;

    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h'
            && argv[1][2] == '\0') {
            write(1, "USAGE\n", 6);
            write(1, "     ./my_sokoban map\n", 22);
            write(1, "DESCRIPTION\n", 12);
            write(1, "     map file representing the warehouse map"
            ", containing ‘#’ for walls, ‘P’ for the player,"
            "‘X’ for boxes and ‘O’ for storage locations.\n", 153);
            return (0);
        } else {
            return (open_map(argv[1], data));
        }
    }
    return (84);
}
