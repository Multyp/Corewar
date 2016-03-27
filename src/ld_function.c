/*
** ld_function.c for ld_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:48:07 2016 Marwane
** Last update Sun Mar 27 14:15:22 2016 Marwane
*/

#include "vm_corewar.h"

int	check_ldoctet(int octet[])
{
  if ((octet[0] != T_DIR && octet[0] != T_IND) ||
      octet[1] != T_REG ||
      octet[2] != 0 ||
      octet[3] != 0)
    return (1);
  return (0);
}

int	ld_function(t_vm *vm, t_champ *champ)
{
  int	octet[4];
  int	i;
  char	reg_param;
  int	first_param;
  int	stock_pc;

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
      get_myint(vm, (stock_pc + (first_param % IDX_MOD)) % MEM_SIZE, 4);
  return (0);
}
