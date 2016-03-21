/*
** my_strcpy.c for strcpy in /home/da-fon_s/lib
** 
** Made by samuel da-fonseca
** Login   <da-fon_s@epitech.net>
** 
** Started on  Thu Jan 28 18:34:35 2016 samuel da-fonseca
** Last update Fri Jan 29 09:59:11 2016 samuel da-fonseca
*/

#include "libmy.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  if (!dest)
    return (NULL);
  while (src && src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  if (!src)
    return (dest);
  while (src && src[i] && i != n)
    {
      dest[i] = src[i];
      i++;
    }
  while (i < n)
    dest[i++] = '\0';
  return (dest);
}
