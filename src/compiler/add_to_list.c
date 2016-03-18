/*
** add_to_list.c for add_to_list in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 17 15:30:59 2016 Clement Peau
** Last update Fri Mar 18 14:15:05 2016 Clement Peau
*/

#include "asm.h"

int		add_to_back_file(t_file *file, char *str)
{
  t_file	*tmp;
  t_file	*tmp_list;

  tmp_list = file;
  while (tmp_list->next != NULL)
      tmp_list = tmp_list->next;
  if ((tmp = malloc(sizeof(t_file))) == NULL)
    return (1);
  tmp->next = tmp_list->next;
  tmp->str = str;
  tmp_list->next = tmp;
  return (0);
}

int		add_to_back_action(t_action *action, char *str)
{
  t_action	*new_action;
  t_action	*tmp_action;

  tmp_action = action;
  while (tmp_action->next != NULL)
      tmp_action = tmp_action->next;
  if ((new_action = malloc(sizeof(t_action))) == NULL)
    return (1);
  new_action->next = tmp_action->next;
  new_action->str = str;
  tmp_action->next = new_action;
  printf("new->str |%s|\n", new_action->str);
  return (0);
}
