/*
** main.c for main in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 00:29:36 2016 Arthur ARNAUD
** Last update Thu Mar 17 12:22:31 2016 Clement Peau
*/

#include "asm.h"

int	main(int ac, char **av, char **env)
{
  t_label	*label;
  t_action	*action;
  t_header	header;


  if (!(label = create_label_list()) ||
      !(action = create_action_list()))
    return (1);
  lexer(label, action, &header, av[1]);
}
