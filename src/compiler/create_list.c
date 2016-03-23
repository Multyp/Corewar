/*
** create_list.c for create_list in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 00:59:33 2016 Arthur ARNAUD
** Last update Tue Mar 22 19:43:07 2016 Arthur ARNAUD
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
  label->next = NULL;
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
  action->instruction = NULL;
  action->args = NULL;
  return (action);
}
