/*
** free_tab.c for freetab in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Mar 21 22:05:33 2016 Poc
** Last update Mon Mar 21 22:08:49 2016 Poc
*/

#include "asm.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab[i]);
  free(tab);
}
