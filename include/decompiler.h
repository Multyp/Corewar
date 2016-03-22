/*
** decompiler.h for decompiler in /home/arnaud_e/rendu/cpe/corewar/include
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Mar  1 15:29:29 2016 Arthur ARNAUD
** Last update Tue Mar 22 16:34:49 2016 Arthur ARNAUD
*/

#ifndef _DECOMPILER_H_
# define _DECOMPILER_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define COMMENT_CHAR "#"
# define LABEL_CHAR ":"
# define DIRECT_CHAR "%"
# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_012345678"
# define NAME_CMD_STRING ".name"
# define COMMENT_CMD_STRING ".comment"
# define REG_NUMBER 16
# define REG_SIZE 1
# define IND_SIZE 2
# define DIR_SIZE 4
# define PROG_NAME_SIZE 128
# define COMMENT_LENGTH 2048

typedef struct	s_header
{
  int		magic_number;
  char		name[PROG_NAME_SIZE + 1];
  int		prog_size;
  char		comment[COMMENT_LENGTH + 1];
}		t_header;

typedef int	(*ftab)(int, int);

/*
** ==========================================
**                    ALGO
** ==========================================
*/
int		print_header(int, t_header *header);
int		check_codage(unsigned char *, int);
int		fill_file(int, int, ftab *);
ftab		*set_ftab(ftab *);
unsigned int	convert_to_nb(unsigned char *str, int size);
char		*new_name(char *);
/*
** ==========================================
**                 INSTRUCTIONS
** ==========================================
*/
int	op_live(int, int);
int	op_ld(int, int);
int	op_st(int, int);
int	op_add(int, int);
int	op_sub(int, int);
int	op_and(int, int);
int	op_or(int, int);
int	op_xor(int, int);
int	op_zjmp(int, int);
int	op_ldi(int, int);
int	op_sti(int, int);
int	op_fork(int, int);
int	op_lld(int, int);
int	op_lldi(int, int);
int	op_lfork(int, int);
int	op_aff(int, int);

/*
** ==========================================
**                    TOOLS
** ==========================================
*/
int	my_memset(void *, char, int);
void	my_putchar_file(char, int);
void	my_putnbr_file(int, int);
int	my_putstr_instruct(char *, int);
int	my_putstr_file(char *, int);
int	my_strlen(char *str);
#endif /* !_DECOMPILER_H_ */
