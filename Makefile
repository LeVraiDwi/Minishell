
SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME)) $(addprefix $(BUILT_PATH)/,$(BUILT_NAME)) $(addprefix $(ENV_PATH)/,$(ENV_NAME)) $(addprefix $(PARSER_PATH)/,$(PARSER_NAME)) $(addprefix $(LEXER_PATH)/,$(LEXER_NAME)) $(addprefix $(EXPANSER_PATH)/,$(EXPANSER_NAME)) $(addprefix $(EXEC_PATH)/,$(EXEC_NAME))

LIBFT = ./libft/libft.a

SRC_PATH =      ./srcs

SRC_NAME =      main.c strisstr.c init.c\
                term.c struct_pars.c\

BUILT_PATH =    ./srcs/builtin

BUILT_NAME =    env.c export.c unset.c\
                echo.c cd.c pwd.c\
                utils.c\

ENV_PATH =      ./srcs/env

ENV_NAME =      env_util.c env_utils.c env_util_access.c\

LEXER_PATH = ./srcs/lexer

LEXER_NAME = lexer.c lexer_utils.c set_token.c tokenize.c

PARSER_PATH = ./srcs/parser

PARSER_NAME = parser.c parser_utils.c

EXPANSER_PATH = ./srcs/expanser

EXPANSER_NAME = expanser.c expanser_utils.c expanser_file.c\
		in_out.c

EXEC_PATH = ./srcs/exec

EXEC_NAME = exec.c exec_util.c

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
		${CC} ${FLAGS} ${HEADER} -c $< -o $@

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
