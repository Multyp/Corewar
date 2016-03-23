/*
** op_sti.c for op_sti in /CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Mar 23 00:26:41 2016 Arthur ARNAUD
** Last update Wed Mar 23 00:38:32 2016 Arthur ARNAUD
*/

#include "asm.h"

int	op_sti(t_action *action, char *str, t_pos *pos)
{
  int	i;
  char	c;
  char	type;
  char	**tab;
  char	**list_arg;

  c = 0;
  pos->prog_size += 2;
  action->identifier = 0x0B;
  i = -1;
  if (!(action->args = malloc(sizeof(t_arg *) * 4)) ||
      !(tab = str_to_word_tab(str, ',')) ||
      !(list_arg = str_to_word_tab("1 123 123", ' ')))
    return (1);
  action->args[3] = NULL;
  while (tab[++i])
    {
      if (i > 2 || (type = check_type(tab[i], pos)) == -1 ||
	  check_args(type, list_arg[i], pos) ||
	  fill_arg(type, tab[i], action->args[i], pos))
	return (1);
      add_prog_size(type, pos);
      create_codage(type, &c);
    }
  return ((i < 3) ? 1 : 0);
}
