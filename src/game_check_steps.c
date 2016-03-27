/*
** game_check_steps.c for game_check_steps in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 06:23:36 2016 Marwane
** Last update Sun Mar 27 03:45:10 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

void		does_everybody_say_alive(t_vm *vm)
{
  t_champ	*tmp_champ;
  t_prog	*tmp_prog;
  int		i;

  i = 0;
  tmp_champ = vm->champs;
  tmp_prog = vm->progs;
  while (tmp_champ && vm->progs_nb > 1)
    {
      if (tmp_champ->alive == false)
	{
	  tmp_champ = tmp_champ->next;
	  tmp_prog = tmp_prog->next;
	  del_prog(vm, i);
	  del_champ(vm, i);
	}
      else
	{
	  tmp_champ->alive = false;
	  tmp_champ = tmp_champ->next;
	  tmp_prog = tmp_prog->next;
	}
      i++;
    }
}

void		game_check_steps(t_vm *vm)
{
  vm->cycle++;
  if (vm->cycle >= vm->cycle_die)
    {
      does_everybody_say_alive(vm);
      vm->cycle = 0;
    }
}
