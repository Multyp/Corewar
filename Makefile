##
## Makefile for Makefile in /home/arnaud_e/rendu/cpe/corewar
##
## Made by Arthur ARNAUD
## Login   <arnaud_e@epitech.net>
##
## Started on  Wed Mar  2 02:57:33 2016 Arthur ARNAUD
## Last update Thu Mar 17 11:29:40 2016 Clement Peau
##

POC=			yes

DEBUG=			yes

SRC_PREFIX_DECOMPILER=	src/decompiler/

SRC_FILES_DECOMPILER=	main.c			\
			header.c		\
			my_putstrs.c		\
			fill_file.c		\
			check_codage.c		\
			my_putnbr_file.c	\
			set_ftab.c		\
			convert_to_nb.c		\
			new_name.c		\
			my_strlen.c		\
			op_live.c		\
			op_add.c		\
			op_aff.c		\
			op_and.c		\
			op_fork.c		\
			op_ld.c			\
			op_ldi.c		\
			op_lfork.c		\
			op_lld.c		\
			op_lldi.c		\
			op_or.c			\
			op_st.c			\
			op_sti.c		\
			op_sub.c		\
			op_xor.c		\
			op_zjmp.c		\
			my_memset.c

SRC_DECOMPILER=		$(addprefix $(SRC_PREFIX_DECOMPILER),$(SRC_FILES_DECOMPILER))

SRC_PREFIX_ASM=		src/compiler/

SRC_FILES_ASM=		get_header.c		\
			main.c			\
			lexer.c			\
		#	check_action.c		\
		#	check_line.c		\
		#	create_list.c		\

		#	check_label.c		\
		#	get_header.c

SRC_ASM=		$(addprefix $(SRC_PREFIX_ASM),$(SRC_FILES_ASM))

NAME=			asm

HEAD=			-Iinclude

ifeq ($(DEBUG), yes)
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
else
	CFLAGS=		$(HEAD) -W -Wall -Wextra -Werror -ansi -pedantic
endif

ifeq ($(POC), yes)
	CC =		clang
else
	CC = 		gcc
endif

RM=			rm -f

OBJ_DECOMPILER=		$(SRC_DECOMPILER:.c=.o)

OBJ_ASM=		$(SRC_ASM:.c=.o)

$(NAME):		$(OBJ_ASM)
			@echo "[ OK ] Soft Compiled"
			@$(CC) $(OBJ_ASM) -o asm

%.o:			%.c
			@echo "[ OK ] Compiling" $<
			@$(CC) -o $@ -c $< $(CFLAGS)

all:			$(NAME)

clean:
			@echo "[ OK ] Removing OBJ files ..."
			@$(RM) $(OBJ_DECOMPILER)
			@$(RM) $(OBJ_ASM)

fclean:			clean
			@echo "[ OK ] Deleting binaries ..."
			@$(RM) $(NAME)
			@$(RM) decompiler

re:			fclean all

decompiler:		$(OBJ_DECOMPILER)
			@$(CC) -o decompiler $(OBJ_DECOMPILER)
			@echo "[ OK ] Decompiler Compiled"

.PHONY:			all clean fclean re
