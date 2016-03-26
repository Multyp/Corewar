/*
** progs_sorting.c for sorting in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Wed Mar 23 11:36:06 2016 Da Fonseca Samuel
** Last update Sat Mar 26 07:18:10 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	checkprogs(int *progstab, int n, int check)
{
  int	i;

  i = 0;
  while (i != n && progstab[i] != -1)
    {
      if (progstab[i] == check)
	return (1);
      i++;
    }
  return (0);
}

void		add_prognb(int *s, t_vm *vm, int stock, int n)
{
  t_prog	*tmp_prog;
  t_champ	*tmp_champ;
  int		i;

  i = 0;
  while (s[i] != -1)
    i++;
  tmp_champ = vm->champs;
  tmp_prog = vm->progs;
  while (tmp_champ != NULL)
    {
      if (tmp_champ->size == stock && tmp_prog->address == -1 &&
	  checkprogs(s, n, tmp_prog->prog_number) == 0)
	s[i] = tmp_prog->prog_number;
      tmp_prog = tmp_prog->next;
      tmp_champ = tmp_champ->next;
    }
}

int		*sortingprogs(t_vm *vm, int n, int *s, int *sorted_progs)
{
  int		i;
  t_champ	*tmp_champ;
  t_prog	*tmp_prog;
  int		stock;

  i = 0;
  while (i != n - 1)
    {
      tmp_champ = vm->champs;
      tmp_prog = vm->progs;
      stock = 0;
      while (tmp_champ != NULL)
	{
	  if (tmp_champ->size > stock && tmp_prog->address == -1 &&
	      checkprogs(s, n, tmp_prog->prog_number) == 0)
	    stock = tmp_champ->size;
	  tmp_champ = tmp_champ->next;
	  tmp_prog = tmp_prog->next;
	}
      sorted_progs[i] = stock;
      add_prognb(s, vm, stock, n);
      i++;
    }
  return (sorted_progs);
}


int		*check_spaces_with_progs(t_vm *vm)
{
  int		*sorted_progs;
  t_prog	*tmp;
  int		n;
  int		*s;

  tmp = vm->progs;
  n = 0;
  while (tmp != NULL)
    {
      if (tmp->address == -1)
	n++;
      tmp = tmp->next;
    }
  if ((sorted_progs = malloc(sizeof(int) * (n + 1))) == NULL ||
      (s = malloc(sizeof(int) * (n + 1))) == NULL)
    return (my_perror(MALLOC_FAILED));
  my_imemset(s, -1, n + 1);
  my_imemset(sorted_progs, -1, n + 1);
  if ((sorted_progs = sortingprogs(vm, (n + 1), s, sorted_progs)) == NULL)
    return (NULL);
  return (sorted_progs);
}
