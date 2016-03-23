/*
** my_memset.c for memset in /home/da-fon_s/lib
**
** Made by samuel da-fonseca
** Login   <da-fon_s@epitech.net>
**
** Started on  Thu Jan 28 19:08:41 2016 samuel da-fonseca
** Last update Wed Mar 23 03:28:49 2016 Da Fonseca Samuel
*/

#include "libmy.h"

char	*my_memset(char *s, int c, int size)
{
  int	n;

  if (size < 0)
    return (s);
  n = 0;
  while (n < size)
    {
      s[n] = c;
      n++;
    }
  return (s);
}

int	*my_imemset(int *s, int c, int size)
{
  int	n;

  if (!s || size < 0)
    return (s);
  n = 0;
  while (s && s[n] && n < size)
    {
      s[n] = c;
      n++;
    }
  return (s);
}
