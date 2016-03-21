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

int	main(int ac, char **av, char **env)
{
  (void)ac;
  (void)av;
  (void)env;
  t_vm	vm;

  /* init_vm(&vm); */
  vm.champs = add_champ_to_list(vm.champs, av[1]);
  printf("%d\n", vm.champs->magic);
  printf("%s\n", vm.champs->name);
  printf("%d\n", vm.champs->size);
  printf("%s\n", vm.champs->comment);
  /* check_options(av, &vm, ac); */
  /* my_afflist(&vm); */
  /* printf("\n\n"); */
  /* del_prog(&vm, 0); */
  /* my_afflist(&vm); */

  return (0);
}
