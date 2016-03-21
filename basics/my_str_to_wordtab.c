/*
** str_to_word_tab.c for str_to_wordtab in /home/da-fon_s/rendu/minishell1
** 
** Made by samuel da-fonseca
** Login   <da-fon_s@epitech.net>
** 
** Started on  Tue Jan 12 20:59:35 2016 samuel da-fonseca
** Last update Fri Jan 29 09:59:29 2016 samuel da-fonseca
*/

#include "libmy.h"

int	count_spaces(char *string, char separator)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  if (!string)
    return (-1);
  while (string[i] == separator && string[i])
    i++;
  while (string[i])
    {
      while (string[i] != separator && string[i])
	i++;
      c++;
      while (string[i] == separator && string[i])
	i++;
    }
  return (c);
}

int	word_size(char *string, int c, char separator)
{
  int	i;

  i = 0;
  if (!string)
    return (-1);
  while (string[i] == separator && string[i])
    i++;
  while (c != 1)
    {
      while (string[i] != separator && string[i])
	i++;
      while (string[i] == separator && string[i])
	i++;
      c--;
    }
  c = 0;
  while (string[i] != separator && string[i++] != '\0')
    c++;
  return (c + 1);
}

char	**my_str_to_wordtab(char *string, char separator)
{
  char	**tab;
  int	i;
  int	j;
  int	x;

  x = 0;
  i = 0;
  if (!string || (tab =
		  malloc(sizeof(char *) * (count_spaces(string, separator) + 1))) == NULL)
    return (NULL);
  while (i != (count_spaces(string, separator)))
    {
      j = 0;
      if ((tab[i] =
	   malloc(sizeof(char) * (word_size(string, (i + 1), separator)))) == NULL)
	return (0);
      while (string[x] != separator && string[x])
	tab[i][j++] = string[x++];
      tab[i][j] = '\0';
      while (string[x] == separator && string[x])
	x++;
      i++;
    }
  tab[i] = NULL;
  return (tab);
}
