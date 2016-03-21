/*
** my_strseek.c for seek in /home/da-fon_s/lib
**
** Made by samuel da-fonseca
** Login   <da-fon_s@epitech.net>
**
** Started on  Thu Jan 28 19:39:47 2016 samuel da-fonseca
** Last update Sun Mar 20 14:35:08 2016 marwane khsime
*/

#include "libmy.h"

int	my_checkstr(char *str, char c)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  if (!str)
    return (-1);
  while (str && str[i])
    {
      if (str[i] == c)
        n++;
      i++;
    }
  return (n);
}

int	my_strseek(char *dest, char *src, int start)
{
  int	i;
  int	j;

  i = start;
  j = 0;
  while (dest && src && dest[i] == src[j] && src[i])
    {
      i++;
      j++;
    }
  if (src && src[j] == '\0')
    return (1);
  return (0);
}
