/*
** check_empty.c for empty in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 17 12:40:01 2016 Clement Peau
** Last update Thu Mar 17 15:47:24 2016 Clement Peau
*/

#include "asm.h"

char		*get_line_not_empty(int fd)
{
  char		*str;

  if ((str = get_next_line(fd)) == NULL ||
      (str = epur_str(str)) == NULL)
    return (NULL);
  while (str != NULL && check_empty(str) == 0)
    {
      if ((str = get_next_line(fd)) == NULL ||
 	  (str = epur_str(str)) == NULL)
	return (NULL);
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
      if (string[i] != ' ' && string[i] != '\t')
	count++;
      i++;
    }
  if (count == 0)
    return (0);
  else
    return (1);
}
