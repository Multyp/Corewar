/*
** free.c for free in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Tue Mar 22 15:56:29 2016 Da Fonseca Samuel
** Last update Tue Mar 22 15:56:31 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

void	my_freeprog(t_prog *prog)
{
  if (prog->prog_name != NULL)
    free (prog->prog_name);
  free (prog);
}
