/*
** my_strdup.c for my_strdup in /home/khsime_m/PSU_2015_tetris/src
**
** Made by marwane khsime
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 19 23:02:52 2016 marwane khsime
** Last update Sat Mar 19 23:02:53 2016 marwane khsime
*/

#include "libmy.h"

char	*my_strdup(char *old_string)
{
  char	*new_string;
  int	i;
  int	size;

  size = my_strlen(old_string) + 1;
  if ((new_string = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  i = 0;
  while (old_string && old_string[i])
    {
      new_string[i] = old_string[i];
      i++;
    }
  new_string[i] = '\0';
  return (new_string);
}
