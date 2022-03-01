/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:29:22 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 16:23:59 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_term	t_term;

typedef struct s_cmd
{
	char	*arg;
	int		flag;
	int		first;
	int		pipefd[2];
	void	*next;
}		t_cmd;

typedef struct s_parsing
{
	char	*path;
	char	**argv;
	int		in;
	int		out;
	int		pipe_in[2];
	int		pipe_out[2];
	void	*next;
}		t_parsing;

typedef struct s_term
{
	int		(*built[7])(t_term *term, t_parsing *parsing);
	int		(*exit)(t_term *term, t_parsing *parsing, t_cmd **cmd, t_parsing *pars);
	char	**env;
	char	cwd[1000];
}				t_term;

void		ft_init_struct(t_parsing *pars);
t_parsing	*ft_creat_pars(void);
void		ft_free_argv(char **argv);
int			ft_free_pars(t_parsing *pars);
int			ft_free_term(t_term *term);
t_cmd		*ft_init_cmd(void);
int			ft_free_cmd(t_cmd *cmd);
int			ft_add_end_cmd(t_cmd **first, t_cmd *new);
void		ft_free_term_err(t_term *term);
void		ft_add_next_cmd(t_cmd *cmd, t_cmd *new);
void		ft_add_end_pars(t_parsing **first, t_parsing *new);
int			ft_creat_cmd(t_cmd **first, char *str);
int			ft_make_cmd(char *str, t_cmd **cmd);
t_parsing	*ft_get_last_pars(t_parsing *pars);
void		ft_print_cmd(t_cmd *cmd);
void		ft_print_tab_cmd(t_cmd **cmd);
#endif
