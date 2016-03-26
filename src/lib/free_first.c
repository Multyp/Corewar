/*
** free_first.c for lib in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Fri Mar 18 10:39:08 2016 Clement Peau
** Last update Fri Mar 18 10:52:06 2016 Clement Peau
*/

#include "asm.h"

void		*free_first(t_file *list)
{
  t_file	*tmp;

  free(list->str);
  tmp = list->next;
  free(list);
  return (tmp);
}
