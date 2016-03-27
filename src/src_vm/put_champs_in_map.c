/*
** put_champs_in_map.c for put_champs_in_map in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Thu Mar 24 05:28:00 2016 Marwane
** Last update Sun Mar 27 20:11:06 2016 Marwane
*/

#include "vm_corewar.h"

void		memset_arena(char *arena, char *instructions,
			     int address, int size)
{
  int		pos;
  int		i;

  pos = address;
  i = 0;
  while (i < size)
    {
      arena[pos % MEM_SIZE] = instructions[i];
      i++;
      pos ++;
    }
}

void		send_to_memset_arena(char *arena,
				     t_champ *tmp_champ,
				     t_prog *tmp_prog)
{
  char		buff[tmp_champ->size + 1];
  char		c[2192 + 1];
  int		readed;
  int		fd;

  if ((fd = open(tmp_prog->prog_name, O_RDONLY)) == -1)
    return ;
  readed = read(fd, c, 2192);
  readed = read(fd, buff, tmp_champ->size);
  buff[readed] = 0;
  memset_arena(arena, buff, tmp_prog->address, tmp_champ->size);
  close(fd);
}

void		file_arena(t_vm *vm)
{
  t_champ	*tmp_champs;
  t_prog	*tmp_progs;

  tmp_champs = vm->champs;
  tmp_progs = vm->progs;
  while (tmp_champs && tmp_progs)
    {
      send_to_memset_arena(vm->arena, tmp_champs, tmp_progs);
      tmp_champs = tmp_champs->next;
      tmp_progs = tmp_progs->next;
    }
}
