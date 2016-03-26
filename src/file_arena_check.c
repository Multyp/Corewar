/*
** file_arena_check.c for file_arena_check in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 04:07:59 2016 Marwane
** Last update Sat Mar 26 04:25:11 2016 Marwane
*/

#include "vm_corewar.h"

void		file_map_check(int arena[], int size, int address, int tag)
{
  int		i;
  int		pos;

  i = 0;
  pos = address;
  while (i++ < size)
    arena[pos++] = tag;
}

void		file_arena_check(t_vm *vm)
{
  t_champ	*tmp_champs;
  t_prog	*tmp_progs;

  my_imemset(vm->arena_check, -1, MEM_SIZE);
  tmp_champs = vm->champs;
  tmp_progs = vm->progs;
  while (tmp_champs)
    {
      file_map_check(vm->arena_check, tmp_champs->size,
		     tmp_progs->address, tmp_progs->prog_number);
      tmp_champs = tmp_champs->next;
      tmp_progs = tmp_progs->next;
    }
}
