#include "vm_corewar.h"

t_vm		*init_vm(t_vm *vm)
{
  vm->dump = -1;
  vm->file_opts[0] = false;
  vm->file_opts[1] = false;
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
  new_elem->prog_number = 0;
  new_elem->address = 0;
  new_elem->prog_name = my_strdup(name);
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

  if (pos == 0 && vm->progs != NULL)
    {
      tmp = vm->progs->next;
      free (vm->progs->prog_name);
      free (vm->progs);
      vm->progs = tmp;
      vm->progs_nb--;
      return ;
    }
  while (pos > 1)
    {
      if (vm->progs == NULL)
	return ;
      tmp = vm->progs;
      vm->progs = vm->progs->next;
      pos--;
    }
  free (vm->progs->next->prog_name);
  free (vm->progs->next);
  tmp->next = vm->progs->next->next;
  vm->progs_nb--;
}
