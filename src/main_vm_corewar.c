#include "vm_corewar.h"

int	main(int ac, char **av, char **env)
{
  (void)ac;
  (void)av;
  (void)env;
  
  check_options(av, NULL, ac);
  return (0);
}
