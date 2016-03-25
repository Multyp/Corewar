/*
** write_action.c for write action in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 24 16:25:34 2016 Poc
** Last update Fri Mar 25 17:56:10 2016 Poc
*/

#include "asm.h"

int	write_args(t_arg *arg, int fd, t_label *label)
{
  if (arg->type == 1 && write_registers(arg, fd) == 1 ||
      arg->type == 2 && write_direct(arg, fd, label) == 1 ||
      arg->type == 3 && write_indirects(arg, fd) == 1 ||
      arg->type == 4 && write_odds(arg, fd, label) == 1)
    {
      printf("WRITE_ARGS---Returning...\n");
      return (1);
    }
  return (0);
}

int	write_action(t_action *action, int fd, t_label *label)
{
  int	i;

  i = 0;
  write(fd , &action->identifier, 1);
  if (action->coding_byte != 0)
    write(fd, &action->coding_byte, 1);
  while (action->args[i])
    {
      printf("WRITE_ACTION---action->identifier %d\n", action->identifier);
      printf("WRITE_ACTION---action->args->link_name %s\n", action->args[i]->link_name);
      printf("WRITE_ACTION---action->args->type %d\n", action->args[i]->type);
      printf("WRITE_ACTION---action->args->pos_link = %d\n", action->args[i]->pos_link);
      printf("WRITE_ACTION---action->args->value %d\n", action->args[i]->value);
      if (write_args(action->args[i], fd, label))
	{
	  printf("WRITE_ACTION---Returning...\n");
	  return (1);
	}
      i++;
    }
  printf("WRITE_ACTION---action-> %s\n", action->instruction );
  printf("\n");
  return (0);
}
