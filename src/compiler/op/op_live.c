/*
** op_live.c for op_live in /CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Mar 22 14:58:29 2016 Arthur ARNAUD
** Last update Sun Mar 27 20:23:12 2016 Poc
*/

#include "asm.h"

int	op_live(t_action *action, char *str, t_pos *pos)
{
  int	i;
  char	type;
  char	**tab;
  char	**list_arg;

  pos->prog_size += 1;
  action->pos = pos->prog_size;
  action->identifier = 0x01;
  i = -1;
  if (!(action->args = malloc(sizeof(t_arg *) * 2)) ||
      !(tab = str_to_word_tab(str, ',')) ||
      !(list_arg = str_to_word_tab("2", ' ')) ||
      init_args(action, 1))
    return (1);
  while (tab[++i])
    if (i > 0 || (type = check_type(tab[i], pos)) == -1 ||
	check_args(type, list_arg[i], pos) ||
	fill_arg(type, tab[i], action->args[i], action->pos - 1) ||
	add_prog_size(type, pos))
      return (1);
  action->coding_byte = 0;
  return (free_tab(tab), free_tab(list_arg), (i < 1) ? 1 : 0);
}
