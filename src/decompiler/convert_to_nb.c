/*
** convert_to_nb.c for convert_to_nb in /CPE_2015_corewar/src/decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Mar  3 10:28:28 2016 Arthur ARNAUD
** Last update Thu Mar  3 18:05:29 2016 Arthur ARNAUD
*/

#include "decompiler.h"

unsigned int	convert_to_nb(unsigned char *str, int size)
{
  unsigned int	res;
  int		factor;

  res = 0;
  factor = 1;
  while (--size >= 0)
    {
      res += (str[size] * factor);
      factor *= 256;
    }
  return (res);
}
