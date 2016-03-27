/*
** write_indirects.c for lol in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sat Mar 26 19:50:45 2016 Poc
** Last update Sat Mar 26 20:29:55 2016 Poc
*/

#include "asm.h"

int	write_indirects(t_arg *arg, int fd)
{
  short	new_endian;

  new_endian = ((arg->value >> 8 & 0x00FF) | (arg->value << 8));
  write(fd, &new_endian, 2);
  return (0);
}
