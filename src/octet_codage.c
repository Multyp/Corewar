/*
** octet_codage.c for octet_codage in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 11:07:59 2016 Marwane
** Last update Sat Mar 26 20:45:37 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	get_myint(t_vm *vm, t_champ *champ)
{
  int	nb;
  int	c;
  int	p;

  p = champ->pc;
  c = 0;
  nb = 0;
  while (c != 4)
    {
      nb += (vm->arena[p] << (3 - c) * 4);
      p = (p + 1) % MEM_SIZE;
      c++;
    }
  return (nb);
}


int		get_size_octet_code(unsigned char codage)
{
  int		c;
  unsigned char	octet;
  int		size[4];

  size[0] = 0;
  size[1] = 1;
  size[2] = 2;
  size[3] = 4;
  c = 0;
  while (c != 4)
    {
      octet = codage;
      octet = octet >> ((3 - c) * 2);
      octet = octet % 4;
      if (octet == 0)
	{
	  printf("octet null size octet = %d\n", c);
	  return (c);
	}
      c += size[octet];
      printf("octet = %d\tsize[octet] = %d\n", octet, size[octet]);
    }
  printf("size octet = %d\n", c);
  return (c);
}

int		get_octet_code(int special_func, int parameter, char codage)
{
  unsigned char	c;

  if (special_func != 0)
    return (get_size_octet_code(codage));
  c = codage;
  c = c >> ((3 - parameter) * 2);
  c = c % 4;
  return (c);
}
