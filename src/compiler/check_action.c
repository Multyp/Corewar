/*
** check_action.c for check_action in /CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar  6 18:29:49 2016 Arthur ARNAUD
** Last update Sun Mar  6 19:01:23 2016 Arthur ARNAUD
*/

#include "asm.h"

int	check_action(char *str, int line)
{
  char	**tab;
  int	i;

  if (!(tab = str_to_word_tab
      ("live ld st add sub and or xor zjmp ldi sti fork lld lldi lfork aff"
       , ' ')))
    return (1);

}
