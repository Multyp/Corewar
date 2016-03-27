/*
** main.c for main in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 00:29:36 2016 Arthur ARNAUD
** Last update Sun Mar 27 22:44:20 2016 Poc
*/

#include "asm.h"

int	main(int ac, char **av)
{
  t_label	*label;
  t_action	*action;
  t_header	header;
  int		fd;

  if (ac != 2)
    return (write(2, "Usage : ./asm file.s\n", 21), 1);
  my_memset(&header, 0, sizeof(t_header) - 4);
  header.magic = 0xF383EA00;
  if (!(label = create_label_list()) ||
      !(action = create_action_list()) ||
      (fd = open(av[1], O_RDONLY)) == -1)
    {
      write(2, "Cannot find file\n", 17);
      return (1);
    }
  if (lexer(label, action, &header, fd))
    return (1);
  close (fd);
  if (parser(label, action, &header, av[1]))
    return (1);
    free_lists(label, action);
  return (0);
}
