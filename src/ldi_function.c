/*
** ldi_function.c for ldi_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:50:11 2016 Marwane
** Last update Sun Mar 27 19:32:51 2016 Da Fonseca Samuel
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

int	ldi_function(t_vm *vm, t_champ *champ)
{
  int	octet[4];
  int	pc;
  int	first_param;
  int	sec;
  int	t;
  int	sum;

  octet[0] = get_octet_code(0, 0, vm->arena[champ->pc]);
  octet[1] = get_octet_code(0, 1, vm->arena[champ->pc]);
  octet[2] = get_octet_code(0, 2, vm->arena[champ->pc]);
  octet[3] = get_octet_code(0, 3, vm->arena[champ->pc]);
  pc = champ->pc;
  champ->cycles_to_wait += 25;
  if (check_ldioctet(octet) == 1)
    return (0);
  champ->pc = (champ->pc + 1) % MEM_SIZE;
  sum = init_stiopeparams(vm, champ, octet[0], &first_param);
  champ->pc = (champ->pc + sum) % MEM_SIZE;
  sum = init_stiopeparams(vm, champ, octet[1], &sec);
  champ->pc = (champ->pc + sum) % MEM_SIZE;
  sum = init_stiopeparams(vm, champ, octet[2], &t);
  champ->pc = (champ->pc + sum) % MEM_SIZE;
  sum = get_myint(vm, (pc + (first_param % IDX_MOD)) % MEM_SIZE, 2) + sec;
  champ->registres[(t - 1) % 16] = get_myint(vm, (pc + (sum % 512)) % 6144, 4);
  return (0);
}
