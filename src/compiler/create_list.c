/*
** create_list.c for create_list in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 00:59:33 2016 Arthur ARNAUD
** Last update Sun Mar 27 19:24:51 2016 Poc
*/

#include "asm.h"

t_label		*create_label_list()
{
  t_label	*label;

  if (!(label = malloc(sizeof(t_label))))
    return (write(2, "Can't perform malloc\n", 21), NULL);
  label->next = NULL;
  label->name = NULL;
  label->pos = 0;
  return (label);
}

t_action	*create_action_list()
{
  t_action	*action;

  if (!(action = malloc(sizeof(t_action))))
    return (write(2, "Can't perform malloc\n", 21), NULL);
  action->next = NULL;
  action->instruction = NULL;
  action->args = NULL;
  return (action);
}
