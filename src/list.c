#include "vm_corewar.h"

t_vm		*init_vm(t_vm *vm)
{
  vm->dump = -1;
  vm->file_opt = true;
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

t_prog		*add_elem(t_prog *prog, char *name)
{
  while (prog != NULL && prog->next != NULL)
    prog = prog->next;
  if (prog == NULL)
    return (create_prog(name));
  prog->next = create_prog(name);
  return (prog);
}
