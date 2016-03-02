/*
** check_codage.c for check_codage in /cpe/corewar/src/decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Mar  2 07:58:06 2016 Arthur ARNAUD
** Last update Wed Mar  2 10:25:46 2016 Arthur ARNAUD
*/

#include "decompiler.h"

int	check_codage(unsigned char *byte, int fd_s)
{
  int	value;

  value = 0;
  if ((byte & 192) == 64 && !(value = 1))
    {
      if (write(fd_s, "r" ,1))
	return (-1);
    }
  else if ((byte & 192) == 128)
    value = 2;
  else if ((byte & 192) == 192 && !(value = 4))
    if (write(fd_s, "%" ,1))
      return (-1);
  *byte = *byte << 2;
  return (value);
}
