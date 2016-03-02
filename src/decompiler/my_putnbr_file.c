/*
** my_putnbr_file.c for my_putnbr_file in corewar/src/decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Mar  2 10:28:41 2016 Arthur ARNAUD
** Last update Wed Mar  2 10:28:48 2016 Arthur ARNAUD
*/

#include <unistd.h>

void	my_putchar_file(char c, int fd)
{
  write(fd, &c, 1);
}

void	my_putnbr_file(int nb, int fd)
{
  int	diviseur;

  diviseur = 1;
  if (nb < 0)
    {
      nb = -(nb);
      my_putchar('-');
    }
  while ((nb / diviseur) >= 10)
    diviseur = diviseur * 10;
  while (diviseur > 0)
    {
      my_putchar(48 + (nb / diviseur) % 10, fd);
      diviseur = diviseur / 10;
    }
}
