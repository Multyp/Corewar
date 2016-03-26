/*
** champions_actions.c for champions_actions in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 08:12:21 2016 Marwane
** Last update Sat Mar 26 08:19:02 2016 Marwane
*/

#include "vm_corewar.h"

/* void		champion_turn(t_vm *vm, */
/* 			      t_champ *tmp_champ, */
/* 			      t_prog *tmp_prog) */
/* { */

/* } */

void		champions_actions(t_vm *vm)
{
  t_champ	*tmp_champ;
  t_prog	*tmp_prog;

  tmp_champ = vm->champs;
  tmp_prog = vm->tmp_progs;
  while (tmp_champ)
    {
      if (tmp->champ->cycles_to_wait == 0)
	champion_turn(vm, tmp_champ, tmp_prog);
      else
	tmp->champ->cycles_to_wait--;
      tmp_champ = tmp_champ->next;
      tmp_prog = tmp_prog->next;
    }
}
