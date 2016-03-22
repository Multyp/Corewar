#include "vm_corewar.h"

t_prog		*create_prog(char *name)
{
  t_prog	*new_elem;

  if ((new_elem = malloc(sizeof(t_prog))) == NULL)
    return (my_perror(MALLOC_FAILED));
  new_elem->prog_number = 0;
  new_elem->address = 0;
  new_elem->prog_name = (name == NULL) ? NULL : my_strdup(name);
  new_elem->next = NULL;
  return (new_elem);
}

t_vm		*add_prog(t_vm *vm, char *name)
{
  t_prog	*tmp;

  tmp = vm->progs;
  while (vm->progs != NULL && vm->progs->next != NULL)
    vm->progs = vm->progs->next;
  if (vm->progs == NULL)
    vm->progs = create_prog(name);
  else
    {
      vm->progs->next = create_prog(name);
      vm->progs = tmp;
    }
  vm->progs_nb++;
  return (vm);
}

void		del_prog(t_vm *vm, int pos)
{
  t_prog	*tmp;
  t_prog	*tmp2;
  
  if ((tmp = vm->progs) == NULL)
    return ;
  if (pos == 0)
    {
      tmp = tmp->next;
      my_freeprog(vm->progs);
      vm->progs = tmp;
      vm->progs_nb--;
      return ;
    }
  while (pos-- > 1)
    {
      if (vm->progs == NULL)
	return ;
      vm->progs = vm->progs->next;
    }
  if ((tmp2 = vm->progs->next) != NULL)
    vm->progs->next = vm->progs->next->next;
  my_freeprog(tmp2);
  vm->progs = tmp;
  vm->progs_nb--;
}

int		check_list_for_prognb(t_vm *vm, int nb)
{
  t_prog	*tmp;
  
  tmp = vm->progs;
  while (vm->progs != NULL)
    {
      if (vm->progs->prog_number == nb)
	return (my_error("Prog_number already used"));
      vm->progs = vm->progs->next;
    }
  vm->progs = tmp;
  return (0);
}

int		check_list_for_address(t_vm *vm, unsigned int nb)
{
  t_prog	*tmp;
  
  tmp = vm->progs;
  while (vm->progs != NULL)
    {
      if (vm->progs->address == nb)
	return (my_error("Address already used"));
      vm->progs = vm->progs->next;
    }
  vm->progs = tmp;
  return (0);
}
