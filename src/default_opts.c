/*
** default_opts.c for default_opts in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Tue Mar 22 15:55:49 2016 Da Fonseca Samuel
** Last update Wed Mar 23 03:41:22 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

void		init_defaultvalues(t_vm *vm)
{
  int		nb;
  t_prog	*tmp;

  tmp = vm->progs;
  nb = 0;
  while (vm->progs != NULL)
    {
      while (check_list_for_prognb(vm, nb) == 1)
      	nb++;
      if (vm->progs->prog_number == -1)
	vm->progs->prog_number = nb++;
      vm->progs = vm->progs->next;
    }
  vm->progs = tmp;
}

void	write_champ(t_prog *prog, t_champ *champ, char map[])
{
  int	n;

  n = (champ->size > (MEM_SIZE - prog->address))
    ? (MEM_SIZE - prog->address) : champ->size;
  my_memset(&map[prog->address], prog->prog_number + 48, n);
  if (n == champ->size)
    return ;
  my_memset(map, prog->prog_number, champ->size - n);
}

int	get_freespace(char map[])
{
  int	i;
  int	value;

  i = 0;
  value = 0;
  while (i != MEM_SIZE)
    {
      if (map[i] != '\0')
	value++;
      i++;
    }
  return (value);
}

void		init_progaddress(t_vm *vm)
{
  char		map[MEM_SIZE + 1];
  t_prog	*tmp_prog;
  t_champ	*tmp_champ;
  int		n;
  int		freespace;

  n = 0;
  printf("entrée init default address\n");
  tmp_prog = vm->progs;
  tmp_champ = vm->champs;
  my_memset(map, 0, MEM_SIZE);
  map[MEM_SIZE] = '\0';
  while (tmp_prog != NULL)
    {
      if (tmp_prog->address != -1)
	{
	  write_champ(tmp_prog, tmp_champ, map);
	  n++;
	}
      tmp_prog = tmp_prog->next;
      tmp_champ = tmp_champ->next;
    }
  freespace = get_freespace(map);
  printf("[map] = \n%s\n", map);
  printf("sortie init default addres\n");
}
