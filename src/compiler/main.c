/*
** main.c for main in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 00:29:36 2016 Arthur ARNAUD
** Last update Thu Mar 24 15:41:26 2016 Poc
*/

#include "asm.h"

int	main(int ac, char **av)
{
  t_label	*label;
  t_action	*action;
  t_header	header;
  int		fd;

  my_memset(&header, 0, sizeof(t_header) - 4);
  header.magic = 0x00ea83f3;
  if (!(label = create_label_list()) ||
      !(action = create_action_list()) ||
      (fd = open(av[1], O_RDONLY)) == -1)
    return (1);
  if (ac == 1)
    write(2, "Usage : ./asm file.s\n", 21);
  lexer(label, action, &header, fd);
  close (fd);
  parser(label, action, &header, av[1]);
}
