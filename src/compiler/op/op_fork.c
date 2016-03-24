/*
1;4205;0c** op_fork.c for op_fork in /CPE_2015_corewar/src/compiler/op
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Mar 24 01:18:25 2016 Arthur ARNAUD
** Last update Thu Mar 24 17:23:17 2016 Arthur ARNAUD
*/

#include "asm.h"

int	op_fork(t_action *action, char *str, t_pos *pos)
{
  int	i;
  char	type;
  char	**tab;
  char	**list_arg;

  pos->prog_size += 1;
  action->identifier = 0x0C;
  i = -1;
  if (!(action->args = malloc(sizeof(t_arg *) * 2)) ||
      !(tab = str_to_word_tab(str, ',')) ||
      !(list_arg = str_to_word_tab("2", ' ')) ||
      init_args(action, 1))
    return (1);
  while (tab[++i])
    {
      if (i > 0 || (type = check_type(tab[i], pos)) == -1 ||
	  check_args(type, list_arg[i], pos) ||
	  fill_arg(type, tab[i], action->args[i], pos))
	return (1);
      add_prog_size(type, pos);
      printf("action->args[1]->type = %d\n", action->args[0]->type);
      printf("action->args[1]->link_name = %s\n", action->args[0]->link_name);
      printf("action->args[1]->pos_link = %d\n", action->args[0]->pos_link);
      printf("action->args[1]->value = %d\n", action->args[0]->value);
      printf("action->identifier = %d\n", action->identifier);
      printf("action->instruction = %s\n", action->instruction);
    }
  action->coding_byte = 0;
  return ((i < 1) ? 1 : 0);
}
