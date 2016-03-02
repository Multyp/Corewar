/*
** my_memset.c for my_memset in /home/arnaud_e/rendu/psu/PSU_2015_tetris/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Feb 24 19:49:39 2016 Arthur ARNAUD
** Last update Wed Mar  2 02:55:24 2016 Arthur ARNAUD
*/

#include "decompiler.h"

void	my_memset(void *mem, char c, int size)
{
  unsigned char	*str;

  str = mem;
  while (size--)
    str[size] = c;
}
