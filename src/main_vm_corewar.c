#include "vm_corewar.h"

char		*get_binary(char *binary)
{
  static char   *stock_binary = NULL;

  if (stock_binary == NULL)
    stock_binary = binary;
  return (stock_binary);
}

void		my_afflist(t_vm *vm)
{
  t_prog	*tmp;

  tmp = vm->progs;
  while (vm->progs != NULL)
    {
      printf("prog_number = %d\n", vm->progs->prog_number);
      printf("address = %d\n", vm->progs->address);
      printf("prog_name = %s\n", vm->progs->prog_name);
      vm->progs = vm->progs->next;
    }
  vm->progs = tmp;
}

void		my_affchamps(t_vm *vm)
{
  t_champ	*tmp;

  tmp = vm->champs;
  while (tmp != NULL)
    {
      printf("\n[Champion :]\n");
      printf("------>magic : %d\n", tmp->magic);
      printf("------>name : %s\n", tmp->name);
      printf("------>size : %d\n", tmp->size);
      printf("------>comment : %s\n", tmp->comment);
      tmp = tmp->next;
    }
}

int	main(int ac, char **av, char **env)
{
  (void)ac;
  (void)av;
  (void)env;
  t_vm	vm;

  init_vm(&vm);
  check_options(av, &vm, ac);
  add_champions(&vm);
  /* my_afflist(&vm); */
  my_affchamps(&vm);
  return (0);
}
