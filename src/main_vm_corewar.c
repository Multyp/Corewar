/*
** main_vm_corewar.c for main in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Tue Mar 22 15:42:32 2016 Da Fonseca Samuel
** Last update Sat Mar 26 08:30:22 2016 Da Fonseca Samuel
*/

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
  int		c;

  tmp = vm->progs;
  my_printf("\ndump = %d\n", vm->dump);
  my_printf("[%d Prog(s):]\n", vm->progs_nb);
  c = 0;
  while (vm->progs != NULL)
    {
      my_printf("\n[Prog n°%d :]\n", c++);
      my_printf("-->prog_number = %d\n", vm->progs->prog_number);
      my_printf("-->address = %d\n", vm->progs->address);
      my_printf("-->prog_name = %s\n", vm->progs->prog_name);
      my_printf("-->original = %d\n", vm->progs->original);
      vm->progs = vm->progs->next;
    }
  vm->progs = tmp;
}

void		my_affchamps(t_vm *vm)
{
  t_champ	*tmp;
  int		i;

  tmp = vm->champs;
  i = 0;
  while (tmp != NULL)
    {
      my_printf("\n[Champion n°%d :]\n", i++);
      my_printf("------>magic : %d\n", tmp->magic);
      my_printf("------>name : %s\n", tmp->name);
      my_printf("------>size : %d\n", tmp->size);
      my_printf("------>comment : %s\n", tmp->comment);
      my_printf("------>pc : %d\n", tmp->pc);
      tmp = tmp->next;
    }
}

int	init_structs(t_vm *vm, int ac, char **av)
{
  check_options(av, vm, ac);
  add_champions(vm);
  /* my_afflist(vm); */
  check_champs_error(vm);
  /* my_affchamps(vm); */
  init_defaultvalues(vm);
  if (default_addr(vm) == 1 ||
      check_champs_sizes(vm) == 1)
    return (1);
  file_arena(vm);
  file_arena_check(vm);
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
  while (vm->dump > 0 && vm->progs_nb > 1)
    {
      game_check_steps(vm);
      printf("dump = %d\n", vm->dump);
      /* champions_actions(vm); */
      vm->dump--;
    }
}

int	main(int ac, char **av)
{
  t_vm	vm;

  init_vm(&vm);
  if (init_variables(&vm, ac, av) == 1)
    return (1);
  launch_game(&vm);
  return (0);
}
