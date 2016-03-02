/*
** decompiler.h for decompiler in /home/arnaud_e/rendu/cpe/corewar/include
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Mar  1 15:29:29 2016 Arthur ARNAUD
** Last update Wed Mar  2 11:17:54 2016 Arthur ARNAUD
*/

#ifndef _DECOMPILER_H_
# define _DECOMPILER_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

#ifndef COMMENT_CHAR
# define COMMENT_CHAR '#'
#endif /* !COMMENT_CHAR */

#ifndef LABEL_CHAR
# define LABEL_CHAR ':'
#endif /* !LABEL_CHAR */

#ifndef DIRECT_CHAR
# define DIRECT_CHAR '%'
#endif /* !DIRECT_CHAR */

#ifndef SEPARATOR_CHAR
# define SEPARATOR_CHAR ','
#endif /* !SEPARATOR_CHAR */

#ifndef LABEL_CHARS
# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_012345678"
#endif /* !LABEL_CHARS */

#ifndef NAME_CMD_STRING
# define NAME_CMD_STRING ".name"
#endif /* !NAME_CMD_STRING */

#ifndef COMMENT_CMD_STRING
# define COMMENT_CMD_STRING ".comment"
#endif /* !COMMENT_CMD_STRING */

#ifndef REG_NUMBER
# define REG_NUMBER 16
#endif /* !REG_NUMBER */

#ifndef REG_SIZE
# define REG_SIZE 1
#endif /* !REG_SIZE */

#ifndef IND_SIZE
# define IND_SIZE 2
#endif /* !IND_SIZE */

#ifndef DIR_SIZE
# define DIR_SIZE 4
#endif /* !DIR_SIZE */

#ifndef PROG_NAME_SIZE
# define PROG_NAME_SIZE 128
#endif /* !PROG_NAME_SIZE */

#ifndef COMMENT_LENGTH
# define COMMENT_LENGTH 2048
#endif /* !COMMENT_LENGTH */

typedef struct	s_header
{
  int		magic_number;
  char		name[PROG_NAME_SIZE + 1];
  int		prog_size;
  char		comment[COMMENT_LENGTH + 1];
}		t_header;

typedef char **(**ftab)(int, int);

int	print_header(int, int);
int	check_codage(unsigned char *, int);
void	my_putchar_file(char, int);
void	my_putnbr_file(int, int);
int	my_putstr_instruct(char *, int);
int	my_putstr_file(char *, int);
int	fill_file(int, int, ftab);
int	op_live(int, int);
int	op_sti(int, int);
ftab	*set_ftab(ftab *);
void	my_memset(void *, char, int);

#endif /* !_DECOMPILER_H_ */
