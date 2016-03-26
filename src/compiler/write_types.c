/*
** write_types.c for write types in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 24 17:50:43 2016 Poc
** Last update Sat Mar 26 12:44:25 2016 Poc
*/

#include "asm.h"

short	find_label_short(t_label *label, char *name, int pos)
{
  int	i;

  if (label->name == NULL || name == NULL)
    {
      printf("FIND_LABEL_SHORT---Returning at TOP...\n");
      return (-1);
    }
  while (label && my_strcmp(label->name, name) != 0)
    {
      label = label->next;
    }
  if (label)
    {
      printf("FIND_LABEL_SHORT---label->name %s\n", label->name);
      printf("FIND_LABEL_SHORT---find_label->pos %d && label->pos%d\n", pos, label->pos);
    }
  if (label && pos >= label->pos)
    {
      i = 0xFFFF;
      printf("FIND_LABEL_SHORT---i - pos + 2 %d\n", label->pos - pos);
      return (i - pos);
    }
  if (label != NULL)
    {
      printf("FIND_LABEL_SHORT---label->pos - pos %d\n", label->pos - pos);
      return (label->pos - pos + 1);
    }
  else
    {
      printf("FIND_LABEL_SHORT---Returning at BOT...\n");
      return (-1);
    }
}

int	find_label(t_label *label, char *name, int pos)
{
  int	i;

  printf("FIND_LABEL---label->name %s\nname %s\n", label->name, name);
  if (label->name == NULL || name == NULL)
    {
      printf("FIND_LABEL---label->name || name\n");
      return (-1);
    }
  while (label && my_strcmp(label->name, name) != 0)
    {
      label = label->next;
    }
  if (label && pos > label->pos)
    {
      i = 0xFFFFFFFF;
      printf("FIND_LABEL---Returning i - pos + 2 = %x\n", i - pos + 2);
      return (i - pos);
    }
  if (label)
    {
      printf("FIND_LABEL---Returning label->pos - pos - 1 = %x\n", label->pos- pos - 1);
      return (label->pos - pos);
    }
  else
    {
      printf("FIND_LABEL---Returning BOT...\n");
      return (-1);
    }
}

int	write_registers(t_arg *arg, int fd)
{
  char	c;

  printf("WRITE_REGISTERS---arg->value %d\n", arg->value);
  c = arg->value;
  write(fd, &c, 1);
  return (0);
}

int	write_direct(t_arg *arg, int fd, t_label *label)
{
  int	new_endian;

  printf("WRITE_DIRECT---je suis un direct\n");
  printf("WRITE_DIRECT---arg->link_name %s\n", arg->link_name);
  if (arg->link_name != NULL)
    {
      printf("WRITE_DIRECT---j'ai un label %s\n", arg->link_name);
      if ((new_endian =
	   find_label(label, arg->link_name, arg->pos_link)) == -1)
	{
	  printf("WRITE_DIRECT---I just broke sadface\n");
	  return (1);
	}
      printf("WRITE_DIRECT---label->pos %x\n", new_endian);
      new_endian = change_endian(new_endian);
      printf("WRITE_DIRECT---label->pos %x\n", new_endian);
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
  short	new_endian;
  short	tmp;

  printf("WRITE_ODDS---je suis un odd\n");
  printf("WRITE_ODDS---arg->link_name %s\n", arg->link_name);
  if (arg->link_name != NULL)
    {
      printf("WRITE_ODDS---j'ai un label %s\n", arg->link_name);
      if ((tmp =
	   find_label_short(label, arg->link_name, arg->pos_link)) == -1)
	{
	  printf("WRITE_ODDS---Returning...\n");
	  return (1);
	}
      new_endian = ((tmp>>8) | (tmp<<8));
      printf("WRITE_ODDS---label->pos %d\n", new_endian);
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
