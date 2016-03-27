/*
** get_base_16.c for get_base in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 22:59:10 2016 Marwane
** Last update Sat Mar 26 23:50:35 2016 Marwane
*/

#include "vm_corewar.h"

void		put_char_base_16(unsigned char c)
{
  static int	nb_octets = 0;
  char		*base;
  char		result[3];
  int		i;

  base = "0123456789ABCDEF";
  my_memset(result, 0, 3);
  i = 0;
  nb_octets++;
  if (c == 0)
    my_putstr("00");
  else
    {
      while (c > 0)
	{
	  result[i++] = base[c % 16];
	  c /= 16;
	}
      my_printf("%s", my_revstr(result));
      (i < 2 ? write(1, "0", 1) : i);
    }
  (nb_octets == 32 ? write(1, "\n", 1), nb_octets = 0 : write(1, " ", 1));
}

void		put_memory_hexa_format(char *arena)
{
  int		i;

  i = 0;
  while (i < MEM_SIZE)
    put_char_base_16(arena[i++]);
}
