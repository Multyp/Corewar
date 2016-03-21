/*
** my_strcat_two.c for my_str_cat_two in /home/marwane-khsime/rendu/Projets/PSU/test/PSU_2015_tetris/basics
**
** Made by khsime_m
** Login   <khsime_m@epitech.net>
**
** Started on  Wed Feb 24 01:57:23 2016 khsime_m
** Last update Wed Feb 24 02:18:28 2016 khsime_m
*/

#include "libmy.h"
#include <stdio.h>

char	*my_strcat_cpy(char *src, char *dest)
{
  char	*new;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (!(new = malloc(sizeof(char) * my_strlen(src) + my_strlen(dest) + 1)))
    return (NULL);
  while (src && src[i] != '\0')
    {
      new[i] = src[i];
      i++;
    }
  while (dest && dest[j] != '\0')
    new[i++] = dest[j++];
  new[i] = '\0';
  return (new);
}
