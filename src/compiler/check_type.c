/*
** check_type.c for cehck_type in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 22 17:19:48 2016 Poc
** Last update Sun Mar 27 21:58:13 2016 Poc
*/

#include "asm.h"

int	check_direct(char *str, int *size)
{
  int	i;

  i = 0;
  if (str[i] == '-')
    i++;
  while (str[i])
    {
      if ((str[i] > '9' || str[i] < '0'))
	return (print_error("Direct must be an int\n", *size, 1));
      i++;
    }
  return (0);
}

int	check_percent(char *str, int *size)
{
  int	i;

  i = 1;
  if (str[0] == ':')
    while (str[i])
      {
	if (icubed(LABEL_CHARS, str[i]))
	  return (print_error("Invalid character\n", *size, 1));
	i++;
      }
  else
    if (check_direct(str, size))
	return (1);
  return (0);
}

int	check_registery(char *str, int *size)
{
  int	i;
  int	k;

  k = 0;
  i = 1;
  while (str[i])
    {
      if (str[i] > 9 && str[i] < 0)
	return (print_error("Number is required\n", *size, 1));
      i++;
    }
  if (my_getnbr(str, &k) > REG_NUMBER || k == -1)
    return (print_error("Direct too big\n", *size, 1));
  return (0);
}

int	is_it_an_int(char *str, int *size)
{
  int	i;

  i = 0;
  if (str[i] == '-')
    i++;
  while (str[i])
    {
      if (str[i] > '9' || str[i] < '0')
	return (print_error("Indirect must be a number\n", *size, 1));
      i++;
    }
  return (0);
}

char	check_type(char *str, t_pos *pos)
{
  if (str[0] == 'r')
    {
      if (check_registery(str, &pos->line))
	return (-1);
      else
	  return (1);
    }
  else if (str[0] == '%')
    {
      if (check_percent(str + 1, &pos->line) == 0)
      return (2);
    }
  else
    if (!is_it_an_int(str, &pos->line))
      return (3);
  return (-1);
}
