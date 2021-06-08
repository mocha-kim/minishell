#include "../../includes/builtin.h"

extern t_state	g_state;

void	ft_export(t_command *cmd)
{
	(void)cmd;
	g_state.ret = 0;
}