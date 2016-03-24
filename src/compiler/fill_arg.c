/*
** fill_arg.c for fill_arg in /CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Mar 22 20:37:20 2016 Arthur ARNAUD
** Last update Thu Mar 24 00:40:25 2016 Arthur ARNAUD
*/

#include "asm.h"

int	fill_arg(char type, char *str, t_arg *arg, t_pos *pos)
{
  arg->type = type;
  arg->pos_link = 0;
  arg->link_name = NULL;
  if (type == 1)
    arg->value = my_getnbr(str + 1);
  else if (type == 2)
    {
      if (str[1] == LABEL_CHAR && !(arg->value = 0) &&
	  (arg->pos_link = pos->prog_size) &&
	  !(arg->link_name = my_strdup(str + 2)))
	return (1);
      else
	arg->value = my_getnbr(str + 1);
    }
  else
    arg->value = my_getnbr(str);
  return (0);
}
