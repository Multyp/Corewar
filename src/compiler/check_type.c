/*
** check_type.c for cehck_type in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 22 17:19:48 2016 Poc
** Last update Tue Mar 22 19:05:16 2016 Poc
*/

#include "asm.h"

int	check_percent(char *str)
{
  int	i;

  i = 2;
  if (str[1] == ':')
    while (str[i])
      {
	i++;
      }
}

int	check_registery(char *str)
{
  int	i;

  i = 1;
  while (str[i])
    {
      if (str[i] > 9 && str[i] < 0)
	{
	  printf("wrong registery\n");
	  return (1);
	}
      i++;
    }
  if (atoi(str + 1) > REG_NUMBER)
    {
      return (1);
      printf("wrong_reg_nbr\n");
    }
  return (0);
}

int	check_type(char *str, t_pos *pos)
{
  printf("CHECK_TYPE -> str = %s\n", str);
  if (str[0] == 'r')
    if (check_registery(str) == 0)
      {
	printf("good\n");
	return (1);
      }
  if (str[0] == '%')
    check_percent(str);
    printf("wrong\n");
  return (-1);
}
