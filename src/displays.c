/*
** displays.c for displays.c in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sun Mar 27 20:41:11 2016 Marwane
** Last update Sun Mar 27 20:48:26 2016 Marwane
*/

#include "vm_corewar.h"

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
