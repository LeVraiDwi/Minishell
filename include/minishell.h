#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>


typedef struct	s_parsing
{
	char				**path; //le path
	char				**argv; //tableau des argument 1er element le nom de la cmd eg: echo
	char				**env; //variable env du main
	unsigned int		flag;
	void				*next;
}				t_parsing;

#endif
