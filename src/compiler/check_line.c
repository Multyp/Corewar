/*
** check_line.c for check_line in /home/arnaud_e/rendu/cpe/corewar/include
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Feb 29 11:47:09 2016 Arthur ARNAUD
** Last update Mon Feb 29 12:55:44 2016 Arthur ARNAUD
*/

int	check_line(char **tab, t_action *action, t_label *label, t_pos *pos)
{
  if (!(tab = check_label(tab, label, pos)))
    return (-1);

}
