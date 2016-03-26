/*
** write_types.c for write types in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 24 17:50:43 2016 Poc
** Last update Sat Mar 26 19:59:59 2016 Poc
*/

#include "asm.h"

short	find_label_short(t_label *label, char *name, int pos)
{
  short	i;

  if (label->name == NULL || name == NULL)
      return (-1);
  while (label && my_strcmp(label->name, name) != 0)
      label = label->next;
  if (label && pos >= label->pos)
    {
      i = 0xFFFF;
      printf("(label->pos - pos) %hx\n", ((short)label->pos - pos));
      return (((short)label->pos - pos));
    }
  if (label != NULL)
    return ((short)label->pos - pos);
  else
      return (-1);
}

int	find_label(t_label *label, char *name, int pos)
{
  int	i;

  if (label->name == NULL || name == NULL)
      return (-1);
  while (label && my_strcmp(label->name, name) != 0)
      label = label->next;
  if (label && pos > label->pos)
    {
      i = 0xFFFFFFFF;
      return (i - pos);
    }
  if (label)
    return ((short)label->pos - pos);
  else
      return (-1);
}

int	write_registers(t_arg *arg, int fd, int decal)
{
  char	c;

  c = arg->value;
  write(fd, &c, 1);
  return (0);
}

int	write_direct(t_arg *arg, int fd, t_label *label, int decal)
{
  int	new_endian;

  if (arg->link_name != NULL)
    {
      if ((new_endian =
	   find_label(label, arg->link_name, decal)) == -1)
	  return (1);
      new_endian = change_endian(new_endian);
      write(fd, &new_endian, 4);
    }
  else
    {
      new_endian = change_endian(arg->value);
      write (fd, &new_endian, 4);
    }
  return (0);
}

int	write_odds(t_arg *arg, int fd, t_label *label, int decal)
{
  short	new_endian;
  short	tmp;

  if (arg->link_name != NULL)
    {
      if ((tmp =
	   find_label_short(label, arg->link_name, decal)) == -1)
	return (1);
      new_endian = (((tmp >> 8) & 0x00FF) | (((tmp << 8) & 0xFF00)));
  write(fd, &new_endian, 2);
}
  else
    {
      new_endian = (((arg->value >> 8) & 0x00FF) |
		    ((arg->value << 8) & 0xFF00));
      write (fd, &new_endian, 2);
    }
  return (0);
}
