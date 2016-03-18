/*
** main.c for ;ain in /home/peau_c/rendu/PSU/minishell/PSU_2015_my_exec
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Tue Jan  5 14:33:32 2016
** Last update Thu Mar 17 12:30:56 2016 Clement Peau
*/

#include "asm.h"

char	*epur_str(char *str)
{
  int	i;
  char	*tmp;
  int   j;

  j = 0;
  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    exit(-1);
  i = 0;
  while ((str[i] != 0 && str[i] == ' ') || (str[i] == '\t' && str[i] != 0))
    i++;
  while (str[i] != 0)
    {
      while ((str[i] == 32 && str[i + 1] == 32) ||
	     (str[i] == '\t' && str[i + 1] == '\t'))
	i++;
      tmp[j] = str[i];
      i++;
      j++;
    }
  tmp[j] = 0;
  free(str);
  if (my_strlen(tmp) != 0 && tmp[my_strlen(tmp) - 1] == ' ')
    tmp[my_strlen(tmp) - 1] = 0;
  return (tmp);
}
