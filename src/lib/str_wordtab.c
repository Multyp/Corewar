/*
** str_wordtab.c for lol\ in /home/peau_c/rendu/PSU/minishell/
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Tue Jan 12 16:48:54 2016
** Last update Mon Mar 21 19:12:20 2016 Poc
*/

#include "asm.h"

int     count_words(char *str, char target)
 {
   int   i;
   int   count;

   count = 0;
   i = 0;
   while (str[i] != 0)
     {
       if (str[i] == target && str[i + 1] != 0 && i != 0)
	 count++;
       i++;
     }
   return (count + 1);
 }

int	word_size(char *str, int pos, char target)
{
  int	i;

  i = 0;
  while (str[pos] != target && str[pos] != 0)
    {
      pos++;
      i++;
    }
  return (i);
}

void	strcpy_gitan(int pos, char *str, char *av, int target)
{
  int	i;

  i = 0;
  while (str[pos] != 0 && str[pos] != target)
    {
      av[i] = str[pos];
      i++;
      pos++;
    }
  av[i] = 0;
}

char    **my_wordtab(char *str, char target)
{
  char  **av;
  int   i;
  int	j;

  i = -1;
  if ((av = malloc((count_words(str, target) + 1) * sizeof(char *))) == NULL)
    exit(-1);
  av[0] = NULL;
  av[count_words(str, target)] = NULL;
  j = 0;
  while (str[++i] != 0)
    {
      if (str[i] == target || i == 0)
	{
	  if (i == 0)
	    i--;
	  if ((av[j] = malloc (sizeof(char) *
			       (word_size(str, i + 1, target) + 1))) == NULL)
	    exit(-1);
	  strcpy_gitan(i + 1, str, av[j++], target);
	  if (i == -1)
	    i++;
	}
    }
  return (av);
}
