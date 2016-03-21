#include "vm_corewar.h"

void    init_bool_opts(t_vm *vm)
{
  vm->prog_opts[0] = false;
  vm->prog_opts[1] = false;
  vm->prog_opts[2] = false;
}

int	check_bool_opts(t_vm *vm)
{
  int	i;

  i = 0;
  while (i != 3 && vm->prog_opts[i] == true)
    i++;
  return (i / 2);
}
