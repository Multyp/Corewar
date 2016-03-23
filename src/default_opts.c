/*
** default_opts.c for default_opts in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Tue Mar 22 15:55:49 2016 Da Fonseca Samuel
** Last update Wed Mar 23 06:53:22 2016 Da Fonseca Samuel
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

void	write_champs(t_vm *vm, char map[])
{
  t_prog	*tmp_prog;
  t_champ	*tmp_champ;

  tmp_prog = vm->progs;
  tmp_champ = vm->champs;
  my_memset(map, 0, MEM_SIZE + 1);
  while (tmp_prog != NULL)
    {
      if (tmp_prog->address != -1)
	write_champ(tmp_prog, tmp_champ, map);
      tmp_prog = tmp_prog->next;
      tmp_champ = tmp_champ->next;
    }
  tmp_prog = vm->progs;
  tmp_champ = vm->champs;


}

void		init_progaddress(t_vm *vm)
{
  char		map[MEM_SIZE + 1];
  int		i;
  char		c;
  t_champ	*tmp_champ;
  t_prog	*tmp_prog;

  i = 0;
  c = '\0';
  write_champs(vm, map);
  tmp_prog = vm->progs;
  tmp_champ = vm->champs;
  while (i++ != MEM_SIZE && tmp_prog)
    {
      while (map[i] != c && i++ != MEM_SIZE);
      c = map[--i];
      while (tmp_prog != NULL && tmp_prog->address != -1)
	{
	  tmp_prog = tmp_prog->next;
	  tmp_champ = tmp_champ->next;
	}
      if (!tmp_prog)
	return ;
      tmp_prog->address = i;
      write_champ(tmp_prog, tmp_champ, map);
    }
}
