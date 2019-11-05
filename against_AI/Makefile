##
## PERSONAL PROJECT, 2019
## tictactoe
## File description:
## Makefile
##

SRC	=	src/error.c		\
		src/ai/ai_rowcol.c	\
		src/ai/ai2.c		\
		src/ai/ai.c		\
		src/overwrite.c		\
		src/game_loop.c		\
		src/detectors2.c	\
		src/detectors.c		\
		src/setup.c		\
		src/malloc_free.c	\
		src/main_tictactoe.c	\

OBJ	=	$(SRC:.c=.o)

HEADER_PATH     =       include/

CC	=	@gcc

LIB     =       include/libmy.a

CFLAGS	=	-I $(HEADER_PATH) -Wall -Werror -Wextra --pedantic

NAME	=	tictactoe

.PHONY: clean fclean re tictactoe

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling \'$(NAME)\'
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo \'$(NAME)\' compiled successfully

clean:
	@rm -rf $(OBJ)
	@echo Cleaned .o for \'$(NAME)\'

fclean:	clean
	@rm -rf $(NAME)
	@echo Cleaned \'$(NAME)\'

re: fclean all
