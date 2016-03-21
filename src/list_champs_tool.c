#include "vm_corewar.h"

int		file_champion(t_champ *champ, char *file_path)
{
  int		fd;

  if ((fd = open(file_path, O_RDONLY)) == -1)
    return (-1);
  if (read(fd, champ, (int)sizeof(t_champ)) < (int)sizeof(t_champ))
    return (-1);
  champ->magic = convert_to_little_endian(champ->magic);
  champ->size = convert_to_little_endian(champ->size);
  return (0);
}

/*
**   add_champt_to_list prend en paramètre un champion (vide et non malloc)
**   le path du champion, et le rempli.
*/
t_champ		*add_champ_to_list(t_champ *champ, char *file_path)
{
  if ((champ = malloc(sizeof(t_champ))) == NULL)
    return (NULL);
  if (file_champion(champ, file_path) == -1)
    return (NULL);
  return (champ);
}
