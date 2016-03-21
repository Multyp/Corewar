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
  while (vm.progs != NULL)
    {
      printf("prog_number = %d\n", vm.progs->prog_number);
      printf("address = %d\n", vm.progs->address);
      printf("prog_name = %s\n", vm.progs->prog_name);
      vm.progs = vm.progs->next;
    }
  return (0);
}
