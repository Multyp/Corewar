/*
** change_to_odds.c for change_to_odds in /CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Fri Mar 25 19:23:11 2016 Arthur ARNAUD
** Last update Fri Mar 25 19:25:37 2016 Arthur ARNAUD
*/

#include "asm.h"

int	change_to_odds(t_arg *arg)
{
  if (arg->type == 2)
    arg->type = 4;
  return (0);
}
