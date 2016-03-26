/*
** fill_arg.c for fill_arg in /CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Mar 22 20:37:20 2016 Arthur ARNAUD
** Last update Sat Mar 26 23:20:23 2016 Poc
*/

#include "asm.h"

int	fill_pos(t_arg *arg, int pos)
{
  arg->pos_link = pos;
  return (1);
}

int	fill_arg(char type, char *str, t_arg *arg, int pos)
{
  int	ret;

  ret = 0;
  arg->type = type;
  arg->pos_link = 0;
  arg->link_name = NULL;
  if (type == 1)
    arg->value = my_getnbr(str + 1, &ret);
  else if (type == 2)
    {
      if (str[1] == LABEL_CHAR && !(arg->value = 0) &&
	  fill_pos(arg, pos) &&
	  !(arg->link_name = my_strdup(str + 2)))
	return (1);
      else
	arg->value = my_getnbr(str + 1, &ret);
    }
  else
    arg->value = my_getnbr(str, &ret);
  if (ret == -1)
    return (1);
  return (0);
}
