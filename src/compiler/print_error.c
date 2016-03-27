/*
** print_error.c for print_error in /CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Mar 24 17:29:58 2016 Arthur ARNAUD
** Last update Sat Mar 26 18:45:49 2016 Arthur ARNAUD
*/

#include "asm.h"

int	print_error(char *str, int line, int ret)
{
  write(2, "line ", 5);
  my_putnbr(line);
  write(2, ": ", 2);
  write(2, str, my_strlen(str));
  return (ret);
}
