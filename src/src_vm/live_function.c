/*
** live_function.c for live_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 06:15:33 2016 Marwane
** Last update Sun Mar 27 19:59:59 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int		live_function(t_vm *vm, t_champ *champ)
{
  t_champ	*c;
  t_prog	*p;
  int		nb;

  if (++vm->live_calls == NBR_LIVE)
    {
      vm->live_calls = 0;
      vm->cycle_die -= (vm->cycle_die - CYCLE_DELTA > 0 ? CYCLE_DELTA : 0);
    }
  c = vm->champs;
  p = vm->progs;
  nb = get_myint(vm, champ->pc, 4);
  while (c != NULL && c->next != NULL)
    {
      if (c->registres[0] == nb || c == champ || p->prog_number == nb)
	{
	  my_printf("Le joueur %d(%s) est en vie\n", p->prog_number, c->name);
	  c->alive = true;
	}
      c = c->next;
      p = p->next;
    }
  champ->cycles_to_wait += 10;
  champ->pc = (champ->pc + 4) % MEM_SIZE;
  return (1);
}
