/*
** st_function.c for st_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:48:27 2016 Marwane
** Last update Sun Mar 27 13:30:35 2016 Marwane
*/

#include "vm_corewar.h"

int	check_stoctet(int octet[])
{
  if (octet[2] != 0 || octet[3] != 0 ||
      octet[1] != T_REG ||
      (octet[0] != T_IND && octet[0] != T_REG))
    return (1);
  return (0);
}

void	st_function_t_ind(t_vm *vm, t_champ *champ,
			  int _pc, int first_param)
{
  int	second_param;

  second_param = get_myint(vm, (champ->pc = (champ->pc + 1) % MEM_SIZE), 2);
  vm->arena[(_pc + second_param % IDX_MOD) % MEM_SIZE] = first_param;
  champ->pc = (champ->pc + 2) % MEM_SIZE;
}

void	st_function_t_reg(t_vm *vm, t_champ *champ, int first_param)
{
  int	second_param;

  second_param = get_myint(vm, (champ->pc = ((champ->pc  + 1) % MEM_SIZE)), 1);
  champ->registres[second_param % 16] = first_param;
  (void)first_param;
}

int	st_function(t_vm *vm, t_champ *champ)
{
  int	octet[4];
  int	i;
  int	_pc;
  int	first_param;

  i = 0;
  while (i < 4)
    {
      octet[i] = get_octet_code(0, i, vm->arena[champ->pc]);
      i++;
    }
  _pc = champ->pc;
  if (check_stoctet(octet) == 0)
    {
      first_param = get_myint(vm,
			      (champ->pc = ((champ->pc + 1) % MEM_SIZE)), 1);
      if (octet[1] == T_IND)
	st_function_t_ind(vm, champ, _pc, first_param);
      else
	st_function_t_reg(vm, champ, first_param);
    }
  champ->cycles_to_wait += 5;
  return (1);
}
