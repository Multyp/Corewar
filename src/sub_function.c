/*
** sub_function.c for sub_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:48:57 2016 Marwane
** Last update Sat Mar 26 22:04:35 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	sub_function(t_vm *vm, t_champ *champ)
{
  (void)vm;
  (void)champ;
  int	octet[4];
  int	i;

  i = 0;
  while (i != 4)
    {
      octet[i] = get_octet_code(0, i, vm->arena[champ->pc]);
      i++;
    }
  champ->pc =
    (champ->pc + get_size_octet_code(vm->arena[champ->pc] + 1)) % MEM_SIZE;
  champ->cycles_to_wait += 10;
  if (check_addoctet(octet) == 1)
    return (1);
  return (0);
}
