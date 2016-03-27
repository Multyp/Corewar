/*
** live_function.c for live_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 06:15:33 2016 Marwane
** Last update Sun Mar 27 16:21:16 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int		live_function(t_vm *vm, t_champ *champ)
{
  t_champ	*tmp_champ;
  t_prog	*tmp_prog;
  int		nb;

  if (++vm->live_calls == NBR_LIVE)
    {
      vm->live_calls = 0;
      vm->cycle_die -= (vm->cycle_die - CYCLE_DELTA > 0 ? CYCLE_DELTA : 0);
    }
  tmp_champ = vm->champs;
  tmp_prog = vm->progs;
  nb = get_myint(vm, champ->pc, 4);
  printf("live pour nb = %d\n", nb);
  while (tmp_champ != NULL && tmp_champ->next != NULL)
    {
      if (tmp_champ->registres[0] == nb)
	{
	  my_printf("Le joueur %d(%s) est en vie,\n",
		    tmp_prog->prog_number, tmp_champ->name);
	  tmp_champ->alive = true;
	}
      tmp_champ = tmp_champ->next;
      tmp_prog = tmp_prog->next;
    }
  champ->cycles_to_wait += 10;
  champ->pc = (champ->pc + 4) % MEM_SIZE;
  return (0);
}
