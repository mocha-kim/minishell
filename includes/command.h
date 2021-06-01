#ifndef COMMAND_H
# define COMMAND_H

# include "data.h"
# include "builtin.h"

void		execute(t_parse *cmd);
void		execute_cmd(t_command cmd);

#endif