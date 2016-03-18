/*
** format_string.c for string in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Fri Mar 18 17:22:19 2016 Clement Peau
** Last update Fri Mar 18 17:35:58 2016 Clement Peau
*/

char	*format_string(char *str)
{
  char	*new_str;
  int	i;
  int	k;

  i = 0;
  k = 0;
  ((new_str = malloc(my_strlen(str))) == NULL)
    return (NULL);
  while (str[i] != 32)
    new_str[k++] = str[i++];
}
