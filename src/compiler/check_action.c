/*
** check_action.c for check_action in /CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar  6 18:29:49 2016 Arthur ARNAUD
** Last update Sat Mar 26 20:40:16 2016 Arthur ARNAUD
*/

#include "asm.h"

int		check_name(char *str, t_action *action, t_pos *pos)
{
  char		**tab;
  int		i;

  i = 0;
  if ((tab = str_to_word_tab
	("live ld st add sub and or xor zjmp ldi sti fork lld lldi lfork aff"
	 , ' ')) == NULL)
    return (write(2, "Can't perform malloc\n", 21), -1);
  while (tab[i])
    {
      if (my_strcmp(tab[i], str) == 0)
	{
	  action->instruction = str;
	  free_tab(tab);
	  return (i);
	}
      i++;
    }
  free_tab(tab);
  return (print_error("Syntax error\n", pos->line, -1));
}

int		check_action(char *str, t_action *action,
			     t_pos *pos, t_ftab *ftab)
{
  char		**tab;
  t_action	*new_action;
  int		ret;

  if (!check_empty(str))
    return (0);
  if (!(new_action = create_action_list()) ||
      !(str = format_instruction(str)) ||
      !(tab = cut_instruction(str)) ||
      (ret = check_name(tab[0], new_action, pos)) == -1)
    return (1);
  if (ftab[ret] != NULL)
    {
      new_action->pos = 0;
      if (ftab[ret](new_action, tab[1], pos))
	return (1);
    }
  add_action(action, new_action);
  return (0);
}
