/*
** live_function.c for live_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 06:15:33 2016 Marwane
** Last update Sat Mar 26 08:06:04 2016 Marwane
*/

#include "vm_corewar.h"

void	live_function(t_vm *vm, t_champ *champ)
{
  if (++vm->live_calls == NBR_LIVE)
    {
      vm->live_calls = 0;
      vm->cycle_die -= (vm->cycle_die - CYCLE_DELTA > 0 ? CYCLE_DELTA : 0);
    }
  champ->alive = 1;
  champ->cycles_to_wait += 10;
}
