#include "../includes/utils.h"

int		custom_putchar(int c)
{
	return (write(STD_OUT, &c, 1));
}

void	skip_whitespace(char *str, int *i)
{
	while (str[*i] != 0 && (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
				|| str[*i] == '\f' || str[*i] == '\r' || str[*i] == '\v'))
				(*i)++;
}

void	free_info(t_list **info)
{
	int		i;

	i = 0;
	while (*info)
	{
		if (((t_command *)((*info)->content))->command)
			free(((t_command *)((*info)->content))->command);
		while (((t_command *)((*info)->content))->args[i])
		{
			free(((t_command *)((*info)->content))->args[i]);
			i++;
		}
	}
}