/*
** EPITECH PROJECT, 2022
** strlen
** File description:
** strlen
*/

int nb_line(char *s)
{
    int nb = 0;

    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == '\n')
            nb++;
    return (nb);
}

int my_strlen_n_s(char *s, int l)
{
    int i = 0;
    int	nb = 0;
    int i_back = 0;
    int n = 0;

    for (; n != l; i++) {
        if (s[i] == '\n') {
            nb = i - i_back;
            i_back = i;
            n++;
        }
    }
    return (nb);
}

int my_strlen_n(char *s)
{
    int i = 0;

    for (; s[i] != '\n'; i++);
    return (i);
}

int my_strlen(char *s)
{
    int i = 0;

    for (; s[i] != '\0'; i++);
    return (i);
}
