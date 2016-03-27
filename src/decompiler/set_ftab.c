/*
** set_ftab.c for set_ftab in /home/arnaud_e/rendu/cpe/corewar/src/decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Mar  2 07:11:29 2016 Arthur ARNAUD
** Last update Wed Mar  2 14:51:38 2016 Arthur ARNAUD
*/

#include "decompiler.h"

ftab	*set_ftab(ftab *tab)
{
  if (!(tab = malloc(sizeof(ftab) * 17)))
    return (NULL);
  tab[0] = op_live;
  tab[1] = op_ld;
  tab[2] = op_st;
  tab[3] = op_add;
  tab[4] = op_sub;
  tab[5] = op_and;
  tab[6] = op_or;
  tab[7] = op_xor;
  tab[8] = op_zjmp;
  tab[9] = op_ldi;
  tab[10] = op_sti;
  tab[11] = op_fork;
  tab[12] = op_lld;
  tab[13] = op_lldi;
  tab[14] = op_lfork;
  tab[15] = op_aff;
  tab[16] = NULL;
  return (tab);
}
