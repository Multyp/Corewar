/*
** lfork_function.c for lfork_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:51:53 2016 Marwane
** Last update Sun Mar 27 10:22:15 2016 Marwane
*/

#include "vm_corewar.h"

t_prog		*get_current_prog_lfork(t_vm *vm, t_champ *champ)
{
  t_champ	*tmp_champ;
  t_prog	*tmp_prog;

  tmp_champ = vm->champs;
  tmp_prog = vm->progs;
  while (tmp_champ != champ && tmp_champ != NULL)
    {
      tmp_champ = tmp_champ->next;
      tmp_prog = tmp_prog->next;
    }
  if (tmp_champ)
    return (tmp_prog);
  return (NULL);
}

int		lfork_function(t_vm *vm, t_champ *champ)
{
  t_prog	*tmp_prog;

  if ((tmp_prog = get_current_prog_lfork(vm, champ)) != NULL)
    {
      if ((add_champ_to_list(vm, tmp_prog->prog_name,
                        (champ->pc + get_myint(vm, champ->pc, 2)) % MEM_SIZE,
			     tmp_prog->prog_number)) != NULL)
	add_prog(vm, tmp_prog->prog_name);
    }
  champ->cycles_to_wait += 1000;
  return (1);
}
