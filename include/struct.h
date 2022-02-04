#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_term t_term;

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
	unsigned int		flag;
	int					in;
	int					out;
	int					err;
	char				*str_in;
	char				*str_out;
	char				*str_err;
	void				*next;
}		t_parsing;

void		ft_init_struct(t_parsing *pars);
t_parsing	*ft_creat_pars(void);
void		ft_free_argv(char ***argv);
int		ft_free_pars(t_parsing *pars);
#endif
