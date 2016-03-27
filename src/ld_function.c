/*
** ld_function.c for ld_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:48:07 2016 Marwane
** Last update Sun Mar 27 03:24:51 2016 Da Fonseca Samuel
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

  i = 0;
  while (i != 4)
    {
      octet[i] = get_octet_code(0, i, vm->arena[champ->pc]);
      i++;
    }
  champ->pc = (champ->pc + 1) % MEM_SIZE + 4;
  printf("pc = %d\n", champ->pc);
  get_myint(vm, champ, 4);
  champ->pc =
    (champ->pc + get_size_octet_code(vm->arena[champ->pc])) % MEM_SIZE;
  champ->cycles_to_wait += 5;
  if (check_ldoctet(octet) == 1)
    return (1);
  return (0);
}
