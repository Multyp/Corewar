/*
** my_strncmp.c for strcmp in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 17 19:29:35 2016 Clement Peau
** Last update Sun Mar 27 21:07:27 2016 Poc
*/

#include "asm.h"

int	my_strncmp(char *str1, char *str2, int nb)
{
  int	i;

  i = 0;
  while (i < nb)
    {
      if (str1[i] != str2[i])
	{
	  return (1);
	}
      i++;
    }
  return (0);
}
