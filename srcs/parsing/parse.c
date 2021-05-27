#include "../../includes/parsing.h"

int		parse_command(char *line)
{
	if (*line == ';')
		return (0);
	if (!ft_strncmp(line, "echo ", 5))
		
	return (1);
}

int		findsemi(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ';')
			return (1);
		i++;
	}
	return (0);
}

int		parse(char *line, t_parse *info)
{
	int		command;
	int		i;
	command = 0;
	(void)info;
	while (*line == ' ')
		line++;
	if (ft_strlen(line) == 0)
		return (0);
	while (line)
	{
		i = parse_command(line);
		line += i;
	}
	return (command);
}

