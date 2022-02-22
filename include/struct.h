#ifndef STRUCT_H
# define STRUCT_H
# define JOIN 1
# define SIMPLE 2
# define DOUBLE 4

typedef struct s_term t_term;

typedef struct s_cmd
{
	char	*arg;
	int	flag;
	void	*next;
}		t_cmd;

typedef struct s_parsing
{
	char				*path;
	char				**argv;
	char				**heredoc;
	t_cmd				*cmd;
	unsigned int		flag;
	int					in;
	int					out;
	int					err;
	char				*str_in;
	t_cmd				*quote_in;
	char				*str_out;
	t_cmd				*quote_out;
	char				*str_err;
	t_cmd				*quote_err;
	void				*next;
}		t_parsing;

typedef struct s_term
{
	int		exit;
	int		(*built[6])(t_term *term, t_parsing *parsing);
	char		**env;
	int		last_ret;
	char		**err;
}				t_term;

void		ft_init_struct(t_parsing *pars);
t_parsing	*ft_creat_pars(void);
void		ft_free_argv(char **argv);
int		ft_free_pars(t_parsing *pars);
int		ft_free_term(t_term *term);
t_cmd		*ft_init_cmd(void);
int		ft_free_cmd(t_cmd *cmd);
int		ft_add_end_cmd(t_cmd **first, t_cmd *new);
void		ft_add_next_cmd(t_cmd *cmd, t_cmd *new);
int		ft_creat_cmd(t_parsing *parsing);
int		ft_make_cmd(char *str, t_cmd **cmd);
#endif
