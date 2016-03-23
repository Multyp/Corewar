/*
** check_type.c for cehck_type in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 22 17:19:48 2016 Poc
** Last update Wed Mar 23 01:37:14 2016 Poc
*/

#include "asm.h"

int	check_direct(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] > '9' || str[i] < '0')
	  return (1);
      i++;
    }
  return (0);
}


int	check_percent(char *str)
{
  int	i;

  i = 1;
  if (str[0] == ':')
    while (str[i])
      {
	if (icubed(LABEL_CHARS, str[i]))
	    return (1);
	i++;
      }
  else
    if (check_direct(str))
	return (1);
  return (0);
}

int	check_registery(char *str)
{
  int	i;

  i = 1;
  while (str[i])
    {
      if (str[i] > 9 && str[i] < 0)
	return (1);
      i++;
    }
  if (my_getnbr(str) > REG_NUMBER)
    return (1);
  return (0);
}

int	is_it_an_int(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] > '9' || str[i] < '0')
	return (1);
      i++;
    }
  return (0);
}

char	check_type(char *str, t_pos *pos)
{
  printf("CHECK_TYPE -> str = %s\n", str);
  if (str[0] == 'r')
    {
      if (check_registery(str) == 0)
	return (-1);
      else
	  return (1);
    }
  else if (str[0] == '%')
    {
      if (check_percent(str + 1) == 0)
      return (2);
    }
  else
    if (!is_it_an_int(str))
      return (3);
  printf("je return -1\n");
  return (-1);
}
