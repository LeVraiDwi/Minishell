#include "minishell.h"

int	ft_free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
	env = 0;
	return (0);
}

int	replace_env(t_term *term, char *var, int i)
{
	char	*tmp;

	tmp = term->env[i];
	tmp = ft_strdup(var);
	if (!tmp)
		return (0);
	free(term->env[i]);
	term->env[i] = tmp;
	return (1);
}

int	ft_dealloc_env(t_term *term, int i)
{
	int	l;
	int	j;
	char	**tmp;

	l = 0;
	while (term->env[l])
		l++;
	tmp = (char **)malloc(sizeof(char *) * l);
	if (!tmp)
		return(0);
	tmp[l - 1] = 0;
	l = 0;
	j = 0;
	while (term->env[l])
	{
		if (l == i)
		{
			free(term->env[l]);
			l++;
		}
		tmp[j++] = term->env[l++];
	}
	free(term->env);
	term->env = tmp;
	return (1);
}

int	remove_env(t_term *term, char *var)
{
	int	i;

	i = ft_is_env(term->env, var);
	if (!i)
		return (0);
	ft_dealloc_env(term, i);
	return (0);
}

void print_env(t_term term)
{
	int	i;

	i = 0;
	while (term.env[i])
	{
		printf("%s\n", term.env[i]);
		i++;
	}
}
