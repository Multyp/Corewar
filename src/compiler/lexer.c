/*
** lexer.c for lexer in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 16:03:05 2016 Arthur ARNAUD
** Last update Wed Mar 16 17:13:56 2016 Clement Peau
*/

#include "asm.h"


int	lexer(t_label *label, t_action *action, t_header *header, char *name)
{
  int	fd;
  char	**tab;
  t_pos	pos;

  if ((fd = open(name, O_RDONLY) == -1 ||
       !get_header(fd, header)))
    return (1);
  pos.prog_size = 0;
  pos.line = 0;
  while ((str = get_next_line(fd)))
    {
      if (!check_empty_line(str))
	{
	  if (!(tab = line_to_action_tab(str)) ||
	      (pos = check_line(tab, action, label, &pos)) == -1)
	    return (1);
	}
      pos.line += 1;
    }
}
