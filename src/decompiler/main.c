/*
** main.c for main in /home/arnaud_e/rendu/cpe/corewar/src/decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Mar  2 01:35:46 2016 Arthur ARNAUD
** Last update Wed Mar  2 14:00:14 2016 Arthur ARNAUD
*/

#include "decompiler.h"

int	main(int ac, char **av, char **env)
{
  int	fd_s;
  int	fd_cor;
  ftab	*tab;

  if (ac < 2 ||
      (fd_cor = open(av[1], O_RDONLY)) == -1 ||
      (fd_s = open("test.s", O_RDWR | O_TRUNC | O_CREAT, 00644)) == -1)
    return (1);
  print_header(fd_cor, fd_s);
  tab = set_ftab(tab);
  while (fill_file(fd_cor, fd_s, tab));
  close(fd_cor);
  close(fd_s);
  return (0);
}
