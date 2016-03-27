/*
** change_endian.c for change_endian in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sun Mar 27 00:46:24 2016 Marwane
** Last update Sun Mar 27 00:46:25 2016 Marwane
*/

int	change_endian(int nb)
{
  int	res;
  int	one;
  int	two;
  int	three;
  int	four;

  one = (nb & 0x000000ff) << 24u;
  two = (nb & 0x0000ff00) << 8u;
  three = (nb & 0x00ff0000) >> 8u;
  four = (nb & 0xff000000) >> 24u;
  res = one | two | three | four;
  return (res);
}
