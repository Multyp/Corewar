/*
** add_to_list.c for add_to_list in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 17 15:30:59 2016 Clement Peau
** Last update Sat Mar 26 17:33:07 2016 Arthur ARNAUD
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
    return (write(2, "Can't perform malloc\n", 21), 1);
  tmp->next = tmp_list->next;
  tmp->str = str;
  tmp_list->next = tmp;
  return (0);
}

int		add_action(t_action *action, t_action *new_action)
{
  t_action	*tmp_list;

  if (action->instruction == NULL)
    {
      action->next = NULL;
      action->coding_byte = new_action->coding_byte;
      action->instruction = new_action->instruction;
      action->identifier = new_action->identifier;
      action->args = new_action->args;
      free(new_action);
      return (0);
    }
  tmp_list = action;
  while (tmp_list->next)
    tmp_list = tmp_list->next;
  tmp_list->next = new_action;
  new_action->next = NULL;
  return (0);
}

int		add_label(t_label *label, t_label *new_label)
{
  t_label	*tmp_label;

  if (label->name == NULL)
    {
      label->next = NULL;
      label->name = new_label->name;
      label->pos = new_label->pos;
      free(new_label);
      return (0);
    }
  tmp_label = label;
  while (tmp_label->next)
    tmp_label = tmp_label->next;
  tmp_label->next = new_label;
  new_label->next = NULL;
  return (0);
}
