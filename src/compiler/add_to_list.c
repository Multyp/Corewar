/*
** add_to_list.c for add_to_list in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 17 15:30:59 2016 Clement Peau
** Last update Tue Mar 22 14:45:01 2016 Poc
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

int		add_action(t_action *action, t_action *new_action)
{
  t_action	*tmp_list;

  tmp_list = action;
  while (tmp_list->next)
    tmp_list = tmp_list->next;
  tmp_list->next = new_action;
  return (0);
}

int		add_label(t_label *label, t_label *new_label)
{
  t_label	*tmp_label;

  tmp_label = label;
  while (tmp_label->next)
    tmp_label = tmp_label->next;
  tmp_label->next = new_label;
  return (0);
}
