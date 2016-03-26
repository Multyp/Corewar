/*
** check_champs_size.c for check_champs_size in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 03:40:16 2016 Marwane
** Last update Sat Mar 26 16:39:48 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int		check_champs_sizes_file_map(int map[], int size,
					    int address, int flag)
{
  int		i;
  int		pos;

  i = 0;
  pos = address;
  while (i++ < size)
    {
      if (map[pos] != -1)
	return (-1);
      map[pos++] = flag;
      if (pos >= MEM_SIZE)
	return (-1);
    }
  return (0);
}

int		check_champs_sizes(t_vm *vm)
{
  t_champ	*tmp_champs;
  t_prog	*tmp_progs;
  int		map[MEM_SIZE + 1];

  tmp_champs = vm->champs;
  tmp_progs = vm->progs;
  my_imemset(map, -1, MEM_SIZE + 1);
  while (tmp_champs)
    {
      if (check_champs_sizes_file_map(map, tmp_champs->size, tmp_progs->address,
				      tmp_progs->prog_number) == -1)
	return (my_error("Error: not enough spaces for champions"));
      tmp_champs = tmp_champs->next;
      tmp_progs = tmp_progs->next;
    }
  return (0);
}
