/*
** check_functions.c for check_functions in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 02:44:26 2016 Marwane
** Last update Sat Mar 26 09:47:34 2016 Marwane
*/

#include ""

void	functions_vm(t_champ *champ, int i, t_vm *vm)
{
  int	(*ptr[16])(t_champ *, char *);

  ptr[0] = &function_live;
  ptr[1] = &function_ld;
  ptr[2] = &function_st;
  ptr[3] = &function_add;
  ptr[4] = &function_sub;
  ptr[5] = &function_and;
  ptr[6] = &function_or;
  ptr[7] = &function_xor;
  ptr[8] = &function_zjmp;
  ptr[9] = &function_ldi;
  ptr[10] = &function_sti;
  ptr[11] = &function_fork;
  ptr[12] = &function_lld;
  ptr[13] = &function_lldi;
  ptr[14] = &function_lfork;
  ptr[15] = &function_aff;
  ptr[c](champ, vm->arena);
}
