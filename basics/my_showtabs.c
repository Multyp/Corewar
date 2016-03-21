/*
** show_tabs.c for show_tabs in /home/da-fon_s/lib
** 
** Made by samuel da-fonseca
** Login   <da-fon_s@epitech.net>
** 
** Started on  Thu Jan 28 19:00:23 2016 samuel da-fonseca
** Last update Fri Jan 29 09:58:28 2016 samuel da-fonseca
*/

#include "libmy.h"

void	my_showitab(int **itab)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (itab && itab[i])
    {
      j = 0;
      while (itab[i][j] >= 0)
        {
          my_putnbr(itab[i][j]);
          j++;
	  if (itab[i][j] >= 0)
	    write(1, " ", 1);
        }
      write(1, "\n", 1);
      i++;
    }
}

int	my_intlen(int nb)
{
  int   i;

  i = 0;
  while (nb != 0)
    {
      nb = nb / 10;
      i = i + 1;
    }
  return (i);
}

int	my_tablen(char **tab)
{
  int   i;

  i = 0;
  while (tab && tab[i])
    i++;
  return (i);
}

void	my_showtab(char **tab)
{
  int   i;
  int   j;

  i = 0;
  while (tab && tab[i])
    {
      j = 0;
      while (tab[i] && tab[i][j])
        write(1, &tab[i][j++], 1);
      i++;
    }
  write(1, "\n", 1);
}
