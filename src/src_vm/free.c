/*
** free.c for free in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Tue Mar 22 15:56:29 2016 Da Fonseca Samuel
** Last update Sun Mar 27 20:56:36 2016 Marwane
*/

#include "vm_corewar.h"

void	my_freeprog(t_prog *prog)
{
  if (prog->prog_name != NULL)
    free(prog->prog_name);
  free(prog);
}
