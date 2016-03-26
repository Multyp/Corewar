/*
** my_strncmp.c for strcmp in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 17 19:29:35 2016 Clement Peau
** Last update Fri Mar 18 11:12:28 2016 Clement Peau
*/

#include "asm.h"

int	my_strncmp(char *str1, char *str2, int nb)
{
  int	i;

  i = -1;
  while (++i < nb)
      if (str1[i] != str2[i])
      return (0);
  return (1);
}
