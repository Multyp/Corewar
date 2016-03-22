/*
** set_ftab.c for set_ftab in /CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Mar 22 02:20:07 2016 Arthur ARNAUD
** Last update Tue Mar 22 19:36:27 2016 Poc
*/

#include "asm.h"

t_ftab	*set_ftab(t_ftab *ftab)
{
  if ((!(ftab = malloc(sizeof(t_ftab *) * 17))))
    return (NULL);
  /* ftab[0] = op_live; */
  /* ftab[1] = op_ld; */
  /* ftab[2] = op_st; */
  /* ftab[3] = op_add; */
  /* ftab[4] = op_sub; */
  /* ftab[5] = op_and; */
  /* ftab[6] = op_or; */
  /* ftab[7] = op_xor; */
  /* ftab[8] = op_zjmp; */
  /* ftab[9] = op_ldi; */
  /* ftab[10] = op_sti; */
  /* ftab[11] = op_fork; */
  /* ftab[12] = op_lld; */
  /* ftab[13] = op_lldi; */
  /* ftab[14] = op_lfork; */
  /* ftab[15] = op_aff; */
  ftab[0] = op_live;
  ftab[1] = NULL;
  ftab[2] = NULL;
  ftab[3] = NULL;
  ftab[4] = NULL;
  ftab[5] = NULL;
  ftab[6] = NULL;
  ftab[7] = NULL;
  ftab[8] = NULL;
  ftab[9] = NULL;
  ftab[10] = NULL;
  ftab[11] = NULL;
  ftab[12] = NULL;
  ftab[13] = NULL;
  ftab[14] = NULL;
  ftab[15] = NULL;
  ftab[16] = NULL;
  return (ftab);
}
