/*
** addr_get.c for addr_get in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Fri Mar 25 02:08:59 2016 Da Fonseca Samuel
** Last update Sat Mar 26 07:10:52 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	get_nbtab(int *tab)
{
  int	i;

  i = 0;
  while (tab[i] != -1)
    i++;
  return (i);
}

int	get_sizetoload(int *progs_ordered)
{
  int	value;
  int	i;

  i = 0;
  value = 0;
  while (progs_ordered[i] != -1)
    {
      value += progs_ordered[i];
      i++;
    }
  return (value);
}

int	get_sizefree(int *free_spaces)
{
  int	i;
  int	value;

  i = 0;
  value = 0;
  while (i != ((MAX_ARGS_NUMBER + 1) * 2) && free_spaces[i] != -1)
    {
      value += (free_spaces[i + 1] - free_spaces[i]);
      i += 2;
    }
  return (value);
}

int	check_addr(int *news, int value)
{
  int	i;

  i = 0;
  while (news[i] != -1)
    {
      if (news[i] == value)
	return (1);
      i++;
    }
  return (0);
}

int	get_addr(int *activefs, int size)
{
  int	i;

  i = 0;
  while (i < ((MAX_ARGS_NUMBER + 1) * 2) && activefs[i] != -1)
    {
      if (activefs[i + 1] - activefs[i] >= size)
	return (i);
      i += 2;
    }
  return (-1);
}
