/*
** main.c for main in /home/arnaud_e/rendu/cpe/corewar/src/decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Mar  2 01:35:46 2016 Arthur ARNAUD
** Last update Tue Mar 15 17:49:30 2016 Clement Peau
*/

#include "decompiler.h"

int	main(int ac, char **av, char **env)
{
  t_header	header;
  int		fd_s;
  int		fd_cor;
  char		*name;
  ftab		*tab;

  if (*env == NULL|| ac < 2 ||
      (fd_cor = open(av[1], O_RDONLY)) == -1 ||
      my_memset(&header, 0, sizeof(t_header)) ||
      read(fd_cor, &header, sizeof(t_header)) < 0 ||
      header.magic_number != (int)0xF383EA00 ||
      !(name = new_name(av[1])) ||
      (fd_s = open(name, O_RDWR | O_TRUNC | O_CREAT, 00644)) == -1 ||
      print_header(fd_s, &header))
    return (1);
  tab = NULL;
  tab = set_ftab(tab);
  while (!fill_file(fd_cor, fd_s, tab));
  close(fd_cor);
  close(fd_s);
  return (0);
}
