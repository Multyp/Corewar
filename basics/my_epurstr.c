/*
** my_epurstr.c for epur_str in /home/da-fon_s/stock/libmy/basics
** 
** Made by samuel da-fonseca
** Login   <da-fon_s@epitech.net>
** 
** Started on  Fri Jan 29 16:24:23 2016 samuel da-fonseca
** Last update Fri Jan 29 16:35:55 2016 samuel da-fonseca
*/

#include "libmy.h"

char	*clear_tab(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] == '\t')
	str[i] = ' ';
      i++;
    }
  return (str);
}

char	*my_epurstr(char *str)
{
  char	*new_str;
  int	i;
  int	j;

  if (!str)
    return (NULL);
  if ((new_str = malloc(sizeof(char) * 1)) == NULL)
    return (str);
  i = 0;
  j = 0;
  str = clear_tab(str);
  while (str[j] == ' ' && str[j])
    j++;
  while (str && str[j])
    {
      new_str[i] = str[j];
      while (str[j] == ' ' && str[j])
	j++;
      new_str = my_realloc(str, (i + 1));
      i++;
    }
  new_str[i] = '\0';
  free(str);
  return (new_str);
}
