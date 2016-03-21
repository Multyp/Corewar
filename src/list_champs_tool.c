#include "vm_corewar.h"

int		file_champion_tool_for_magic_nb(char *str)
{
  int		i;

  i = 0;
  while (i < 4)
    {
      if (str[i] != '\0')
	return (i);
      i++;
    }
  return (-1);
}

int		file_champion(t_champ *champ, char *filepath)
{
  int		fd;
  int		readed;
  char		buffer[2184]

  if ((fd = open(file_path, O_RDONLY)) == -1)
    return (-1);
  if ((readed = read(fd, buffer, 4)) < 4)
    return (-1);
  if ((readed = file_champion_tool_for_magic_nb(buffer)) == -1)
    return (-1);
  champ.magic = my_getnbr(&buffer[readed]);
  printf("magic = %d\n", champ.magic);
  my_memset(buffer, 0, 4);
  if ((readed = read(fd, buffer, 128)) < 128)
    return (-1);
  champ.name = my_strncpy(champ.name, buffer, 129);
  printf("name = %s\n", champ.name);
  my_memset(buffer, 0, 128);
  if ((readed = read(fd, buffer, 4)) < 4)
    return (-1);
  if ((readed = file_champion_tool_for_magic_nb(buffer)) == -1)
    return (-1);
  champ.size = my_getnbr(&buffer[readed]);
  my_memset(buffer, 0, 4);
  if ((readed = read(fd, buffer, 2048)) < 2048)
    return (-1);
  champ.comment = my_strncopy(champ.comment, 2049);
  return (0);
}

/*
**   add_champt_to_list prend en paramètre un champion (vide et non malloc)
**   le path du champion, et le rempli.
*/
void		add_champ_to_list(t_champ *champ, char *file_path)
{
  if ((champ = malloc(sizeof(t_champ))) == NULL)
    return (NULL);
  if (file_champion(champ, file_path) == -1)
    return (NULL);
}
