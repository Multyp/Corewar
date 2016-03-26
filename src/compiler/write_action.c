/*
** write_action.c for write action in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 24 16:25:34 2016 Poc
** Last update Sat Mar 26 19:57:54 2016 Poc
*/

#include "asm.h"

int	write_args(t_arg *arg, int fd, t_label *label, int decal)
{
  if ((arg->type == 1 && write_registers(arg, fd, decal) == 1) ||
      (arg->type == 2 && write_direct(arg, fd, label, decal) == 1) ||
      (arg->type == 3 && write_indirects(arg, fd, decal) == 1) ||
      (arg->type == 4 && write_odds(arg, fd, label, decal) == 1))
    return (1);
  return (0);
}

int	write_action(t_action *action, int fd, t_label *label)
{
  int	decal;
  int	i;

  i = 0;
  decal = 0;
  write(fd , &action->identifier, 1);
  if (action->coding_byte != 0)
    write(fd, &action->coding_byte, 1);
  while (action->args[i])
    {
      if (write_args(action->args[i], fd, label, action->args[i]->pos_link))
	return (1);
      i++;
    }
  return (0);
}
