/*
** options.c for options in /home/khsime_m/PSU_2015_tetris/src
**
** Made by marwane khsime
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 19 23:02:29 2016 marwane khsime
** Last update Sat Mar 19 23:02:30 2016 marwane khsime
*/

#include "vm_corewar.h"

char	**get_opts()
{
  char	**d_opts;

  if ((d_opts = malloc(sizeof(char *) * 4)) == NULL ||
      (d_opts[0] = my_strdup("--help")) == NULL ||
      (d_opts[1] = my_strdup("-dump")) == NULL ||
      (d_opts[2] = my_strdup("-n")) == NULL ||
      (d_opts[3] = my_strdup("-a")) == NULL)
    return (my_perror(MALLOC_FAILED));
  return (d_opts);
}

int	fct_call(int opt, t_vm *vm, char *next_param)
{
  int	(*ptr[4])(t_vm *, char *);

  ptr[0] = &show_help;
  ptr[1] = &my_dump_memory;
  ptr[2] = &my_next_prognumber;
  ptr[3] = &my_load_address;
  return (ptr[opt](vm, next_param));
}

void	free_options(char **opts)
{
  int	i;

  i = 0;
  while (i != 4)
    free (opts[i++]);
  free (opts);
}

int	check_options(char **av, t_vm *vm, int ac)
{
  int   i;
  int	j;
  char	**opts;

  opts = get_opts();
  get_binary(av[0]);
  i = 1;
  while (opts && i < ac)
    {
      j = 0;
      while (j != 4 && my_strcmp(av[i], opts[j]) != 0)
	j++;
      if (j == 4)
	return (my_error("check_file_prog"));
      i += fct_call(j, vm, av[i + 1]);
    }
  free_options(opts);
  return (0);
}
