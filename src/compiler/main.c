/*
** main.c for main in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 00:29:36 2016 Arthur ARNAUD
** Last update Mon Mar 21 18:56:46 2016 Poc
*/

#include "asm.h"

int	main(int ac, char **av)
{
  t_label	*label;
  t_action	*action;
  t_header	header;


  if (!(label = create_label_list()) ||
      !(action = create_action_list()))
    return (1);
  if (ac == 1)
    {
      write(2, "Usage : ./asm file.s\n", 21);
    }
  lexer(label, action, &header, av[1]);
}
