/*
** op_aff.c for op_aff in /CPE_2015_corewar/src/decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar  6 16:37:12 2016 Arthur ARNAUD
** Last update Sun Mar  6 16:38:42 2016 Arthur ARNAUD
*/

#include "decompiler.h"

int	op_aff(int fd_cor, int fd_s)
{
  unsigned char	c;
  unsigned char buf[5];
  unsigned int	nb;
  int		size_read;

  if (my_putstr_instruct("aff", fd_s) ||
      read(fd_cor, &c, 1) == -1)
    return (1);
  if ((size_read = check_codage(&c, fd_s)) == -1 ||
      my_memset(&buf, 0, size_read) ||
      read(fd_cor, &buf, size_read) < 0)
    return (1);
  buf[size_read] = 0;
  nb = convert_to_nb(buf, size_read);
  my_putnbr_file(nb, fd_s);
  if (write(fd_s, "\n", 1) < 0)
    return (1);
  return (0);
}
