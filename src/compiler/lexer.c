/*
** lexer.c for lexer in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 16:03:05 2016 Arthur ARNAUD
** Last update Fri Mar 18 16:56:13 2016 Arthur ARNAUD
*/

#include "asm.h"


int	lexer(t_label *label, t_action *action, t_header *header, char *name)
{
  int		fd;
  char		**tab;
  t_pos		pos;

  fd = -1;
  if (((fd = open(name, O_RDONLY)) == -1))
    return (1);
  pos.prog_size = 0;
  pos.line = 0;
  while ((str = get_line_not_empty(fd, &pos.line)) != NULL)
    {
      if (get_header(str, header))
	return (1);
      if (header->full)
	{
	  if (!(str = check_label(str, label, pos)))
	    return (1);
	  if (!check_empty_line(str))
	    if (!(fill_check_action(str, action, pos)))
	      return (1);
	}
      pos.line += 1;
    }
  return (0);
}
