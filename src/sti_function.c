/*
** sti_function.c for sti_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:50:29 2016 Marwane
** Last update Sun Mar 27 19:55:38 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	check_stioctet(int octet[])
{
  if (octet[0] != T_REG ||
      (octet[1] != T_REG && octet[1] != T_DIR &&
       octet[1] != T_IND) ||
      (octet[2] != T_DIR && octet[2] != T_REG) ||
      octet[3] != 0)
    return (1);
  return (0);
}

int	init_stiopeparams(t_vm *vm, t_champ *champ, int octet, int *p)
{
  if (get_spesize(octet) == 1)
    {
      *p = (char)(champ->registres[(get_myint(vm, champ->pc, 1) - 1) % 16]);
      return (1);
    }
  *p = (short)get_myint(vm, champ->pc, 2);
  return (2);
}

void	write_map(t_vm *vm, int reg, int pos)
{
  int	c;
  int	reg_changed;

  c = 0;
  reg_changed = change_endian(reg);
  while (c != 4)
    {
      reg_changed = change_endian(reg);
      vm->arena[(pos + c) % MEM_SIZE] =
	(reg_changed >> ((3 - c) * 8) % 126);
      c++;
    }
}

int	sti_function(t_vm *vm, t_champ *champ)
{
  int	octet[4];
  int	i;
  int	p1;
  int	p2;
  int	p3;
  int	s;

  i = 0;
  s = champ->pc;
  while (i != 4)
    {
      octet[i] = get_octet_code(0, i, vm->arena[champ->pc]);
      i++;
    }
  if (check_stioctet(octet) == 1)
    return (1);
  champ->cycles_to_wait += 25;
  champ->pc = (champ->pc + 1) % MEM_SIZE;
  p1 = get_myint(vm, champ->pc, 1);
  champ->pc = (champ->pc + 1) % MEM_SIZE;
  i = init_stiopeparams(vm, champ, octet[1], &p2);
  champ->pc = (champ->pc + i) % MEM_SIZE;
  i = init_stiopeparams(vm, champ, octet[2], &p3);
  champ->pc = (champ->pc + i) % MEM_SIZE;
  write_map(vm, champ->registres[(p1 - 1) % 16], (s + p1 + p2) % MEM_SIZE);
  return (1);
}
