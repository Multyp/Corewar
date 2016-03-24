/*
** op_sti.c for op_sti in /CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Mar 23 00:26:41 2016 Arthur ARNAUD
** Last update Thu Mar 24 02:10:55 2016 Arthur ARNAUD
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
      !(list_arg = str_to_word_tab("1 123 123", ' ')) ||
      init_args(action, 3))
    return (1);
  while (tab[++i])
    {
      printf("arg = %s\n", tab[i]);
      if (i > 2 || (type = check_type(tab[i], pos)) == -1 ||
	  check_args(type, list_arg[i], pos) ||
	  fill_arg(type, tab[i], action->args[i], pos))
	return (1);
      printf("lol\n");
      add_prog_size(type, pos);
      /* create_codage(type, &c); */
      printf("action->args[%d]->type = %d\n", i, action->args[i]->type);
      printf("action->args[%d]->link_name = %s\n", i,
	     action->args[i]->link_name);
      printf("action->args[%d]->pos_link = %d\n", i,
	     action->args[i]->pos_link);
      printf("action->args[%d]->value = %d\n", i, action->args[i]->value);
    }
  printf("action->identifier = %d\n", action->identifier);
  printf("action->instruction = %s\n", action->instruction);
  return ((i < 3) ? 1 : 0);
}
