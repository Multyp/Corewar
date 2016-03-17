##
## Makefile for Makefile in /home/arnaud_e/rendu/cpe/corewar
##
## Made by Arthur ARNAUD
## Login   <arnaud_e@epitech.net>
##
## Started on  Wed Mar  2 02:57:33 2016 Arthur ARNAUD
## Last update Wed Mar 16 19:21:40 2016 Clement Peau
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
			my_memset.c		\

SRC_DECOMPILER=		$(addprefix $(SRC_PREFIX_DECOMPILER),$(SRC_FILES_DECOMPILER))

SRC_PREFIX_ASM=		src/compiler/

SRC_FILES_ASM=		check_action.c		\
			check_line.c		\
			create_list.c		\
			lexer.c			\
			check_label.c		\
			main.c			\
			get_header.c		\

SRC_ASM=		$(addprefix $(SRC_PREFIX_ASM),$(SRC_FILES_ASM))

NAME_DECOMPILER=	decompiler

NAME=			asm

HEAD=			-Iinclude

ifeq ($(DEBUG), yes)
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
else
	CFLAGS=		$(HEAD) -W -Wall -Wextra -Werror -ansi -pedantic
endif

ifeq ($(POC), yes)
	CC = clang
else
	CC = gcc
endif

#ifeq ($(DEBUG), yes)
#	@echo "  ____  _____ ____  _   _  ____   __  __  ___  ____  _____ "
#	@echo " |  _ \| ____| __ )| | | |/ ___| |  \/  |/ _ \|  _ \| ____|"
#	@echo " | | | |  _| |  _ \| | | | |  _  | |\/| | | | | | | |  _|  "
#	@echo " | |_| | |___| |_) | |_| | |_| | | |  | | |_| | |_| | |___ "
#	@echo " |____/|_____|____/ \___/ \____| |_|  |_|\___/|____/|_____|"
#	@echo "                                                           "
#endif

RM=			rm -f

LIB=			-lncurses

OBJ_DECOMPILER=		$(SRC_DECOMPILER:.c=.o)

OBJ_ASM=		$(SRC_ASM:.c=.o)

decompiler:		$(OBJ_DECOMPILER)

asm:			$(OBJ_ASM)
			@echo -n "[ OK ] Soft Compiled"
			@$(CC) $(OBJ_ASM) -o asm $(LIB)

%.o:			%.c
			@echo "[ OK ] Compiling" $<
			@$(CC) -o $@ -c $< $(CFLAGS)

all:			asm

clean:
			@echo "[ OK ] Removing OBJ files ..."
			@$(RM) $(OBJ_DECOMPILER)
			@$(RM) $(OBJ_ASM)

fclean:			clean
			@echo "[ OK ] Deleting binaries ..."
			@$(RM) $(NAME)
			@$(RM) $(NAME_DECOMPILER)

re:			fclean all

.PHONY:			all clean fclean re
