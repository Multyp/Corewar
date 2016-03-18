/*
** get_header.c for getheader in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Mar 16 17:17:26 2016 Clement Peau
** Last update Fri Mar 18 17:08:47 2016 Clement Peau
*/

#include "asm.h"

int		get_name(t_header *header, char *str)
{
  int	i;
  int	k;

  k = 0;
  if (my_strncmp(str, ".name ", 6) == 0)
    return (1);
  i = 0;
  while (str[i++] != '"')
    if (str[i] == 0)
      return (1);
  k = i;
  while (str[i++] != '"')
    if (str[i] == 0)
      return (1);
  str[i - 1] = 0;
  my_strcpy(header->prog_name, str + k);
  return (0);
}

int		get_comment(t_header *header, char *str)
{
  int		i;
  int		k;

  if (my_strncmp(str, ".comment ", 9) == 0)
    return (0);
  i = 0;
  while (str[i++] != '"')
    if (str[i] == 0)
      {
	write(2, "Wrong comment format\n", 21);
	return (1);
      }
  k = i;
  while (str[i++] != '"')
    if (str[i] == 0)
      {
	write(2, "Wrong comment format\n", 21);
	return (1);
      }
  str[i - 1] = 0;
  my_strcpy(header->comment, str + k);
  return (0);
}

int		get_header(char *str, t_header *header)
{
  if (header->full == 1)
    return (0);
  if (get_name(header, str) == 1)
    return (1);
  printf("header->progname = |%s|\n", header->prog_name);
  if (get_comment(header, str) == 1)
    return (1);
  printf("header->comment = |%s|\n", header->comment);
  header->full = 1;
  return (0);
}
