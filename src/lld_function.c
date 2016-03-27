/*
** lld_function.c for lld_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:51:04 2016 Marwane
** Last update Sun Mar 27 07:55:54 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	lld_function(t_vm *vm, t_champ *champ)
{
  int   octet[4];
  int   i;
  char  reg_param;
  int   first_param;
  int   stock_pc;

  i = 0;
  stock_pc = (champ->pc != 0) ? (champ->pc - 1) : MEM_SIZE;
  while (i != 4)
    {
      octet[i] = get_octet_code(0, i, vm->arena[champ->pc]);
      i++;
    }
  champ->pc = (champ->pc + 1) % MEM_SIZE;
  i = init_opeparams(vm, champ, octet[0], &first_param);
  champ->pc = (champ->pc + i) % MEM_SIZE;
  reg_param = get_myint(vm, champ->pc, 1);
  champ->pc = (champ->pc + 1) % MEM_SIZE;
  champ->cycles_to_wait += 5;
  if (reg_param > 0 && check_ldoctet(octet) == 0)
    champ->registres[(reg_param - 1) % 16] =
      vm->arena[(stock_pc + first_param) % MEM_SIZE];
  return (0);
}
