/*
** zjmp_function.c for zjmp_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:50:00 2016 Marwane
** Last update Sun Mar 27 19:37:18 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	zjmp_function(t_vm *vm, t_champ *champ)
{
  short	nb;

  nb = get_myint(vm, champ->pc, 2);
  champ->cycles_to_wait += 20;
  if (champ->carry == 1)
    champ->pc = (champ->pc + (nb % IDX_MOD)) % MEM_SIZE;
  else
    champ->pc = (champ->pc + 2) % MEM_SIZE;
  return (1);
}
