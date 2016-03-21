#include "vm_corewar.h"

char		*get_binary(char *binary)
{
  static char   *stock_binary = NULL;

  if (stock_binary == NULL)
    stock_binary = binary;
  return (stock_binary);
}

int	main(int ac, char **av, char **env)
{
  (void)ac;
  (void)av;
  (void)env;
  t_vm	vm;

  init_vm(&vm);
  check_options(av, &vm, ac);
  printf("%d\t%u\n", vm.progs->prog_number, vm.progs->address);
  return (0);
}
