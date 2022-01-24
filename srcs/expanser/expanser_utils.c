#include "minishell.h"

int	ft_var_len(char *var)
{
	int	i;

	i = 1;
	while (var[i] && (ft_isalnum(var[i]) || var[i] == '_'))
		i++;
	return i;
}

int	ft_is_special_char(char c)
{
	int	i;

	i = 0;
	while (CHAR_SPE[i])
	{
		if (c == CHAR_SPE[0])
			return (i + 1);
	}
	return (0);
}

int	insert_var(char **env, char **cmd, int var_start)
{
	char	*var;
	char	*tmp;
	int		l;

	tmp = *cmd;
	if (tmp[var_start] == '$' && (ft_isalnum(tmp[var_start]) || tmp[var_start] == '_'))
	{
		l = ft_var_len(*cmd + var_start);
		var = ft_substr(tmp, var_start + 1, l);
		tmp = ft_get_env_var(env, var);
		if (tmp < 0)
			return (-1);
		free(var);
		var = ft_insertvar(*cmd, tmp, var_start, l);
		l = ft_strlen(tmp);
		free(tmp);
		if (!var)
			return (-1);
		free(*cmd);
		*cmd = var;
	}
	else if (tmp[var_start] == '~')
	{
		var = ft_get_env_var(env, "HOME");
		if (tmp < 0)
			return (-1);
		tmp = ft_insertvar(*cmd, var, var_start, 1);
		free(var);
		l = 4;
		if (!tmp)
			return (-1);
		free(*cmd);
		*cmd = tmp;
	}
	return (l);
}

char	*ft_insertvar(char *s, char *str, int var_start, int var_l)
{
	int		l;
	chra	*new;

	if (!s || !*s)
		return (ft_strdup(str));
	if (!str)
		return (ft_strdup(s));
	l = 0;
	l = ft_strlen(s) + ft_strlen(str);
	new = (char *)malloc(sizeof(char) * (l + 1));
	if (!new)
		return (0);
	new[l] = 0;
	l = 0;
	while (*s)
	{
		if (l == start)
		{
			while (*str)
				new[l++] == *str++;
			s += var_l;
		}
		new[l++] = *s++;
	}
	return (new);
}
