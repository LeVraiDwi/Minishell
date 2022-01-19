#include "minishell.h"

char *get_val(char *env)
{
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

int	ft_update_pwd(t_term *term, char *path)
{
	char	*tmp;
	char	*var;

	var = get_env_var(term->env, "PWD");
	if (!var)
		return (0);
	tmp = ft_strjoin("OLDPWD=", var);
	free(var);
	add_env(term, tmp);
	free(tmp);
	var = (ft_strjoin("PWD=", path));
	add_env(term, var);
	return (1);

}
