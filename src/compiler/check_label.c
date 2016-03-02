/*
** check_label.c for check_label in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 29 12:45:46 2016 Arthur ARNAUD
** Last update Mon Feb 29 12:59:02 2016 Arthur ARNAUD
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
  if (!(is_valid_label(tab[0]))

}
