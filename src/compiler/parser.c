/*
** parser.c for parser.c in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 24 12:58:41 2016 Poc
** Last update Fri Mar 25 11:38:41 2016 Poc
*/

#include "asm.h"

int	parser(t_label *label, t_action *action, t_header *header, char *name)
{
  int	fd;

  if ((fd = write_header(header, name)) == -1)
    return (1);
  while (action)
    {
      write_action(action, fd, label);
      action = action->next;
    }
  close(fd);
  return (0);
}
