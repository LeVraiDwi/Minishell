#include "minishell.h"
#include "lexer.h"
#include "parser.h"

t_parsing	*parse_init(char *line, char **env)
{
	t_lexer		lexerbuf;
	t_parsing	*parserbuf;

	lexerbuf.path = get_pathv(env);
	lexerbuf.tokenlist = malloc(sizeof(t_token));
	lexerbuf.j = 0;
	lexer_build(line, ft_strlen(line), &lexerbuf);
	parserbuf = malloc(sizeof(t_parsing));
	parse(&lexerbuf, parserbuf);
	parserbuf->path = check_cmd(parserbuf->argv[0], lexerbuf.path);
	return (parserbuf);
}

int	main(int argc, char **argv, char **env)
{
	t_term		term;
	t_parsing	*parsebuf;
	char		*str;
	char		**cmd;
	int			i;
	//char	*cmd1[] = {"env", 0};
	//char	*cmd1[] = {"export", "a=12", "jaime=", "pain=jamenfkfhssflf", "0"};

	(void)argv;
	(void)argc;
	if(!init_term(&term, env))
		return (0);
	while (!term.exit)
	{
		str = readline("\033[34;01mMinishell\033[00m$ ");
		parsebuf = parse_init(str, env);
		cmd = ft_split(str, ' ');
		i = ft_is_builtin(*cmd);
		printf("%d\n", i);
		if (i == 6)
			term.exit = 1;
		else if (i >= 0)
			term.built[i](&term, cmd);
		free(str);
	}
	return (0);
}
