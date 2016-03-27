/*
** or_function.c for or_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:49:28 2016 Marwane
** Last update Sun Mar 27 07:48:03 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	check_oroctet(int octet[])
{
  if ((octet[0] != T_REG && octet[0] != T_IND &&
       octet[0] != T_DIR) ||
      (octet[1] != T_REG && octet[1] != T_IND &&
       octet[1] != T_DIR) ||
      octet[2] != T_REG ||
      octet[3] != 0)
    return (1);
  return (0);
}

int	or_function(t_vm *vm, t_champ *champ)
{
  int   octet[4];
  int   i;
  int	p1;
  int	p2;
  int	p3;

  i = 0;
  while (i != 4)
    {
      octet[i] = get_octet_code(0, i, vm->arena[champ->pc]);
      i++;
    }
  champ->cycles_to_wait += 6;
  champ->pc = (champ->pc + 1) % MEM_SIZE;
  i = init_opeparams(vm, champ, octet[0], &p1);
  champ->pc = (champ->pc + i) % MEM_SIZE;
  i = init_opeparams(vm, champ, octet[1], &p2);
  champ->pc = (champ->pc + i) % MEM_SIZE;
  p3 = get_myint(vm, champ->pc, 1);
  champ->pc = (champ->pc + 1) % MEM_SIZE;
  if (check_andoctet(octet) == 0)
    champ->registres[(p3 - 1) % 16] = p1 | p2;
  return (0);
}
