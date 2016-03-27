/*
** pc_correction.c for pc_correction in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 22:41:59 2016 Marwane
** Last update Sun Mar 27 16:15:41 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

void		pc_correction(t_vm *vm)
{
  t_champ	*tmp_champs;
  t_prog	*tmp_progs;

  tmp_champs = vm->champs;
  tmp_progs = vm->progs;
  while (tmp_progs)
    {
      my_imemset(tmp_champs->registres, 0, 16);
      tmp_champs->registres[0] = tmp_progs->prog_number;
      tmp_champs->pc = tmp_progs->address;
      tmp_champs = tmp_champs->next;
      tmp_progs = tmp_progs->next;
    }
}
