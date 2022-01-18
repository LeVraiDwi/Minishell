#include "minishell.h"

char *get_val(char *env)
{
	char	*new;
	int	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	return (ft_strdup(env + i));
}

char	*get_env_var(char **env, char *var)
{
	int	i;
	
	i = ft_is_env(env, var);
	if (i)
		return (get_val(env[i]));
	return (0);
}

int	update_pwd()
{

}
