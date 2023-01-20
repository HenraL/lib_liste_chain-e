/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** jitter jitter
*/

int ll_strlen(char const *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}
