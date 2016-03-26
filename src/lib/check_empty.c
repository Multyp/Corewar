/*
** check_empty.c for empty in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 17 12:40:01 2016 Clement Peau
** Last update Sat Mar 26 14:08:44 2016 Poc
*/

#include "asm.h"

char		*get_line_not_empty(int fd, int *line)
{
  char		*str;

  if ((str = get_next_line(fd)) == NULL ||
      (str = epur_str(str)) == NULL)
    return (NULL);
  (*line)++;
  while (str != NULL && check_empty(str) == 0)
    {
      if ((str = get_next_line(fd)) == NULL ||
 	  (str = epur_str(str)) == NULL)
	return (NULL);
      (*line)++;
    }
  return (str);
}

int		check_empty(char *string)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (string[i])
    {
      if (count == 0 && string[i] == COMMENT_CHAR)
	return (0);
      if (string[i] != ' ' && string[i] != '\t')
	count++;
      i++;
    }
  if (count == 0)
    return (0);
  else
    return (1);
}
