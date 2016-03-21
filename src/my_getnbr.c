/*
** my_getnbr.c for my_getnbr_tetris in /home/marwane-khsime/rendu/Projets/PSU/PSU_2015_tetris/src
**
** Made by khsime_m
** Login   <khsime_m@epitech.net>
**
** Started on  Tue Feb 23 09:32:49 2016 khsime_m
** Last update Wed Feb 24 02:55:22 2016 khsime_m
*/

#include "vm_corewar.h"

int	my_getneg(char *str, int i, int nb)
{
  int	m;

  while (str[i] == '-')
    {
      i++;
      if (str[i] == '\0')
	return (0);
    }
  if (i % 2 == 1)
    m = -1;
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
      nb = (nb * 10) + (str[i] - 48);
      i++;
    }
  nb = nb * m;
  return (nb);
}

int	my_getnbr(char *str)
{
  int	nb;
  int	i;

  i = 0;
  nb = 0;
  if (!str)
    return (0);
  if (str[0] == '-')
    {
      nb = my_getneg(str, i ,nb);
      return (nb);
    }
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
      nb = (nb * 10) + (str[i] - 48);
      i++;
      if (str[i] == '\0')
	return (nb);
    }
  return (nb);
}
