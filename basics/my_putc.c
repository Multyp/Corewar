/*
** my_putc.c for putc in /home/da-fon_s/lib
** 
** Made by samuel da-fonseca
** Login   <da-fon_s@epitech.net>
** 
** Started on  Thu Jan 28 18:12:34 2016 samuel da-fonseca
** Last update Fri Jan 29 09:57:11 2016 samuel da-fonseca
*/

#include "libmy.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    my_putchar(str[i++]);
}
