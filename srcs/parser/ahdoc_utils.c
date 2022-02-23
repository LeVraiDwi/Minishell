#include "minishell.h"

int	ft_make_var(t_term *term, t_cmd *tab)
{
	while (tab)
	{
		if (ft_replace_in_tab(term, tab) < 0)
			return (-1);
		tab = tab->next;
	}
	return (0);
}

int	ft_replace_in_tab(t_term *term, t_cmd *tab)
{
	int		i;
	int		l;
	char	*tmp;
	char	*var;

	i = 0;
	while (tab->arg[i])
	{
		if ((ft_is_special_char(tab->arg, i, 0) & VAR))
		{
			l = ft_ahdoc_var_len(tab->arg + i);
			var = ft_substr(tab->arg, i + 1, l);
			if (!var)
				return (-1);
			tmp = get_env_var(term->env, var);
			free(var);
			if (!tmp)
				return (-1);
			var = tab->arg;
			tab->arg = ft_insertvar(tab->arg, tmp, i, l);
			l = ft_strlen(tmp);
			free(tmp);
			free(var);
			if (!tab->arg)
				return (-1);
			i += l;
		}
		i++;
	}
	return (0);
}

int	ft_ahdoc_var_len(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '$')
		i++;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i);
}

int	ft_free_ahdoc(t_term *term, t_cmd *cmd, char *str, int exit_state)
{
	if (term) 
		ft_free_term(term);
	if (cmd)
		ft_free_cmd(cmd);
	if (str)
		free(str);
	ft_close(cmd->pipefd[0], cmd->pipefd[1]);
	exit(exit_state);
	return (-1);
}
