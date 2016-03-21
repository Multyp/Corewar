/*
** create_list.c for create_list in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 00:59:33 2016 Arthur ARNAUD
** Last update Mon Mar 21 20:49:45 2016 Poc
*/

#include "asm.h"

t_file		*create_file_list(char *str)
{
  t_file	*file;

  if ((file = malloc(sizeof(t_file))) == NULL)
    return(NULL);
  file->next = NULL;
  file->str = str;
  return (file);
}

t_label		*create_label_list()
{
  t_label	*label;

  if (!(label = malloc(sizeof(t_label))))
    return (NULL);
  label->next = label;
  label->name = NULL;
  label->pos = 0;
  return (label);
}

t_action	*create_action_list()
{
  t_action	*action;

  if (!(action = malloc(sizeof(t_action))))
    return (NULL);
  action->next = NULL;
  action->identifier = NULL;
  action->identifier = NULL;
  action->args = NULL;
  return (action);
}
