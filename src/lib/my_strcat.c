/*
** my_strcat.c for my_strcat in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 24 13:23:58 2016 Poc
** Last update Thu Mar 24 13:28:49 2016 Poc
*/

void	my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i])
    i++;
  while (src[j])
    dest[i++] = src[j++];
  dest[i] = 0;
}
