/*
** op_lfork.c for op_lfork in /CPE_2015_corewar/src/decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar  6 16:02:01 2016 Arthur ARNAUD
** Last update Sun Mar  6 16:02:22 2016 Arthur ARNAUD
*/

#include "decompiler.h"

int	op_lfork(int fd_cor, int fd_s)
{
  unsigned char buf[5];
  int		nb;
  int		size_read;

  size_read = 2;
  if (my_putstr_instruct("lfork", fd_s) ||
      write(fd_s, "%", 1) < 0)
    return (1);
  if (my_memset(&buf, 0, size_read) ||
      read(fd_cor, &buf, size_read) < 0)
    return (1);
  buf[size_read] = 0;
  nb = convert_to_nb(buf, size_read);
  my_putnbr_file(nb, fd_s);
  if (write(fd_s, "\n", 1) < 0)
    return (1);
  return (0);
}
