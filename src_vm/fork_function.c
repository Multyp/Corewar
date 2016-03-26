/*
** fork_function.c for fork_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:50:44 2016 Marwane
** Last update Sat Mar 26 15:20:28 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	fork_function(t_vm *vm, t_champ *champ)
{
  (void)champ;
  (void)vm;
  champ->pc =
    (champ->pc + 4) % MEM_SIZE;
  champ->cycles_to_wait += 800;
  return (0);
}
