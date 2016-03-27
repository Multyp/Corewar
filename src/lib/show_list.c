/*
** show_list.c for show_list in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 17 15:50:00 2016 Clement Peau
** Last update Thu Mar 17 16:06:15 2016 Clement Peau
*/

#include "asm.h"

void		show_list(void *list)
{
  t_file	*tmp;

  tmp = list;
  while (tmp->next != NULL)
    {
      my_putstr(tmp->str);
      write(1, "\n", 1);
      tmp = tmp->next;
    }
  my_putstr(tmp->str);
  write(1, "\n", 1);
}
