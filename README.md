# Minishell
minishell project for 42chool paris.
reproduce a shell with less feature in c

to do list:
	exec:
		historique
	`	gerer $?
	builtin:
		modifier les builtin pour qu' il ecrive dans la sortie choisie
		si il y a une | apres export ou unset ne rien faire return 0 sauf si export a pas arg-> print env sur sortie
	redirection:
		permettre de lire < file cmd ou < file > file cmd < file2
		gerer le <<
	free, etc...:
		trouver et eliminer les leaks
	signal:
		faire les signal dans >>
		faire les signal dans le term
	expanser
		tester ~/
