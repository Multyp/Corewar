/*
** op_sti.c for op_sti in /home/arnaud_e/rendu/cpe/corewar/src/decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Mar  2 09:29:32 2016 Arthur ARNAUD
** Last update Wed Mar  2 10:40:20 2016 Arthur ARNAUD
*/

#include "decompiler.h"

int	op_sti(int fd_cor, int fd_s)
{
  unsigned char	c;
  unsigned char *buf;
  int		nb;
  int		i;
  int		size_read;

  if (read(fd_cor, &c, 1) == -1)
    return (1);
  while (i < 3)
    {
      if ((size_read = check_codage(&c, fd_s)) == -1 ||
	  !(buf = malloc(sizeof(unsigned char) * (size_read + 1))) ||
	  !(my_memset(&buf, 0, size_read)) ||
	  read(fd_cor, &buf, size_read) == -1)
	return (1);
      buf[size_read] = 0;
      /* nb = convert_to_nb(buf); */
      /* my_putnbr_file(nb); */
      if (i < 2 && write(fd_s, ",", 1) == -1)
	return (1);
      free(buf);
    }
  if (write(fd_s, "\n", 1) == -1)
    return (1);
}
