#include "../includes/utils.h"
#include <stdio.h>

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
	t_list	*tmp;

	while (*info)
	{
		if (((t_command *)((*info)->content))->command)
			free(((t_command *)((*info)->content))->command);
		printf("1\n");
		if (((t_command *)((*info)->content))->args)
		{
			i = 0;
			while (i < ((t_command *)((*info)->content))->argc + 1)
			{
				free(((t_command *)((*info)->content))->args[i]);
				i++;
			}
			printf("2\n");
			free(((t_command *)((*info)->content))->args);
		}
		printf("3\n");
		if ((*info)->content)
			free((*info)->content);
		printf("4\n");
		tmp = *info;
		(*info) = (*info)->next;
		free(tmp);
	}
	printf("5\n");
	*info = NULL;
}