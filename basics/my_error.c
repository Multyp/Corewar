/*
** my_puterror.c for error in /home/da-fon_s/lib
** 
** Made by samuel da-fonseca
** Login   <da-fon_s@epitech.net>
** 
** Started on  Thu Jan 28 22:05:07 2016 samuel da-fonseca
** Last update Fri Jan 29 09:56:14 2016 samuel da-fonseca
*/

#include "libmy.h"

int	my_error(char *error)
{
  int	n;

  if (error)
    {
      n = my_strlen(error);
      write(2, error, n);
      write(2, "\n", 1);
    }
  return (1);
}

void	*my_perror(char *error)
{

  int	n;

  if (error)
    {
      n = my_strlen(error);
      write(2, error, n);
      write(2, "\n", 1);
    }
  return (NULL);
}
