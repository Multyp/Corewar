/*
** main_vm_corewar.c for main in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Tue Mar 22 15:42:32 2016 Da Fonseca Samuel
** Last update Tue Mar 22 15:43:18 2016 Da Fonseca Samuel
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
  printf("\ndump = %d\n", vm->dump);
  printf("[%d Prog(s):]\n", vm->progs_nb);
  c = 0;
  while (vm->progs != NULL)
    {
      printf("\n[Prog n°%d :]\n", c++);
      printf("-->prog_number = %d\n", vm->progs->prog_number);
      printf("-->address = %d\n", vm->progs->address);
      printf("-->prog_name = %s\n", vm->progs->prog_name);
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
  t_vm	vm;

  if (*env == NULL)
    return (1);
  init_vm(&vm);
  check_options(av, &vm, ac);
  init_defaultvalues(&vm);
  my_afflist(&vm);
  /* add_champions(&vm); */
  /* check_champs_error(&vm); */
  /* printf("\n\nCHECK ERROR\n"); */
  /* my_affchamps(&vm); */
  return (0);
}
