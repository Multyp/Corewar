/*
** default_addr.c for default_addr in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Wed Mar 23 10:17:56 2016 Da Fonseca Samuel
** Last update Sat Mar 26 07:18:30 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	*getfreespaces(char map[])
{
  int	*freespaces;
  int	n;
  int	i;
  int	x;

  x = (MAX_ARGS_NUMBER + 1) * 2;
  i = 0;
  n = 0;
  if ((freespaces = malloc(sizeof(int) * x)) == NULL)
    return (my_perror(MALLOC_FAILED));
  my_imemset(freespaces, -1, x);
  while (i != MEM_SIZE && n < x)
    {
      if (map[i] == '*')
	{
	  freespaces[n++] = i;
	  while (i != MEM_SIZE - 1 && map[i] == '*')
	    i++;
	  freespaces[n++] = i;
	  if (i == MEM_SIZE)
	    return (freespaces);
	}
      i++;
    }
  return (freespaces);
}

void    write_champ(t_prog *prog, t_champ *champ, char map[])
{
  int   n;

  n = (champ->size > (MEM_SIZE - prog->address))
    ? (MEM_SIZE - prog->address) : champ->size;
  my_memset(&map[prog->address], 'A', n);
  if (n == champ->size)
    return ;
  my_memset(map, 'B', champ->size - n);
}

int		*write_progs(t_vm *vm, char map[])
{
  t_prog        *tmp_prog;
  t_champ       *tmp_champ;

  tmp_prog = vm->progs;
  tmp_champ = vm->champs;
  my_memset(map, '*', MEM_SIZE + 1);
  map[MEM_SIZE] = '\0';
  while (tmp_prog != NULL)
    {
      if (tmp_prog->address != -1)
	write_champ(tmp_prog, tmp_champ, map);
      tmp_prog = tmp_prog->next;
      tmp_champ = tmp_champ->next;
    }
  tmp_prog = vm->progs;
  tmp_champ = vm->champs;
  return (getfreespaces(map));
}

int	*init_addr(int *sfs, int *prog_size)
{
  int	i;
  int	n;
  int	*addr;
  int	stock;

  stock = 0;
  n = get_nbtab(prog_size);
  if ((addr = malloc(sizeof(int) * (n + 1))) == NULL)
    return (NULL);
  i = 0;
  my_imemset(addr, -1, n + 1);
  while (i != n)
    {
      if ((stock = get_addr(sfs, prog_size[i])) == -1)
	return (NULL);
      addr[i] = sfs[stock];
      sfs[stock] += prog_size[i];
      i++;
    }
  free(sfs);
  free(prog_size);
  return (addr);
}

int		default_addr(t_vm *vm)
{
  char		map[MEM_SIZE + 1];
  t_prog	*tmp_prog;
  int		*free_spaces;
  int		*progs_ordered;
  int		*new_addr;
  int		i;

  if ((free_spaces = write_progs(vm, map)) == NULL ||
      (progs_ordered = check_spaces_with_progs(vm)) == NULL)
    return (1);
  if (get_sizetoload(progs_ordered) > get_sizefree(free_spaces) ||
      (new_addr = init_addr(free_spaces, progs_ordered)) == NULL)
    return (my_error("Error: Can't load every program"));
  tmp_prog = vm->progs;
  i = 0;
  while (new_addr[i] != -1)
    {
      while (tmp_prog->address != -1)
	tmp_prog = tmp_prog->next;
      tmp_prog->address = new_addr[i];
      i++;
      tmp_prog = tmp_prog->next;
    }
  free(new_addr);
  return (0);
}
