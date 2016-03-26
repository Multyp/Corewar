/*
** str_to_word_tab.c for str_to_word_tab in /CPE_2015_corewar/src/lib
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Mar 22 05:00:34 2016 Arthur ARNAUD
** Last update Tue Mar 22 05:03:43 2016 Arthur ARNAUD
*/

#include "asm.h"

int	get_nb_word(char *s, char sep)
{
  int	nb_arg;
  int	i;

  nb_arg = 0;
  i = -1;
  while (s[++i] != '\0')
    if (s[i] == sep)
      nb_arg++;
  return (nb_arg);
}

char	**str_to_word_tab(char *s, char sep)
{
  char	**arg;
  int	index;
  int	size;
  int	i;
  int	j;

  size = get_nb_word(s, sep) + 1;
  if ((arg = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  index = -1;
  while (++index < size)
    {
      j = 0;
      i = -1;
      while (s[++i] != '\0' && s[i] != sep && (j = j + 1));
      if ((arg[index] = malloc(sizeof(char) * (j + 1))) == NULL)
	return (NULL);
      i = -1;
      while (++i < j && (arg[index][i] = s[i]));
      s += (i + 1);
      arg[index][i] = '\0';
    }
  arg[index] = NULL;
  return (arg);
}
