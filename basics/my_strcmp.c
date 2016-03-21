/*
** my_strcmp.c for  in /home/da-fon_s/lib
**
** Made by samuel da-fonseca
** Login   <da-fon_s@epitech.net>
**
** Started on  Thu Jan 28 19:28:13 2016 samuel da-fonseca
** Last update Sun Mar 20 14:35:22 2016 marwane khsime
*/

#include "libmy.h"

int	my_strcmp2(char *s1, char *s2, int opt)
{
  char	*str;
  int	n;

  n = 0;
  str = my_strdup(s1);
  while (str && str[n] && str[n++] != '=');
  if (n > 0 && str[n - 1] == '=' && str[n])
    {
      str = my_realloc(str, n);
      if (my_strseek(s2, str, 0) == 1 &&
	  (opt != 19 || (my_checkstr(s1, ',') == my_checkstr(s2, ','))))
	{
	  free (str);
	  return (0);
	}
    }
  free(str);
  return (1);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1 && s2 && s1[i] && s2[i])
    {
      if (s1[i] > s2[i])
        return (1);
      if (s1[i] < s2[i])
        return (-1);
      i++;
    }
  if (s1[i] == '\0' && s1[i] != s2[i])
    return (-1);
  if (s2[i] == '\0' && s1[i] != s2[i])
    return (1);
  return (0);
}

int	my_strcncmp(char *s1, char *s2, int n)
{
 int	i;

  i = 0;
  while (s1 && s2 && s1[i] && s2[i] && i < n)
    {
      if (s1[i] > s2[i])
	return (1);
      if (s1[i] < s2[i])
	return (-1);
      i++;
    }
  return (0);
}
