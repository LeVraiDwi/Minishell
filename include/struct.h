#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_term	t_term;

typedef struct s_term
{
	int		exit;
	int		(*built[6])(t_term *term, char **cmd);
	char	**env;
}				t_term;

typedef struct s_parsing
{
	char				*path;
	char				**argv;
	char				**env;
	unsigned int		flag;
	int					in;
	int					out;
	int					err;
	char				*str_in;
	char				*str_out;
	char				*str_err;
	void				*next;
}		t_parsing;
#endif
