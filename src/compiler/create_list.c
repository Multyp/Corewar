/*
** create_list.c for create_list in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 00:59:33 2016 Arthur ARNAUD
** Last update Sun Feb 28 01:09:07 2016 Arthur ARNAUD
*/

t_label		*create_label_list()
{
  t_label	*label;

  if (!(label = malloc(sizeof(t_label))))
    return (NULL);
  label->next = label;
  label->prev = label;
  label->name = NULL;
  label->pos = 0;
  return (label);
}

t_action	*create_label_list()
{
  t_action	*action;

  if (!(action = malloc(sizeof(t_action))))
    return (NULL);
  action->next = action;
  action->prev = action;
  action->identifier = NULL;
  action->args = NULL;
  return (action);
}
