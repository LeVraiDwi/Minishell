ECHO_SRCS = echo.c

CD_SRCS = cd.c

PWD_SRCS = pwd.c

LIBFT = ../../libft/libft.a

ECHO_OBJS = ${SRCS:.c=.o}

CD_OBJS = ${SRCS:.c=.o}

PWD_OBJS = ${SRCS:.c=.o}

NAME1 = echo

NAME2 = cd

NAME3 = pwd

FLAGS = -Wall -Wextra -Werror

HEADER = -I "../../include" -I"../../libft"

DEBUG = -g -std=c11 -fsanitize=address

CC = clang

RM = rm -f

CD = cd

.c.o:
			${CC} ${FLAGS} ${HEADER} -c $< -o $@

${NAME}:		${ECHO_OBJS} ${CD_OBJS} ${PWD_OBJS}
			${CC} -o ${NAME1} ${ECHO_OBJS} ${FLAGS} ${LIBFT}
			${CC} -o ${NAME2} ${CD_OBJS} ${FLAGS} ${LIBFT}
			${CC} -o ${NAME3} ${PWD_OBJS} ${FLAGS} ${LIBFT}

all:			${NAME}

clean:
			${RM} ${ECHO_OBJS} ${CD_OBJS} ${PWD_OBJS}

fclean:			clean
			${RM} ${NAME1} ${NAME2} ${NAME3}

re:			fclean all

.PHONY =		all clean fclean re

