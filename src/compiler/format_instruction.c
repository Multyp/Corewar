/*
** format_string.c for string in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Fri Mar 18 17:22:19 2016 Poc
** Last update Sat Mar 26 02:28:26 2016 Arthur ARNAUD
*/

#include "asm.h"

char	**cut_instruction(char *str)
{
  char	**instruction;

  if (!(instruction = str_to_word_tab(str, 32)))
    return (write(2, "Can't perform malloc\n", 21), NULL);
  showtab(instruction);
  return (instruction);
}

char	*exiting_format(char *str, char *new_str, int k)
{
  free(str);
  new_str[k] = 0;
  return (new_str);
}

char	*format_instruction(char *str)
{
  char	*new_str;
  int	i;
  int	k;

  i = 0;
  k = 0;
  if ((new_str = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (write(2, "Can't perform malloc\n", 21), NULL);
  while (str[i] != 0 && str[i] != 32 && str[i] != COMMENT_CHAR)
    new_str[k++] = str[i++];
  new_str[k++] = 32;
  i++;
  while(str[i] != 0 && str[i] != COMMENT_CHAR)
    {
      while (str[i] != 0 && str[i] == 32)
	i++;
      if (str[i] == COMMENT_CHAR)
	return (exiting_format(str, new_str, k));
      new_str[k++] = str[i++];
    }
  return (exiting_format(str, new_str, k));
}
