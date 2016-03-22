/*
** check_label.c for check_label in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 29 12:45:46 2016 Arthur ARNAUD
** Last update Tue Mar 22 13:36:14 2016 Arthur ARNAUD
*/

#include "asm.h"

char		*check_label(char *str, t_label *label, t_pos *pos)
{
  int		i;
  int		len;
  t_label	*new_label;

  i = -1;
  printf("\n--------RECUP_LABEL--------\n", str);
  if (!(str = epur_str(str)) ||
      !(new_label = create_label_list()))
    return (NULL);
  len = my_strlen(str);
  while (str[++i] != 0 && str[i] != ' ' && str[i] != '\n' && str[i] != '\t');
  if (i <= len && str[i - 1] == ':' && is_valid_label(str, i - 1))
    if (!(str = add_to_label(str, pos->prog_size, label, i)) ||
	!(str = epur_str(str)))
      return (NULL);
  // ajout de maillon vide <3
  printf("str_sans_label = |%s|\n---------------------------\n", str);
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
