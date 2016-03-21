#include "vm_corewar.h"

int	main(int ac, char **av, char **env)
{
  (void)ac;
  (void)av;
  (void)env;
  t_vm	vm;

  check_options(av, &vm, ac);
  return (0);
}
