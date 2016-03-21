/*
** my_strcat.c for strcat in /home/da-fon_s/lib
** 
** Made by samuel da-fonseca
** Login   <da-fon_s@epitech.net>
** 
** Started on  Thu Jan 28 18:31:23 2016 samuel da-fonseca
** Last update Fri Jan 29 09:58:47 2016 samuel da-fonseca
*/

#include "libmy.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (!dest)
    return (NULL);
  while (dest && dest[i])
    i++;
  while (src && src[j] && dest && dest[i])
    {
      dest[i] = src[j];
      i++;
      j++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strncat(char *dest, char *src, int n)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  if (!dest)
    return (NULL);
  if (n < 0)
    return (dest);
  while (dest && dest[i])
    i++;
  while (src && src[j] && dest && dest[i] && j != n)
    {
      dest[i] = src[j];
      i++;
      j++;
    }
  dest[i] = '\0';
  return (dest);
}
