SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

SRC_PATH = ./srcs

SRC_NAME = main.c env_utils.c env_util.c\
		strisstr.c builtin/env.c builtin/export.c\
		builtin/unset.c init.c builtin/echo.c\
		builtin/cd.c builtin/pwd.c env_util_access.c\
		builtin/utils.c\
		lexer/lexer.c															\
		lexer/tokenize.c 														\
		lexer/set_token.c														\
		lexer/lexer_utils.c														\
		parser/parser.c															\
		parser/parser_utils.c
LIBFT = ./libft/libft.a

OBJS = ${SRCS:.c=.o}

NAME = minishell

FLAGS = -Wall -Wextra

HEADER = -I "./include" -I"./libft"

DEBUG = -g -std=c11 -fsanitize=address

RL = -lreadline 

CC = clang

RM = rm -f

CD = cd

.c.o:
		${CC} ${FLAGS} ${HEADER} ${RL} -c $< -o $@

${NAME}:	${OBJS}
		cd libft; make;
		${CC} -o ${NAME} ${OBJS} ${FLAGS} ${LIBFT} ${RL}

all:		${NAME}

clean:
		${RM} ${OBJS}
		cd libft; make clean;

fclean:		clean
		${RM} ${NAME}
		cd libft; make fclean;

re:		fclean all
		cd libft; make re;

.PHONY =	all clean fclean re
