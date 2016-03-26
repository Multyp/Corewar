/*
** asm.h for asm in /home/arnaud_e/rendu/cpe/corewar/include
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 00:09:32 2016 Arthur ARNAUD
** Last update Sat Mar 26 01:18:48 2016 Arthur ARNAUD
*/

#ifndef ASM_H_
# define ASM_H_

# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define COMMENT_CHAR '#'
# define LABEL_CHAR ':'
# define DIRECT_CHAR '%'
# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING ".name"
# define COMMENT_CMD_STRING ".comment"
# define REG_NUMBER 16
# define REG_SIZE 1
# define IND_SIZE 2
# define DIR_SIZE 4
# define PROG_NAME_SIZE 128
# define COMMENT_LENGTH 2048

typedef struct		s_header
{
  int	magic;
  char	prog_name[PROG_NAME_SIZE + 1];
  int	prog_size;
  char	comment[COMMENT_LENGTH + 1];
  int	full;
}			t_header;

typedef struct		s_pos
{
  int	prog_size;
  int	line;
}			t_pos;

typedef struct		s_arg
{
  char			type;
  char			*link_name;
  int			pos_link;
  int			value;
}			t_arg;

typedef struct		s_label
{
  char			*name;
  int			pos;
  struct s_label	*next;
}			t_label;

typedef struct		s_file
{
  char			*str;
  struct s_file		*next;
}			t_file;

typedef struct		s_action
{
  int			coding_byte;
  char			identifier;
  char			*instruction;
  t_arg			**args;
  struct s_action	*next;
}			t_action;

typedef int	(*t_ftab)(t_action *, char *, t_pos *);

/*
** ================================
**              INIT
** ================================
*/
t_label		*create_label_list();
t_action       	*create_action_list();
t_file		*create_file_list();
t_ftab		*set_ftab(t_ftab *);

/*
** ================================
**              LEXER
** ================================
*/
char		check_type(char *, t_pos *);
char		*add_to_label(char *, int, t_label *, int);
char		*check_label(char *, t_label *, t_pos *);
char		*format_instruction(char *);
char		**cut_instruction(char *);
int		add_action(t_action *, t_action *);
int		add_label(t_label *, t_label *);
int		add_to_back(t_file *, char *);
int		check_action(char *, t_action *, t_pos *, t_ftab *);
int		check_args(char, char *, t_pos *);
int		fill_arg(char, char *, t_arg *, t_pos *);
int		get_header(char *, t_header *);
int		icubed(char *, char);
int		init_args(t_action *, int);
int		is_valid_label(char *, int);
int		is_char_valid(char, char *);
int		lexer(t_label *, t_action *, t_header *, int);
int		print_error(char *, int, int);
void		add_prog_size(char, t_pos *);
int		change_to_odds(t_arg *, char *);
/*
** ================================
**              LIB
** ================================
*/
char		**str_to_word_tab(char *,  char);
char		*epur_str(char *);
char		*get_line_not_empty(int, int *);
char		*get_next_line(int);
char		*my_strdup(char *);
int		change_endian(int);
int		check_empty(char *);
int		my_getnbr(char *);
int		my_memset(void *, char , int);
int		my_putstr(char *);
int		my_strlen(char *);
int		my_strcpy(char *, char *);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
void		my_strcat(char *, char *);
void		*free_first(t_file *);
void		free_tab(char **);
void		my_putnbr(int);
void		showtab(char **);

/*
** ================================
**             PARSER
** ================================
*/
int		parser(t_label *, t_action *, t_header *, char *);
int		write_action(t_action *, int, t_label *);
int		write_header(t_header *, char *);
int		write_registers(t_arg *, int);
int		write_direct(t_arg *, int, t_label *);
int		write_odds(t_arg *, int, t_label *);
int		write_indirects(t_arg *, int);

/*
** ================================
**        FUNCTION_POINTER
** ================================
*/
int    		op_live(t_action *, char *, t_pos *);
int		op_ld(t_action *, char *, t_pos *);
int		op_st(t_action *, char *, t_pos *);
int		op_add(t_action *, char *, t_pos *);
int		op_sub(t_action *, char *, t_pos *);
int		op_and(t_action *, char *, t_pos *);
int		op_or(t_action *, char *, t_pos *);
int		op_xor(t_action *, char *, t_pos *);
int		op_zjmp(t_action *, char *, t_pos *);
int		op_ldi(t_action *, char *, t_pos *);
int		op_sti(t_action *, char *, t_pos *);
int		op_fork(t_action *, char *, t_pos *);
int		op_lld(t_action *, char *, t_pos *);
int		op_lldi(t_action *, char *, t_pos *);
int		op_lfork(t_action *, char *, t_pos *);
int		op_aff(t_action *, char *, t_pos *);

#endif /* !ASM_H_*/
