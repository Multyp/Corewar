#include "vm_corewar.h"

int		check_prog_blocs(char *name, int size, int magic)
{
  if (my_strlen(name) == 0 ||
      size < 1 ||
      magic < 1)
    return (-1);
  return (0);
}

void		check_champs_error(t_vm *vm)
{
  t_champ	*tmp;
  int		i;

  i = 0;
  tmp = vm->champs;
  while (tmp)
    {
      if (check_prog_blocs(tmp->name, tmp->size, tmp->magic) == -1)
	{
	  printf("error found\n");
	  del_prog(vm, i);
	  /* del_champ(vm, i); */
	}
      tmp = tmp->next;
      i++;
    }
}
