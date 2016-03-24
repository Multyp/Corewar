/*
** write_action.c for write action in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 24 16:25:34 2016 Poc
** Last update Thu Mar 24 23:07:47 2016 Poc
*/

#include "asm.h"

int	write_args(t_arg *arg, int fd)
{
  if (arg->type == 1)
    write_registers();
  else if (arg->type == 2)
    write_direct();
  else if (arg->type == 3)
    write_indirects();
  return (0);
}

int	write_action(t_action *action, int fd)
{
  int	i;

  i = 0;
  if (action->coding_byte != 0)
    printf("Coding byte-> %x\n", action->coding_byte);
  else
    printf("Coding byte -> 0\n");
  write(fd , &action->identifier, 1);
  while (action->args[i])
    {
      printf("action->identifier %d\n", action->identifier);
      printf("action->args->link_name %s\n", action->args[i]->link_name);
      printf("action->args->type %d\n", action->args[i]->type);
      printf("action->args->pos_link = %d\n", action->args[i]->pos_link);
      printf("action->args->value %d\n", action->args[i]->value);
      write(fd, &action->coding_byte, 1);
      write_args(action->args[i], fd);
      i++;
    }
  printf("action-> %s\n", action->instruction );
  printf("\n");
  return (0);
}
