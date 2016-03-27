/*
** vm_corewar.h for vm_corewar in /home/khsime_m/rendu/projets/CPE/vm_corewar/include
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 04:08:19 2016 Marwane
** Last update Sun Mar 27 16:00:00 2016 Da Fonseca Samuel
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
# define MALLOC_FAILED	"Error: Malloc Failed"
# define INVALID_OPTION "Error: Invalid option, try to use --help"
# define OPEN_FAILED "Error: Could not open file "
# define INVALID_FILE(file) "Error: "#file" is not a corewar executable"
# define USED_PROGNUMBER(x) "Error: Prog number "#x" already used"
# define PLAYER_ALIVE(player_name) "Player "#player_name" is alive"
# define PLAYER_WIN(winner_name) "Player "#winner_name" wins"
# define INVALID_NUMBER "Error: Invalid number. Option ignored."

# define NAME_SIZE 128
# define COMMENT_SIZE 2048
# define MEM_SIZE (6 * 1024)
# define IDX_MOD 512
# define MAX_ARGS_NUMBER 4

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
  char			comment[COMMENT_SIZE + 1];
  bool			alive;
  int			pc;
  int			cycles_to_wait;
  int			carry;
  int			registres[16];
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
  int			cycle;
  int			live_calls;
}			t_vm;

/*
**
**  VM
**
**/
void	game_check_steps(t_vm *);
void	put_memory_hexa_format(char *arena);
void	aff_winner(t_vm *);

/*
** ********
** * INIT *
** ********
*/
t_vm	*init_vm(t_vm *);
int	init_opeparams(t_vm *, t_champ *, int, int *);
int	init_stiopeparams(t_vm *, t_champ *, int, short *);

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
void	pc_correction(t_vm *);
t_vm	*add_champ_to_list(t_vm *, char *, int, int);

/*
** Checks for options
*/
int	check_list_for_address(t_vm *, int);
int	check_list_for_prognb(t_vm *, int);
int	check_champs_sizes(t_vm *);

/*
** ***********
** * OPTIONS *
** ***********
**
**
** Parsing
**
*/
int	check_options(char **, t_vm *, int);
int	convert_to_little_endian(int);
int	change_endian(int nb);
char	*get_binary(char *);
void	file_arena(t_vm *);
void	file_arena_check(t_vm *);


/*
** Main_functions
*/
void	main_loop(t_vm *);
int	get_octet_code(int, int, char);
int	get_size_octet_code(unsigned char);
int	get_myint(t_vm *, int, int);
int	get_size(int);
int	get_spesize(int);

/*
** Functions
*/
void	functions_vm(t_vm *, t_champ *, int);
int	live_function(t_vm *, t_champ *);
int	ld_function(t_vm *, t_champ *);
int	st_function(t_vm *, t_champ *);
int	add_function(t_vm *, t_champ *);
int	sub_function(t_vm *, t_champ *);
int	and_function(t_vm *, t_champ *);
int	or_function(t_vm *, t_champ *);
int	xor_function(t_vm *, t_champ *);
int	zjmp_function(t_vm *, t_champ *);
int	ldi_function(t_vm *, t_champ *);
int	sti_function(t_vm *, t_champ *);
int	fork_function(t_vm *, t_champ *);
int	lld_function(t_vm *, t_champ *);
int	lldi_function(t_vm *, t_champ *);
int	lfork_function(t_vm *, t_champ *);
int	aff_function(t_vm *, t_champ *);

/*
** CHECK
*/
int	check_addoctet(int octet[]);
int	check_oroctet(int octet[]);
int	check_andoctet(int octet[]);
int	check_ldoctet(int octet[]);
int	check_ldioctet(int octet[]);

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
int	default_addr(t_vm *);
/*
** Sorting
*/
int	*check_spaces_with_progs(t_vm *);
int	*tabcpy(int *, int *);
int	get_sizetoload(int *);
int	get_sizefree(int *);
int	get_addr(int *, int);
int	get_nbtab(int *);
/*
** *********
** * Frees *
** *********
*/
void	my_freeprog(t_prog *);

# endif /* _VM_COREWAR_H__ */
