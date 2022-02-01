#include "minishell.h"

int	ft_isfile(char *path)
{
	DIR	*dp;
	
	dp = opendir(path);
	if (dp)
	{
		errno = EISDIR;
		closedir(dp);
		return (-1);
	}
	closedir(dp);
	return (0);
}

int	ft_checkright(char *path, int right)
{
	if (right & O_RDONLY)
		if (access(path, R_OK))
			return (-1);
	if (right & O_WRONLY)
		if (access(path, W_OK))
			return (-1);
	if (right & O_RDWR)
		if (access(path, R_OK | W_OK))
			return (-1);
	return (0);
}

int	ft_openfile(char *path, int flags, int right)
{
	int fd;

	if (!path)
		return (0);
	if (ft_isfile(path) < 0)
		return (-1);
	if (!access(path, F_OK))
	{
		if (ft_checkright(path, right))
			return (-1);
		fd = open(path, flags | right);
	}
	else
		fd = open(path, O_CREAT | flags | right, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (fd < 0)
		return (-1);
	return (fd);
}
