#ifndef COMMAND_H
# define COMMAND_H

# include "../libft/libft.h"
# include "data.h"
# include "builtin.h"
# include <stdio.h>

void		execute(t_list *cmd);
void		execute_cmd(t_command cmd);

#endif