#ifndef __VM_COREWAR_H__
#define __VM_COREWAR_H__

# include <stdio.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libmy.h"

# define MALLOC_FAILED "Error: Malloc Failed"
# define INVALID_OPTION "Error: Invalid option, try to use --help"
# define OPEN_FAILED(file_name) "Error: Could not open file "#file_name
# define INVALID_FILE(file_name) "Error: "#file_name" is not a corewar executable"
# define USED_PROGNUMBER(x) "Error: Prog number "#x" already used"
# define PLAYER_ALIVE(player_name) "Player "#player_name" is alive"
# define PLAYER_WIN(winner_name) "Player "#winner_name" wins"
# define NAME_BLOC 129
# define COMMENT_BLOC 2049

typedef struct		s_prog
{
  int			prog_number;
  unsigned int		address;
  char			*prog_name;
  struct s_prog		*next;
}			t_prog;

typedef struct		s_champ
{
  int			magic;
  char			name[NAME_BLOC];
  int			size;
  char			comment[COMMENT_BLOC];
  struct s_champ	*next;
}			t_champ;

typedef struct		s_vm
{
  int			dump;
  bool			file_opts[2];
  int			progs_nb;
  t_prog		*progs;
  t_champ		*champs;
}			t_vm;

/*
** ********
** * INIT *
** ********
*/
t_vm	*init_vm(t_vm *);

/*
** *****************
** * LIST MANAGING *
** *****************
*/
t_vm	*add_prog(t_vm *, char *);
void	*add_champions(t_vm *);
void	check_champs_error(t_vm *);
void	del_prog(t_vm *, int);
void	del_champ(t_vm *, int);
t_vm	*add_champ_to_list(t_vm *, char *);

/*
** Checks for options
*/
int	check_list_for_address(t_vm *, unsigned int);
int	check_list_for_prognb(t_vm *, int);

/*
** ***********
** * OPTIONS *
** ***********
*/
/*
** Parsing
*/
int	check_options(char **, t_vm *, int);
int	convert_to_little_endian(int);
char	*get_binary(char *);
/*
** Commands
*/
int	show_help(t_vm *, char *, char *);
int	my_dump_memory(t_vm *, char *, char *);
int	my_load_address(t_vm *, char *, char *);
int	my_get_prognumber(t_vm *, char *, char *);
int	check_file(t_vm *, char *, char *);
/*
** Init default values
*/
void	init_defaultvalues(t_vm *);

/*
** *********
** * Frees *
** *********
*/
void	my_freeprog(t_prog *);

# endif /* _VM_COREWAR_H__ */
