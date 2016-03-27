/*
** add_function.c for add_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:48:41 2016 Marwane
** Last update Sun Mar 27 19:43:45 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	check_addoctet(int octet[])
{
  if (octet[3] != 0 ||
      octet[2] != T_REG ||
      octet[1] != T_REG ||
      octet[0] != T_REG)
    return (1);
  return (0);
}

int	add_function(t_vm *vm, t_champ *champ)
{
  int	octet[4];
  int	i;
  char	reg_n1;
  char	reg_n2;
  char	reg_dest;

  i = 0;
  while (i != 4)
    {
      octet[i] = get_octet_code(0, i, vm->arena[champ->pc]);
      i++;
    }
  if (check_addoctet(octet) == 1)
    return (0);
  champ->pc = (champ->pc + 1) % MEM_SIZE;
  champ->cycles_to_wait += 10;
  reg_n1 = get_myint(vm, champ->pc, T_REG);
  champ->pc = (champ->pc + 1) % MEM_SIZE;
  reg_n2 = get_myint(vm, champ->pc, T_REG);
  champ->pc = (champ->pc + 1) % MEM_SIZE;
  reg_dest = get_myint(vm, champ->pc, T_REG);
  champ->pc = (champ->pc + 1) % MEM_SIZE;
  champ->registres[(reg_dest - 1) % 16] =
    champ->registres[(reg_n2 - 1) % 16] + champ->registres[(reg_n1 - 1) % 16];
  return (0);
}
