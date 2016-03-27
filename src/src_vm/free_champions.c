/*
** free_champions.c for free_champions in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sun Mar 27 20:24:48 2016 Marwane
** Last update Sun Mar 27 20:51:09 2016 Marwane
*/

#include "vm_corewar.h"

void		free_champions(t_vm *vm)
{
  int		i;

  i = 0;
  while (i < vm->progs_nb)
    {
      del_champ(vm, i);
      del_prog(vm, i);
      i++;
    }
  free(vm->champs);
  free(vm->progs);
}
