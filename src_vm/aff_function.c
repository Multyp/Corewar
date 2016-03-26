/*
** aff_function.c for aff_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:52:08 2016 Marwane
** Last update Sat Mar 26 22:06:58 2016 Da Fonseca Samuel
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
  char	c;

  i = 0;
  while (i != 4)
    {
      octet[i] = get_octet_code(0, i, vm->arena[champ->pc]);
      i++;
    }
  c = vm->arena[(champ->pc + 1) % MEM_SIZE];
  champ->pc =
    (champ->pc + 1 + get_size_octet_code(vm->arena[champ->pc])) % MEM_SIZE;
  champ->cycles_to_wait += 2;
  if (check_affoctet(octet) == 1)
    return (1);
  my_printf("%c\n", c);
  return (0);
}
