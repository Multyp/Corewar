/*
** main_vm_corewar.c for main in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Tue Mar 22 15:42:32 2016 Da Fonseca Samuel
** Last update Sun Mar 27 23:01:30 2016 Marwane
*/

#include "vm_corewar.h"

char		*get_binary(char *binary)
{
  static char   *stock_binary = NULL;

  if (stock_binary == NULL)
    stock_binary = binary;
  return (stock_binary);
}

int	init_structs(t_vm *vm, int ac, char **av)
{
  check_options(av, vm, ac);
  add_champions(vm);
  check_champs_error(vm);
  init_defaultvalues(vm);
  if (default_addr(vm) == 1 ||
      check_champs_sizes(vm) == 1)
    return (1);
  pc_correction(vm);
  file_arena(vm);
  return (0);
}

int	init_variables(t_vm *vm, int ac, char **av)
{
  vm->cycle_die = CYCLE_TO_DIE;
  vm->live_calls = 0;
  vm->cycle = 0;
  if (init_structs(vm, ac, av) == 1)
    return (1);
  return (0);
}

void	launch_game(t_vm *vm)
{
  int	i;

  i = 0;
  while (vm->dump != 0 && vm->progs_nb > 1)
    {
      main_loop(vm);
      game_check_steps(vm);
      vm->dump--;
      i++;
    }
  if (vm->progs_nb == 1)
    aff_winner(vm);
}

int	main(int ac, char **av)
{
  t_vm	vm;

  init_vm(&vm);
  if (init_variables(&vm, ac, av) == 1)
    return (1);
  if (vm.progs_nb == 1)
    {
      my_printf("Need one more fighter please, because it's more funny .\n");
      return (1);
    }
  launch_game(&vm);
  if (vm.dump == 0)
    put_memory_hexa_format(vm.arena);
  free_champions(&vm);
  return (0);
}
