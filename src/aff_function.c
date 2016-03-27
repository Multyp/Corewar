/*
** aff_function.c for aff_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:52:08 2016 Marwane
** Last update Sun Mar 27 08:05:28 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	check_affoctet(int octet[])
{
  if (octet[0] != T_REG ||
      octet[1] != 0 ||
      octet[2] != 0 ||
      octet[3] != 0)
    return (1);
  return (0);
}

int	aff_function(t_vm *vm, t_champ *champ)
{
  int	octet[4];
  int	i;

  i = 0;
  while (i != 4)
    {
      octet[i] = get_octet_code(0, i, vm->arena[champ->pc]);
      i++;
    }
  champ->cycles_to_wait += 2;
  champ->pc = (champ->pc + 1) % MEM_SIZE;
  i = get_myint(vm, champ->pc, get_size(octet[0]));
  if (i > 0 && check_affoctet(octet) == 0)
    my_printf("%c\n", champ->registres[(i - 1) % 16] % 256);
  return (1);
}
