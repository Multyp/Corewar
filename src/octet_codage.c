/*
** octet_codage.c for octet_codage in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 11:07:59 2016 Marwane
** Last update Sat Mar 26 11:13:11 2016 Marwane
*/

#include "vm_corewar.h"

int	get_octet_code(int special_func, int parameter, char codage)
{
  char	c;

  c = codage;
  c >>= parameter * 2;
  return ((special_func == 1 ? parameter / 2 : parameter));
}
