/*
** main_vm_corewar.c for main in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Tue Mar 22 15:42:32 2016 Da Fonseca Samuel
** Last update Sat Mar 26 04:31:38 2016 Marwane
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
      tmp = tmp->next;
    }
}

void	launch_engine(t_vm *vm)
{
  while (vm->dump > 0)
    {
      vm->dump--;
    }
}

int	init_variables(t_vm *vm, int ac, char **av)
{
  check_options(av, vm, ac);
  add_champions(vm);
  check_champs_error(vm);
  init_defaultvalues(vm);
  init_progaddress(vm);
  vm->cycle_die = CYCLE_TO_DIE;
  vm->nbr_live = NBR_LIVE;
  my_afflist(vm);
  my_affchamps(vm);
  if (check_champs_sizes(vm) == 1)
    return (1);
  file_arena(vm);
  file_arena_check(vm);
  return (0);
}

int	main(int ac, char **av)
{
  t_vm	vm;

  init_vm(&vm);
  if (init_variables(&vm, ac, av) == 1)
    return (1);
  launch_engine(&vm);
  return (0);
}
