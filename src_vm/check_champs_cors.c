/*
** check_champs_cors.c for check_champs in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Tue Mar 22 15:55:37 2016 Da Fonseca Samuel
** Last update Sat Mar 26 15:47:40 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int		check_prog_blocs(char *name, int size, int magic)
{
  if (my_strlen(name) == 0 ||
      size < 1 ||
      magic < 1)
    return (-1);
  return (0);
}

void		check_champs_error(t_vm *vm)
{
  t_champ	*tmp;
  int		i;

  i = 0;
  tmp = vm->champs;
  while (i < vm->progs_nb)
    {
      if (check_prog_blocs(tmp->name, tmp->size, tmp->magic) == -1)
      	{
	  printf("name = %s\nsize = %d\nmagic = %d\n", tmp->name, tmp->size, tmp->magic);
      	  del_prog(vm, i);
      	  del_champ(vm, i);
      	}
      i++;
      if (i < vm->progs_nb)
	tmp = tmp->next;
    }
}
