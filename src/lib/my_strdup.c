/*
** my_strdup.c for lol in /home/peau_c/rendu/PSU/PSU_2015_tetris
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Sat Mar  5 14:00:59 2016 Clement Peau
** Last update Fri Mar 18 17:28:52 2016 Arthur ARNAUD
*/

#include "asm.h"

char	*my_strdup(char *str)
{
  int	i;
  char	*dup;

  i = -1;
  if ((dup = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[++i])
    dup[i] = str[i];
  dup[i] = 0;
  return (dup);
}
