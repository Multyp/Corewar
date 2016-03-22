/*
** is_char.c for char in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 22 19:10:13 2016 Poc
** Last update Tue Mar 22 19:34:48 2016 Poc
*/

#include "asm.h"

int	icubed(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	return (0);
    }
}
