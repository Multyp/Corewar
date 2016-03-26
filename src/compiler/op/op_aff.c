/*
** op_aff.c for op_aff in /CPE_2015_corewar/src/compiler/op
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Mar 24 04:11:57 2016 Arthur ARNAUD
** Last update Sat Mar 26 17:40:24 2016 Arthur ARNAUD
*/

#include "asm.h"

int	op_aff(t_action *action, char *str, t_pos *pos)
{
  int	i;
  char	c;
  char	type;
  char	**tab;
  char	**list_arg;

  if ((c = 0) || !(pos->prog_size += 2) ||
      !(i = -1) || !(action->identifier = 0x0E) ||
      !(action->args = malloc(sizeof(t_arg *) * 2)) ||
      !(tab = str_to_word_tab(str, ',')) ||
      !(list_arg = str_to_word_tab("1", ' ')) ||
      init_args(action, 1))
    return (1);
  while (tab[++i])
    {
      if (i > 0 || (type = check_type(tab[i], pos)) == -1 ||
	  check_args(type, list_arg[i], pos) ||
	  fill_arg(type, tab[i], action->args[i], action->pos - i - 1))
	return (1);
      add_prog_size(type, pos);
      c += (type << (6 - (i * 2)));
    }
  action->coding_byte = c;
  return ((i < 1) ? 1 : 0);
}
