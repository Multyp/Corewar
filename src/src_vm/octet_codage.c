/*
** octet_codage.c for octet_codage in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 11:07:59 2016 Marwane
** Last update Sun Mar 27 22:06:19 2016 Poc
*/

#include "vm_corewar.h"

int	get_spesize(int opt)
{
  int	sizes[4];

  sizes[0] = 0;
  sizes[1] = 1;
  sizes[2] = 2;
  sizes[3] = 2;
  return (sizes[opt]);
}

int	get_size(int opt)
{
  int	sizes[4];

  sizes[0] = 0;
  sizes[1] = 1;
  sizes[2] = DIR_SIZE;
  sizes[3] = IND_SIZE;
  return (sizes[opt]);
}

int	get_myint(t_vm *vm, int pc, int n_octets)
{
  int	c;
  char	s[n_octets + 1];
  int	nb;

  nb = 0;
  my_memset(s, 0, n_octets + 1);
  c = 0;
  while (c != n_octets)
    {
      s[c] = vm->arena[pc];
      pc = (pc + 1) % MEM_SIZE;
      c++;
    }
  c--;
  while (c >= 0)
    {
      nb += ((s[c] << (8 * c)) % 126);
      c--;
    }
  return (nb);
}

int		get_size_octet_code(unsigned char codage)
{
  int		c;
  unsigned char	octet;
  int		nb;

  nb = 0;
  c = 0;
  while (c != 4)
    {
      octet = codage;
      octet = octet >> ((3 - c) * 2);
      octet = octet % 4;
      if (octet == 0)
	  return (nb);
      nb += get_size(octet);
      c++;
    }
  return (nb);
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
