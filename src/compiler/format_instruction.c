/*
** format_string.c for string in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Fri Mar 18 17:22:19 2016 Poc
** Last update Tue Mar 22 05:03:03 2016 Arthur ARNAUD
*/

#include "asm.h"

char	**cut_instruction(char *str)
{
  char	**instruction;

  if (!(instruction = str_to_word_tab(str, 32)))
    return (NULL);
  showtab(instruction);
  return (instruction);
}

char	*format_instruction(char *str)
{
  char	*new_str;
  int	i;
  int	k;

  i = 0;
  k = 0;
  if ((new_str = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[i] != 0 && str[i] != 32 && str[i] != '#')
    new_str[k++] = str[i++];
  new_str[k++] = 32;
  i++;
  while(str[i] && str[i] != '#')
    {
      while (str[i] != 0 && str[i] == 32)
	i++;
      new_str[k++] = str[i++];
    }
  new_str[(new_str[k - 1] == '#' ? k - 1 : k)] = 0;
  printf("Basic chain |%s|\n", str);
  printf("Formated_string = |%s|\n", new_str);
  free(str);
  return (new_str);
}
