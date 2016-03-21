/*
** my_printf.c for printf in /home/da-fon_s/rendu
** 
** Made by samuel da-fonseca
** Login   <da-fon_s@epitech.net>
** 
** Started on  Thu Jan 28 21:55:39 2016 samuel da-fonseca
** Last update Fri Jan 29 09:57:00 2016 samuel da-fonseca
*/

#include "libmy.h"

void	charac(va_list ap)
{
  my_putchar(va_arg(ap, int));
}

void	string(va_list ap)
{
  char  *string;

  string = va_arg(ap, char *);
  if (string == NULL)
    my_putstr("(null)");
  else
    my_putstr(string);
}

void	nb(va_list ap)
{
  my_putnbr(va_arg(ap, int));
}

int	checkformat(char c, va_list ap)
{
  int   x;
  char  *flag;
  void  (*ptr[4])(va_list);

  flag = "csd";
  ptr[0] = &charac;
  ptr[1] = &string;
  ptr[2] = &nb;
  ptr[3] = NULL;
  x = 0;
  while (flag[x] != c && x < 4)
    x = x + 1;
  if (x == 4)
    return (1);
  ptr[x](ap);
  return (0);
}

void		my_printf(char *format, ...)
{
  int           i;
  va_list       ap;
  int		size;

  i = 0;
  size = my_strlen(format);
  va_start(ap, format);
  while (i != size)
    {
      if (format[i] == '%')
        {
	  i = i + 1;
	  if (format[i] && checkformat(format[i], ap) == 1)
	    my_error("Invalid format");
        }
      else
        my_putchar(format[i]);
      i = i + 1;
    }
  va_end(ap);
}
