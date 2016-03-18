/*
** my_memset.c for my_memset in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Feb 24 19:49:39 2016 Arthur ARNAUD
** Last update Thu Mar  3 09:01:01 2016 Arthur ARNAUD
*/

#include "decompiler.h"

int	my_memset(void *mem, char c, int size)
{
  unsigned char	*str;

  str = mem;
  while (size--)
    str[size] = c;
  return (0);
}
