/*
** aff_winner.c for aff_winner in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sun Mar 27 09:47:24 2016 Marwane
** Last update Sun Mar 27 20:05:31 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

void		aff_winner(t_vm *vm)
{
  my_printf("Le joueur n°%d(%s) a gagné la partie, c'est le boss du game.\n",
	    vm->progs->prog_number, vm->champs->name);
  return ;
}
