/*
** my_showtab.c for showtab in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Mar 21 19:13:22 2016 Poc
** Last update Mon Mar 21 19:38:00 2016 Poc
*/

#include "asm.h"

void	showtab(char **str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putstr(str[i]);
      write(1, "\n", 1);
      i++;
    }
}
