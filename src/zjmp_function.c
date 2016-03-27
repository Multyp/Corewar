/*
** zjmp_function.c for zjmp_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:50:00 2016 Marwane
** Last update Sun Mar 27 07:59:48 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	zjmp_function(t_vm *vm, t_champ *champ)
{
  int	nb;
  int	stock;

  nb = get_myint(vm, champ->pc, 2);
  stock = (champ->pc == 0) ? MEM_SIZE : (champ->pc - 1);
  champ->cycles_to_wait += 20;
  if (champ->carry == 1)
    champ->pc = (stock + (nb % IDX_MOD)) % MEM_SIZE;
  return (0);
}
