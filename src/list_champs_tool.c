#include "vm_corewar.h"

/*
**  file_champion lis les 2184 octets contenu dans un fichier et remplis
**  dans champ (cf structure : include/vm_corewar.h") toutes les informations
**  contenu dans celui ci sur les 2184 octets.
*/
int		file_champion(t_champ *champ, char *file_path)
{
  int		fd;

  if ((fd = open(file_path, O_RDONLY)) == -1)
    return (-1);
  if (read(fd, champ, (int)sizeof(t_champ)) < (int)sizeof(t_champ))
    {
      my_memset((char *)champ->name, 0, 10);
      champ->magic = -1;
      champ->size = -1;
      my_memset((char *)champ->comment, 0, 10);
      return (0);
    };
  champ->magic = convert_to_little_endian(champ->magic);
  champ->size = convert_to_little_endian(champ->size);
  return (0);
}

/*
**   add_champt_to_list prend en paramètre un champion (vide et non malloc)
**   le path du champion, et le rempli.
*/
t_vm		*add_champ_to_list(t_vm *vm, char *file_path)
{
  t_champ	*tmp_champ;
  int		i = 0;

  tmp_champ = vm->champs;
  while (vm->champs != NULL)
    {
      printf("name = %s\n", vm->champs->name);
      vm->champs = vm->champs->next;
      printf("i = %d\n", ++i);
    }
  if ((vm->champs = malloc(sizeof(t_champ))) == NULL)
    return (my_perror(MALLOC_FAILED));
  if (file_champion(vm->champs, file_path) == -1)
    return ((free(vm->champs)), (vm->champs = NULL), NULL);
  vm->champs->next = NULL;
  vm->champs = tmp_champ;
  printf("[OK]\n");
  return (vm);
}

/*
**  add_champion ajoute tous les programmes contenu dans t_prog dans la
**  liste chainee t_champ, add_champions ne corrige pas les erreurs des
**  progs (cf : check_champs_cors.c)
*/
void		*add_champions(t_vm *vm)
{
  t_prog	*tmp_progs;
  int		i;

  tmp_progs = vm->progs;
  i = 0;
  while (tmp_progs)
    {
      if (vm->champs == NULL)
	{
	  printf("first\n");
	  if ((vm = add_champ_to_list(vm, tmp_progs->prog_name)) == NULL)
	    return (NULL);
	}
      else
	if ((vm = add_champ_to_list(vm, tmp_progs->prog_name)) == NULL)
	  return (NULL);
      tmp_progs = tmp_progs->next;
      i++;
    }
  printf("nombre de progs = %d\n", i);
  return (vm);
}

/*
**  del_champ permet de supprimer un champion dans la liste chainée de champions
**  à la position i.
*/
void		del_champ(t_vm *vm, int i)
{
  t_champ	*tmp;

  tmp = vm->champs;
  if (i == 0)
    {
      vm->champs = vm->champs->next;
      free(tmp);
      return ;
    }
  while (i-- > 1)
    tmp = tmp->next;
  tmp->next = tmp->next->next;
  free(tmp->next);
  return ;
}
