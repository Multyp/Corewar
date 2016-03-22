#include "vm_corewar.h"

void	my_freeprog(t_prog *prog)
{
  if (prog->prog_name != NULL)
    free (prog->prog_name);
  free (prog);
}
