/*
** my_strlen.c for my_strlen in /CPE_2015_corewar/src/decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Fri Mar  4 16:49:58 2016 Arthur ARNAUD
** Last update Sun Mar  6 16:24:25 2016 Arthur ARNAUD
*/

#include "decompiler.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str)
    {
      while (str[i])
	{
	  i = i + 1;
	}
      return (i);
    }
  return (0);
}
