/*
** my_putnbr.c for my_putnbr in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 24 17:33:01 2016 Poc
** Last update Thu Mar 24 17:40:54 2016 Poc
*/

#include "asm.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putnbr(int nb)
{
  if (nb / 10 > 0)
    {
      my_putnbr(nb / 10);
    }
  my_putchar (nb % 10 + 48);
}
