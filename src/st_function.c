/*
** st_function.c for st_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:48:27 2016 Marwane
** Last update Sat Mar 26 15:14:44 2016 Da Fonseca Samuel
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

int	st_function(t_vm *vm, t_champ *champ)
{
  int	octet[4];
  int	i;

  i = 0;
  while (i++ != 4)
    octet[i] = get_octet_code(0, i, vm->arena[champ->pc]);
  champ->pc =
    (champ->pc + get_size_octet_code(vm->arena[champ->pc]) + 1) % MEM_SIZE;
  champ->cycles_to_wait += 5;
  if (check_stoctet(octet) == 1)
    return (1);
  return (0);
}
