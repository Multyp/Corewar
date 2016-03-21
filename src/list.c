#include "vm_corewar.h"

t_vm		*init_vm(t_vm *vm)
{
  vm->dump = -1;
  init_bool(vm);
  vm->progs_nb = 0;
  vm->progs = NULL;
  vm->champs = NULL;
  return (vm);
}

t_prog		*create_prog(char *name)
{
  t_prog	*new_elem;

  if ((new_elem = malloc(sizeof(t_prog))) == NULL)
    return (my_perror(MALLOC_FAILED));
  new_elem->prog_number = -1;
  new_elem->address = 0;
  new_elem->prog_name = my_strdup(name);
  new_elem->next = NULL;
  return (new_elem);
}

t_vm		*add_prog(t_vm *vm, char *name)
{
  while (vm->progs != NULL && vm->progs->next != NULL)
    vm->progs = vm->progs->next;
  if (vm->progs == NULL)
    vm->progs = create_prog(name);
  else
    vm->progs->next = create_prog(name);
  vm->progs_nb++;
  return (vm);
}
