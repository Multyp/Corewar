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
