/*
** fill_action.c for fill in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Fri Mar 18 12:14:12 2016 Clement Peau
** Last update Fri Mar 18 12:48:43 2016 Clement Peau
*/

#include "asm.h"

int		fill_action(t_action *action, t_file *file)
{
  while (file->next != NULL)
    {
      add_to_back_action(action, file->str);
      file = file->next;
    }
}
