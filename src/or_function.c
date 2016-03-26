/*
** or_function.c for or_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:49:28 2016 Marwane
** Last update Sat Mar 26 15:17:50 2016 Da Fonseca Samuel
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
  int	octet[4];
  int	i;

  i = 0;
  while (i++ != 4)
    octet[i] = get_octet_code(0, i, vm->arena[champ->pc]);
  champ->pc =
    (champ->pc + 1 + get_size_octet_code(vm->arena[champ->pc])) % MEM_SIZE;
  champ->cycles_to_wait += 6;
  if (check_oroctet(octet) == 1)
    return (1);
  return (0);
}
