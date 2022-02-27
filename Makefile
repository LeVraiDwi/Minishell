SRCS = $(addprefix $(CHECK_PATH)/,$(CHECK_NAME)) $(addprefix $(AHDOC_PATH)/,$(AHDOC_NAME)) $(addprefix $(PIPE_PATH)/,$(PIPE_NAME)) $(addprefix $(SPE_PATH)/,$(SPE_NAME)) $(addprefix $(SRC_PATH)/,$(SRC_NAME)) $(addprefix $(HISTORY_PATH)/,$(HISTORY_NAME)) $(addprefix $(UTILS_PATH)/,$(UTILS_NAME)) $(addprefix $(LEXER_PATH)/,$(LEXER_NAME)) $(addprefix $(ENV_PATH)/,$(ENV_NAME)) $(addprefix $(BUILT_PATH)/,$(BUILT_NAME)) $(addprefix $(PARSER_PATH)/,$(PARSER_NAME)) $(addprefix $(ERR_PATH)/,$(ERR_NAME)) $(addprefix $(EXPANSER_PATH)/,$(EXPANSER_NAME)) $(addprefix $(EXEC_PATH)/,$(EXEC_NAME))

LIBFT = ./libft/libft.a

SRC_PATH =      ./srcs

SRC_NAME =      main.c strisstr.c init.c\
                term.c struct_pars.c struct_cmd.c\
				string_utils.c struct_cmd2.c\

BUILT_PATH =    ./srcs/builtin

BUILT_NAME =    env.c export.c unset.c\
                echo.c cd.c pwd.c\
                utils.c\

ENV_PATH =      ./srcs/env

ENV_NAME =      env_util.c env_utils.c env_util_access.c\

LEXER_PATH = ./srcs/lexer

LEXER_NAME = lexer.c

PIPE_PATH = ./srcs/pipe

PIPE_NAME = new_pipe.c new_pipe_utils.c pipe.c\

CHECK_PATH = ./srcs/check

CHECK_NAME = check.c check_file.c check_cmd.c\

ERR_PATH = ./srcs/err

ERR_NAME = err.c err_utils.c\

SPE_PATH = ./srcs/spe_char

SPE_NAME = spe_char_utils.c spe_char.c\

AHDOC_PATH = ./srcs/ahdoc

AHDOC_NAME = ahdoc.c ahdoc_utils.c\

PARSER_PATH = ./srcs/parser

PARSER_NAME = 	parser.c quote.c quote_utils.c\
				split.c split_spe.c\
				
UTILS_PATH = ./srcs/utils

UTILS_NAME = utils.c

EXPANSER_PATH = ./srcs/expanser

EXPANSER_NAME = expanser.c expanser_utils.c\

HISTORY_PATH = ./srcs/history

HISTORY_NAME = history_add.c

EXEC_PATH = ./srcs/exec

EXEC_NAME = exec.c creat_exec.c exec_join.c\
			exec_file.c path.c exec_util.c\
			close.c\

OBJS = ${SRCS:.c=.o}

NAME = minishell

FLAGS = -Wall -Wextra -Werror

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
