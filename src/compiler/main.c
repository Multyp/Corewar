/*
** main.c for main in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 00:29:36 2016 Arthur ARNAUD
** Last update Sun Feb 28 00:50:19 2016 Arthur ARNAUD
*/

#include "asm.h"

int	main(int ac, char **av, char **env)
{
  s_label	*label;
  s_action	*action;

  if (!(label = create_label_list()) ||
      !(action = create_action_list()))
    return (1);
  lexer(label, action, av[1]);
}
