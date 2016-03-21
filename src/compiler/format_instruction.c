/*
** format_string.c for string in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Fri Mar 18 17:22:19 2016 Poc
** Last update Mon Mar 21 21:13:04 2016 Poc
*/

#include "asm.h"

char	**cut_instruction(char *str)
{
  char	**instruction;

  instruction = my_wordtab(str, 32);
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
