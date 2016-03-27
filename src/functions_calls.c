/*
** check_functions.c for check_functions in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 02:44:26 2016 Marwane
** Last update Sun Mar 27 14:44:39 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

void	functions_vm(t_vm *vm, t_champ *champ, int i)
{
  int	(*ptr[16])(t_vm *, t_champ *);
  static int p = 0;

  champ->pc = (champ->pc + 1) % MEM_SIZE;
  ptr[0] = &live_function;
  ptr[1] = &ld_function;
  ptr[2] = &st_function;
  ptr[3] = &add_function;
  ptr[4] = &sub_function;
  ptr[5] = &and_function;
  ptr[6] = &or_function;
  ptr[7] = &xor_function;
  ptr[8] = &zjmp_function;
  ptr[9] = &ldi_function;
  ptr[10] = &sti_function;
  ptr[11] = &fork_function;
  ptr[12] = &lld_function;
  ptr[13] = &lldi_function;
  ptr[14] = &lfork_function;
  ptr[15] = &aff_function;

  if (ptr[i](vm, champ) == 0)
    champ->carry = (champ->carry + 1) % 2;
  if (p % 2 == 0)
    {
      printf("fct n° %d\n", i);
      printf("name = %s\n", champ->name);
      printf("pc = %d\n", champ->pc);
      printf("######################\n");
    }
  p++;
}

void		main_loop(t_vm *vm)
{
  t_champ	*tmp_champ;

  tmp_champ = vm->champs;
  while (tmp_champ != NULL)
    {
      if (vm->arena[tmp_champ->pc] < 1 || vm->arena[tmp_champ->pc] > 15)
	tmp_champ->pc = (tmp_champ->pc + 1) % MEM_SIZE;
      else if (tmp_champ->cycles_to_wait == 0)
	functions_vm(vm, tmp_champ, vm->arena[tmp_champ->pc] - 1);
      else
	tmp_champ->cycles_to_wait--;
      tmp_champ = tmp_champ->next;
    }

}
