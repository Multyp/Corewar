/*
** vm_corewar.h for vm_corewar in /home/khsime_m/rendu/projets/CPE/vm_corewar/include
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 04:08:19 2016 Marwane
** Last update Sat Mar 26 05:39:53 2016 Marwane
*/

#ifndef __VM_COREWAR_H__
#define __VM_COREWAR_H__

# include <stdio.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libmy.h"

/*
** Errors
*/
# define MALLOC_FAILED "Error: Malloc Failed"
# define INVALID_OPTION "Error: Invalid option, try to use --help"
# define OPEN_FAILED(file_name) "Error: Could not open file "#file_name
# define INVALID_FILE(file_name) "Error: "#file_name" is not a corewar executable"
# define USED_PROGNUMBER(x) "Error: Prog number "#x" already used"
# define PLAYER_ALIVE(player_name) "Player "#player_name" is alive"
# define PLAYER_WIN(winner_name) "Player "#winner_name" wins"


# define NAME_SIZE 128
# define COMMENT_SIZE 2048
# define MEM_SIZE (6 * 1024)
# define MAX_ARGS_NUMBER 6

/*
** regs
*/
#define REG_NUMBER      16              /* r1 <--> rx */

/*
**
*/
#define T_REG           1       /* registre */
#define T_DIR           2       /* directe  (ld  #1,r1  met 1 dans r1) */
#define T_IND           4       /* indirecte toujours relatif
                                   ( ld 1,r1 met ce qu'il y a l'adress (1+pc)
                                   dans r1 (4 octecs )) */
#define T_LAB           8       /* LABEL */

/*
** size
*/
#define IND_SIZE        2               /* en octet */
#define REG_SIZE        4               /* en octet */
#define DIR_SIZE        REG_SIZE        /* en octet */

/*
** live
*/
#define CYCLE_TO_DIE    1536    /* nombre de cycle pour etre d\'eclarer mort */
#define CYCLE_DELTA     5
#define NBR_LIVE        40

typedef struct		s_prog
{
  int			prog_number;
  int			address;
  int			original;
  char			*prog_name;
  struct s_prog		*next;
}			t_prog;

typedef struct		s_champ
{
  int			magic;
  char			name[NAME_SIZE + 1];
  int			size;
  int			pc;
  char			comment[COMMENT_SIZE + 1];
  struct s_champ	*next;
}			t_champ;

typedef struct		s_vm
{
  char			arena[MEM_SIZE + 1];
  int			arena_check[MEM_SIZE];
  bool			file_opts[2];
  t_prog		*progs;
  t_champ		*champs;
  int			progs_nb;
  int			dump;
  int			cycle_die;
  int			nbr_live;
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
t_vm	*add_champ_to_list(t_vm *, char *, int);

/*
** Checks for options
*/
int	check_list_for_address(t_vm *, int);
int	check_list_for_prognb(t_vm *, int);
int	check_champs_sizes(t_vm *vm);

/*
** ***********
** * OPTIONS *
** ***********
**
**
** Parsing
*/
int	check_options(char **, t_vm *, int);
int	convert_to_little_endian(int);
char	*get_binary(char *);
void	file_arena(t_vm *vm);
void	file_arena_check(t_vm *vm);

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
void	init_progaddress(t_vm *);

/*
** *********
** * Frees *
** *********
*/
void	my_freeprog(t_prog *);

# endif /* _VM_COREWAR_H__ */
