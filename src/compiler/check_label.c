/*
** check_label.c for check_label in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 29 12:45:46 2016 Arthur ARNAUD
** Last update Sun Mar  6 18:29:06 2016 Arthur ARNAUD
*/

#include "asm.h"

int	check_label(char **tab, t_action *label, t_pos *pos)
{
  int	i;
  int	len;

  i = 0;
  len = my_strlen(tab[0]);
  if (tab[0][len - 1] != ':')
    return (tab);
  if (is_valid_label(tab[0], pos->line) ||
      add_to_label(tab[0], pos->adress, label))
    return (1);
}
