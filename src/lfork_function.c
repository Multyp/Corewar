/*
** lfork_function.c for lfork_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:51:53 2016 Marwane
** Last update Sat Mar 26 15:21:38 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	lfork_function(t_vm *vm, t_champ *champ)
{
  (void)champ;
  (void)vm;
  champ->pc = (champ->pc + 4) % MEM_SIZE;
  champ->cycles_to_wait += 1000;
  return (0);
}
