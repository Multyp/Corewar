/*
** my_getbase.c for getbase in /home/da-fon_s/rendu/My_printf
** 
** Made by samuel da-fonseca
** Login   <da-fon_s@epitech.net>
** 
** Started on  Mon Nov  9 19:11:16 2015 samuel da-fonseca
** Last update Fri Jan 29 09:56:24 2016 samuel da-fonseca
*/

#include "libmy.h"

char	*my_getbase(unsigned int nb, char *base)
{
  char  *final;
  int   j;
  int	b;

  b = my_strlen(base);
  j = 0;
  final = malloc(sizeof(int) * (b + 1));
  while (nb != 0)
    {
      final[j] = base[nb % b];
      nb = nb / b;
      j = j + 1;
    }
  final[j] = '\0';
  final = my_revstr(final);
  return (final);
}
