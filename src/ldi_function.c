/*
** ldi_function.c for ldi_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:50:11 2016 Marwane
** Last update Sun Mar 27 13:28:48 2016 Marwane
*/

#include "vm_corewar.h"

int	check_ldioctet(int octet[])
{
  if ((octet[0] != T_REG && octet[0] != T_DIR &&
       octet[0] != T_IND) ||
      (octet[1] != T_DIR && octet[1] != T_REG) ||
      octet[2] != T_REG ||
      octet[3] != 0)
    return (1);
  return (0);
}

int	ldi_function_third_param(t_vm *vm, t_champ *champ)
{
  int	ret;

  ret = get_myint(vm, champ->pc, 1);
  return ((champ->pc += 1), (char)ret);
}

int	ldi_function_second_param(t_vm *vm, t_champ *champ, int octet[])
{
  int	ret;

  if (octet[0] == T_REG)
    {
      ret = get_myint(vm, champ->pc, 1);
      return ((champ->pc = (champ->pc + 1) % MEM_SIZE), (char)ret);
    }
  else
    {
      ret = (short)get_myint(vm, champ->pc, 2);
      return ((champ->pc = (champ->pc + 2) % MEM_SIZE), (short)ret);
    }
  return (0);
}

int	ldi_function_first_param(t_vm *vm, t_champ *champ, int octet[])
{
  int	ret;

  if (octet[0] == T_REG)
    {
      ret = get_myint(vm, champ->pc, 1);
      return ((champ->pc = (champ->pc + 1) % MEM_SIZE), (char)ret);
    }
  else if (octet[0] == T_DIR)
    {
      ret = (short)get_myint(vm, champ->pc, 2);
      return ((champ->pc = (champ->pc + 2) % MEM_SIZE), (short)ret);
    }
  else
    {
      ret = get_myint(vm, champ->pc, 4);
      return ((champ->pc = (champ->pc + 2) % MEM_SIZE), ret);
    }
  return (0);
}

int	ldi_function(t_vm *vm, t_champ *champ)
{
  int	octet[4];
  int	_pc;
  int	first_param;
  int	second_param;
  int	third_param;
  int	sum;

  octet[0] = get_octet_code(0, 0, vm->arena[champ->pc]);
  octet[1] = get_octet_code(0, 1, vm->arena[champ->pc]);
  octet[2] = get_octet_code(0, 2, vm->arena[champ->pc]);
  octet[3] = get_octet_code(0, 3, vm->arena[champ->pc]);
  _pc = champ->pc;
  if (check_ldioctet(octet) == 0)
    {
      champ->pc = (champ->pc + 1) % MEM_SIZE;
      first_param = ldi_function_first_param(vm, champ, octet);
      second_param = ldi_function_second_param(vm, champ, octet);
      third_param = ldi_function_third_param(vm, champ);
      sum = get_myint(vm, (champ->pc + (first_param % IDX_MOD)) % MEM_SIZE, 4) +
	second_param;
      champ->registres[(char)third_param % 16] = (_pc + (sum % IDX_MOD));
    }
  champ->cycles_to_wait += 25;
  return (0);
}
