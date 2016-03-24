/*
** parser.c for parser.c in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 24 12:58:41 2016 Poc
** Last update Thu Mar 24 16:52:04 2016 Poc
*/

#include "asm.h"

int	parser(t_label *label, t_action *action, t_header *header, char *name)
{
  int	fd;

  if ((fd = write_header(header, name)) == -1)
    return (1);
  while (action->next)
    {
      write_action(action, fd);
      action = action->next;
    }
  return (0);
}
