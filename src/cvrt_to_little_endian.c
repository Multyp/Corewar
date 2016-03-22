/*
** cvrt_to_little_endian.c for endian in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Tue Mar 22 15:56:53 2016 Da Fonseca Samuel
** Last update Tue Mar 22 15:56:53 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int		convert_to_little_endian(int size)
{
  return (((size >> 24) & 0xFF) |
	  ((size << 8) & 0xFF0000) |
	  ((size >> 8) & 0xFF00) |
	  ((size << 24 & 0xFF000000)));
}
