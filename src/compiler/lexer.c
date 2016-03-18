/*
** lexer.c for lexer in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 16:03:05 2016 Arthur ARNAUD
** Last update Fri Mar 18 19:07:53 2016 Clement Peau
*/

#include "asm.h"


int	lexer(t_label *label, t_action *action, t_header *header, char *name)
{
  int		fd;
  char		**tab;
  t_pos		pos;
  char		*str;

  fd = -1;
  if (((fd = open(name, O_RDONLY)) == -1))
    return (1);
  pos.prog_size = 0;
  pos.line = 0;
  header->full = 0;
  header->prog_name[0] = 0;
  while ((str = get_line_not_empty(fd, &pos.line)) != NULL)
    {
      if (header->full)
	{
	  printf("header->progname |%s|\n", header->prog_name);
	  printf("header->comment |%s|\n", header->comment);
	  if (!(str = check_label(str, label, &pos)))
	    return (1);
	  if (check_empty(str))
	    if (!(fill_check_action(str, action, &pos)))
	      return (1);
	}
      else
	if (get_header(str, header))
	  return (1);

      pos.line += 1;
    }
  return (0);
}
