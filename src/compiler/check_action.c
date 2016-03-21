/*
** check_action.c for check_action in /CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar  6 18:29:49 2016 Arthur ARNAUD
** Last update Mon Mar 21 22:46:09 2016 Poc
*/

#include "asm.h"

int		check_name(char *str, t_action *action)
{
  char		**tab;
  int		i;

  i = 0;
  if ((tab = my_wordtab
	("live ld st add sub and or xor zjmp ldi sti fork lld lldi lfork aff"
	 , ' ')) == NULL)
    return (-1);
  while (tab[i])
    {
      if (my_strcmp(tab[i], str) == 0)
	{
	  printf("strcmp match -> tab[i] |%s| et str |%s|\n", tab[i], str);
	  action->identifier = str;
	  printf("action->identifer -> %s\n", action->identifier);
	  free_tab(tab);
	  return (i);
	}
      i++;
    }
  free_tab(tab);
  return (-1);
}

int		check_action(char *str, t_action *action, t_pos *pos)
{
  int		i;
  char		**tab;
  t_action	*new_action;
  int		ret;

  if ((new_action = create_action_list()) == NULL)
    return (1);
  str = format_instruction(str);
  tab = cut_instruction(str);
  if ((ret = check_name(tab[0], new_action)) == -1) // check if the name matche an instruction //and add it in action->instruction;
    return (1);
  /* if (ftab[ret](t_action *, tab[1], pos)) */
  /*   return (1); */
  add_action(action, new_action);
  return (0);
}
