/*
** init_ops.c for ops in /home/da-fon_s/rendu/vm_corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Sat Mar 26 15:02:56 2016 Da Fonseca Samuel
** Last update Sat Mar 26 15:11:33 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

char	**init_names()
{
  char	**names;

  if ((names = malloc(sizeof(char *) * 16)) == NULL)
    return (NULL);
  names[0] = my_strdup("live");
  names[1] = my_strdup("ld");
  names[2] = my_strdup("st");
  names[3] = my_strdup("add");
  names[4] = my_strdup("sub");
  names[5] = my_strdup("and");
  names[6] = my_strdup("or");
  names[7] = my_strdup("xor");
  names[8] = my_strdup("zjmp");
  names[9] = my_strdup("ldi");
  names[10] = my_strdup("sti");
  names[11] = my_strdup("fork");
  names[12] = my_strdup("lld");
  names[13] = my_strdup("lldi");
  names[14] = my_strdup("lfork");
  names[15] = my_strdup("aff");
  return (names);
}
