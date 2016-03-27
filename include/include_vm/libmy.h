
#ifndef __LIBMY_H__
#define __LIBMY_H__

/*
** °---------------------°
** | LIB C BY da-fon_s:  |
** | BASICS              |
** °---------------------°
*/
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/*
** °--------°
** | BASICS |
** °--------°
*/
/*
** REVERSE THE STRING GIVEN AS PARAMETER
*/
char	*my_revstr(char *);

/*
** FILL THE STRING GIVEN AS PARAMETER WITH THE NECESSARY CHARACTER N TIMES
*/
char	*my_memset(char *, int character, int n);
int	*my_imemset(int *, int, int);

/*
** DISPLAY A CHAR, AN INT, A STRING, ... ON THE STANDARD OUTPUT
*/
void	my_putchar(char);
void	my_putnbr(int);
void	my_putstr(char *);
void	my_printf(char *, ...);
void	my_showitab(int **);
void	my_showtab(char **);

/*
** DISPLAY A STRING GIVEN AS PARAMETER ON THE ERROR OUTPUT
*/
int	my_error(char *);
void	*my_perror(char *);

/*
** COPY (ALL / N BYTES) FROM THE SRC STRING TO THE DEST STRING
*/
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *, char *, int n);

/*
** COUNT THE SIZE OF THE GIVEN PARAMETER
*/
int	my_strlen(char *);
int	my_intlen(int);
int	my_tablen(char **);

/*
** COPY (ALL / N BYTES) FROM THE SRC STRING AT THE END OF THE DEST STRING
** OVERWRITING THE NULL BYTE
*/
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *, char *, int n);

/*
** COMPARES TWO STRINGS AND RETURNS AN INT LESS THAN, EQUAL TO, OR GREATER THAN
** ZERO ACCORDING TO THE GREATEST STRING (>0 if S1 > S2)
*/
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *, char *, int);

/*
** CLEAR A STRING, EDITING \t BY SPACES AND THEN DELETING THE MULTIPLE SPACES
*/
char	*my_epurstr(char *);

/*
** SPLIT EACH WORD FROM A STRING INTO A NEW STRING
*/
char	**my_str_to_wordtab(char *, char);

/*
** LOOK FOR THE SRC STRING IN THE DEST STRING, BEGINNING AT THE Nth BYTE
*/
int	my_strseek(char *dest, char *src, int n);

/*
** LOOK FOR A CHAR INTO A STRING, ON FAILURE RETURNS -1 ELSE RETURNS THE
** FIRST POSITION OF THE CHAR IN THE STRING
*/
int	my_checkstr(char *, char);

/*
** ALLOCATES A NEW SPACE MEMORY ACCORDING TO THE SIZE AND FREE THE OLD ONE
** THE NEW STRING WILL OWN THE Nth FIRST BYTES FROM THE OLD STRING
*/
char	*my_realloc(char *, int size);

/*
** CONVERTS A STRING INTO AN INT
*/
int	my_getnbr(char *);

char	*my_getbase(unsigned int, char *);

# ifndef READ_SIZE
#  define READ_SIZE 15
# endif /* READ_SIZE */

/*
** RETURN THE NEXT LINE FROM THE FD
*/
char	*my_getnextline(int fd);
char	*my_strdup(char *);
int	my_strcmp2(char *, char *, int);

#endif /* __LIBMY_H__ */
