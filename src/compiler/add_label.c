/*
** add_label.c for add_label in /cpe/CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Mar 17 13:50:59 2016 Arthur ARNAUD
** Last update Sat Mar 26 02:27:32 2016 Arthur ARNAUD
*/

#include "asm.h"

char	*add_to_label(char *str, int pos, t_label *label, int i)
{
  int	k;
  char	*res;

  k = -1;
  if (!(label->name = malloc(sizeof(char) * (i + 1))) ||
      !(res = my_strdup(str + i)))
    return (write(2, "Can't perform malloc\n", 21), NULL);
  while (++k < i - 1)
    label->name[k] = str[k];
  label->name[k] = 0;
  label->pos = pos;
  free(str);
  return (res);
}
