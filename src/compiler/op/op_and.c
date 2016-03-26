/*
** op_and.c for op_and in /CPE_2015_corewar/src/compiler/op
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Mar 24 04:02:38 2016 Arthur ARNAUD
** Last update Sat Mar 26 23:33:59 2016 Poc
*/

#include "asm.h"

int	op_and(t_action *action, char *str, t_pos *pos)
{
  int	i;
  char	c;
  char	type;
  char	**tab;
  char	**list_arg;

  if ((c = 0) || !(pos->prog_size += 2) || !(action->pos = pos->prog_size) ||
      !(i = -1) || !(action->identifier = 0x06) ||
      !(action->args = malloc(sizeof(t_arg *) * 4)) ||
      !(tab = str_to_word_tab(str, ',')) ||
      !(list_arg = str_to_word_tab("123 123 1", ' ')) ||
      init_args(action, 3))
    return (1);
  while (tab[++i])
    {
      if (i > 2 || (type = check_type(tab[i], pos)) == -1 ||
	  check_args(type, list_arg[i], pos) ||
	  fill_arg(type, tab[i], action->args[i], action->pos - 2))
	return (1);
      add_prog_size(type, pos);
      c += (type << (6 - (i * 2)));
    }
  action->coding_byte = c;
  return ((i < 3) ? 1 : 0);
}
