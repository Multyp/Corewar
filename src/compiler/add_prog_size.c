/*
** add_prog_size.c for add_prog_size in CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Mar 22 21:09:48 2016 Arthur ARNAUD
** Last update Tue Mar 22 21:13:49 2016 Arthur ARNAUD
*/

#include "asm.h"

void	add_prog_size(char type, t_pos *pos)
{
  if (type == 1)
    pos->prog_size += 1;
  else if (type == 2)
    pos->prog_size += 4;
  else
    pos->prog_size += 2;
}
