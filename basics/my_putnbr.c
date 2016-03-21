/*
** my_put_nbr.c for my_put_nbr_tetris in /home/marwane-khsime/rendu/Projets/PSU/PSU_2015_tetris/src
**
** Made by khsime_m
** Login   <khsime_m@epitech.net>
**
** Started on  Tue Feb 23 09:31:47 2016 khsime_m
** Last update Tue Feb 23 09:31:53 2016 khsime_m
*/

#include "libmy.h"

void	my_calcnb(int nb)
{
  if (nb >= 10)
    my_calcnb(nb / 10);
  if (nb > 0)
    my_putchar((nb % 10) + 48);
}

void	my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb == 0)
    my_putchar('0');
  else
    my_calcnb(nb);
}
