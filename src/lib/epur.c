/*
** main.c for ;ain in /home/peau_c/rendu/PSU/minishell/PSU_2015_my_exec
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Tue Jan  5 14:33:32 2016
** Last update Sat Mar 26 23:44:28 2016 Poc
*/

#include "asm.h"

char	*epur_commas(char *str)
{
  int	i;
  char	*new_str;
  int	j;

  j = 0;
  i = 0;
  if ((new_str = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[i])
    {
      if (str[i] == ',' && str[i + 1] == ',')
	i++;
      else
	new_str[j++] = str[i++];
    }
  new_str[j] = 0;
  free(str);
  return (new_str);
}

char	*epur_str(char *str)
{
  int	i;
  int	k;
  char	*new_str;

  k = 0;
  i = 0;
  if (str == NULL)
    return (NULL);
  if ((new_str = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  while ((str[i] == 32 || str[i] == '\t') && str[i++] != 0);
  while (str[i])
    {
      if (str[i] == '\t')
	str[i] = ' ';
      while (str[i] == 32 && str[i + 1] != 0 && str[i + 1] == 32)
	i++;
      new_str[k++] = str[i++];
    }
  new_str[k] = 0;
  free(str);
  if ((new_str = epur_commas(new_str)) == NULL)
    return (NULL);
  return (new_str);
}
