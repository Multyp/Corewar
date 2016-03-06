/*
** check_line.c for check_line in /home/arnaud_e/rendu/cpe/corewar/include
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 29 11:47:09 2016 Arthur ARNAUD
** Last update Sun Mar  6 18:31:17 2016 Arthur ARNAUD
*/

#include "asm.h"

int	check_line(char **tab, t_action *action, t_label *label, t_pos *pos)
{
  t_ftab	ftab;
  int		i;

  if (!(tab = check_label(tab, label, pos)) ||
      !(set_ftab(ftab))
      (i = check_action(tab[0], pos->line)) == -1)
    return (-1);
  return (ftab[i](tab[1], action, pos));

}
