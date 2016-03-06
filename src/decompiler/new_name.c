/*
** new_name.c for new_name in /CPE_2015_corewar/src/decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Fri Mar  4 02:52:51 2016 Arthur ARNAUD
** Last update Sun Mar  6 15:58:03 2016 Arthur ARNAUD
*/

#include "decompiler.h"

char	*new_name(char *str)
{
  int	i;
  int	j;
  int	pos;
  char	*name;

  i = -1;
  pos = 0;
  while (str[++i] != 0)
    if (str[i] == '/')
      pos = i;
  str = str + pos + 1;
  if ((name = malloc(sizeof(char) * (my_strlen(str) + 3))) == NULL)
    return (NULL);
  i = -1;
  j = 0;
  while (str[++i] != 0 && str[i] != '.')
    name[j++] = str[i];
  name[j++] = '.';
  name[j++] = 's';
  name[j] = 0;
  return (name);
}
