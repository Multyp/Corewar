/*
** my_strcmp.c for my_strcmp in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Mar 21 21:30:45 2016 Poc
** Last update Mon Mar 21 21:44:11 2016 Poc
*/

int	my_strcmp(char *str, char *str2)
{
  int	i;

  i = 0;
  while (str[i] && str2[i] && str[i] == str2[i])
    i++;
  return (str[i] - str2[i]);
}
