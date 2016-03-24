/*
** change_endian.c for change endian in /home/peau_c/rendu/CPE/CPE_2015_corewar
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 24 14:57:54 2016 Poc
** Last update Thu Mar 24 15:37:25 2016 Poc
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
