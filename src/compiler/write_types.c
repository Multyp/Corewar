/*
** write_types.c for write types in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 24 17:50:43 2016 Poc
** Last update Fri Mar 25 15:33:46 2016 Poc
*/

#include "asm.h"

int	find_label_short(t_label *label, char *name, int pos)
{
  int	i;

  if (label->name || name)
    return (-1);
  printf("label->name %s\n", label->name);
  printf("name %s\n", name);
  while (label && my_strcmp(label->name, name) != 0)
    {
      label = label->next;
    }
  printf("AFTR - label->name %s\n", label->name);
  printf("find_label->pos %d && label->pos%d\n", pos, label->pos);
  if (pos > label->pos)
    {
      i = 0xFFFF;
      return (i - pos);
    }
  if (label)
    return (label->pos - pos);
  else
    return (-1);
}

int	find_label(t_label *label, char *name, int pos)
{
  int	i;

  if (label->name || name)
    return (-1);
  printf("label->name %s\n", label->name);
  printf("name %s\n", name);
  while (label && my_strcmp(label->name, name) != 0)
    {
      label = label->next;
    }
  printf("AFTR - label->name %s\n", label->name);
  printf("find_label->pos %d && label->pos%d\n", pos, label->pos);
  if (pos > label->pos)
    {
      i = 0xFFFFFFFF;
      return (i - pos);
    }
  if (label)
    return (label->pos - pos);
  else
    return (-1);
}

int	write_registers(t_arg *arg, int fd)
{
  char	c;

  printf("arg->value %d\n", arg->value);
  c = arg->value;
  write(fd, &c, 1);
  return (0);
}

int	write_direct(t_arg *arg, int fd, t_label *label)
{
  int	new_endian;

  printf("je suis un direct\n");
  printf("arg->link_name %s\n", arg->link_name);
  if (arg->link_name != NULL)
    {
      printf("j'ai un label %s\n", arg->link_name);
      if ((new_endian =
	   find_label(label, arg->link_name, arg->pos_link)) == -1)
	return (1);
      printf("label->pos %d\n", new_endian);
      new_endian = change_endian(new_endian);
      printf("label->pos %d\n", new_endian);
      write(fd, &new_endian, 4);
    }
  else
    {
      new_endian = change_endian(arg->value);
      write (fd, &new_endian, 4);
    }
  return (0);
}

int	write_odds(t_arg *arg, int fd, t_label *label)
{
  int	new_endian;

  printf("je suis un direct\n");
  printf("arg->link_name %s\n", arg->link_name);
  if (arg->link_name != NULL)
    {
      printf("j'ai un label %s\n", arg->link_name);
      if ((new_endian =
	   find_label_short(label, arg->link_name, arg->pos_link)) == -1)
	return (1);
      printf("label->pos %d\n", new_endian);
      new_endian = (arg->value>>8) | (arg->value<<8);
      printf("label->pos %d\n", new_endian);
      write(fd, &new_endian, 2);
    }
  else
    {
      new_endian = (arg->value>>8) | (arg->value<<8);
      write (fd, &new_endian, 2);
    }
  return (0);
}

int	write_indirects(t_arg *arg, int fd)
{
  short	new_endian;

  new_endian = change_endian(arg->value);
  write(fd, &new_endian, 2);
  return (0);
}
