/*
** default_opts.c for default_opts in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Tue Mar 22 15:55:49 2016 Da Fonseca Samuel
** Last update Tue Mar 22 15:55:50 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

void	my_afflist(t_vm *);

void		init_defaultvalues(t_vm *vm)
{
  int		nb;
  t_prog	*tmp;

  tmp = vm->progs;
  nb = 1;
  while (vm->progs != NULL)
    {
      while (check_list_for_prognb(vm, nb) == 1)
      	nb++;
      if (vm->progs->prog_number == 0)
	vm->progs->prog_number = nb++;
      vm->progs = vm->progs->next;
    }
  vm->progs = tmp;
}
