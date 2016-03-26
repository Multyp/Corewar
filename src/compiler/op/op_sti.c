/*
** op_sti.c for op_sti in /CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Mar 23 00:26:41 2016 Arthur ARNAUD
** Last update Sat Mar 26 23:24:04 2016 Poc
*/

#include "asm.h"

int	op_sti(t_action *action, char *str, t_pos *pos)
{
  int	i;
  char	c;
  char	type;
  char	**tab;
  char	**list_arg;

  if ((c = 0) || !(pos->prog_size += 2) || !(action->pos = pos->prog_size) ||
      !(i = -1) || !(action->identifier = 0x0B) ||
      !(action->args = malloc(sizeof(t_arg *) * 4)) ||
      !(tab = str_to_word_tab(str, ',')) ||
      !(list_arg = str_to_word_tab("1 123 12", ' ')) ||
      init_args(action, 3))
    return (1);
  while (tab[++i])
    {
      if (i > 2 || (type = check_type(tab[i], pos)) == -1 ||
	  check_args(type, list_arg[i], pos) ||
	  fill_arg(type, tab[i], action->args[i], action->pos - 2))
	return (1);
      c += (type << (6 - (i * 2)));
      change_to_odds(action->args[i], &type);
      add_prog_size(type, pos);
    }
  action->coding_byte = c;
  return ((i < 3) ? 1 : 0);
}
