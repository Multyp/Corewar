/*
** my_revstr.c for revstr in /home/da-fon_s/lib
** 
** Made by samuel da-fonseca
** Login   <da-fon_s@epitech.net>
** 
** Started on  Thu Jan 28 19:15:29 2016 samuel da-fonseca
** Last update Fri Jan 29 09:58:21 2016 samuel da-fonseca
*/

#include "libmy.h"

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  int	size;
  char	stock;

  i = 0;
  size = my_strlen(str);
  j = size - 1;
  if (!str)
    return (NULL);
  while (str && str[i] && i < (size / 2))
    {
      stock = str[i];
      str[i] = str[j];
      str[j] = stock;
      i++;
      j--;
    }
  return (str);
}
