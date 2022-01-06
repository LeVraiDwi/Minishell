SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

UNAME_S = $(shell uname -s)

SRC_PATH = ./src

SRC_NAME =	main.c 

LIBFT = ./libft/libft.a

OBJS = ${SRCS:.c=.o}

NAME = minishell

FLAGS = -Wall -Wextra -Werror

HEADER = -I "./include" -I"./libft"

DEBUG = -g -std=c11 -fsanitize=address

CC = clang

RM = rm -f

CD = cd

.c.o:
			${CC} ${FLAGS} ${HEADER} -c $< -o $@

${NAME}:	${OBJS}
			cd libft; make;
			${CC} -o ${NAME} ${OBJS} ${FLAGS} ${LIBFT}

all:		${NAME}

clean:
			${RM} ${OBJS}
			cd libft; make clean;

fclean:		clean
			${RM} ${NAME}
			cd libft; make fclean;

re:			fclean all
			cd libft; make re;

.PHONY =	all clean fclean re
