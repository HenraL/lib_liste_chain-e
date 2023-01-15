/*
** EPITECH PROJECT, 2022
** tmp
** File description:
** hl_strlen.c
*/

int hl_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
