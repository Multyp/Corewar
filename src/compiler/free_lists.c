/*
** free_lists.c for freelists in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sun Mar 27 17:54:07 2016 Poc
** Last update Sun Mar 27 21:36:27 2016 Marwane
*/

#include "asm.h"

void	free_labels(t_label *label)
{
  t_label *tmp;

  while (label)
    {
      tmp = label;
      free(label->name);
      label = label->next;
      free(tmp);
    }
}

void	free_args(t_arg **args)
{
  int	i;

  i = 0;
  while (args[i])
    {
      free(args[i]->link_name);
      free(args[i]);
      i++;
    }
  free(args);
}

void	free_action(t_action *action)
{
  t_action *tmp;

  while (action)
    {
      tmp = action;
      free(tmp->instruction);
      free_args(action->args);
      action = action->next;
      free(tmp);
    }
}

void	free_lists(t_label *label, t_action *action)
{
  free_labels(label);
  free_action(action);
}
