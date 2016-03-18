/*
** check_label.c for check_label in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 29 12:45:46 2016 Arthur ARNAUD
** Last update Fri Mar 18 16:41:31 2016 Arthur ARNAUD
*/

#include "asm.h"

int	check_label(char *str, t_label *label, t_pos *pos)
{
  int	i;
  int	len;

  i = -1;
  if (!(str = epure_str(str)))
    return (NULL);
  while (str[++i] != 0 && str[i] != ' ');
  if (i <= my_strlen  && str[i - 1] == ':' && is_valid_label(str, i - 1))
    if (!(str = add_to_label(str, pos->adress, label. i - 1)))
      return (NULL);
  return (str);
}

int	is_valid_label(char *str, int i)
{
  int	k;

  k = -1;
  while (str[++k] < i)
    {
      if (is_char_valid(str[k], "abcdefghijklmnopqrstuvwxyz_0123456789"))
	return (0);
    }
  return (1);
}

int	is_char_valid(char c, char *list)
{
  int	i;

  i = -1;
  while (list[++i])
    {
      if (c == list[i])
	return (0);
    }
  return (1);
}
