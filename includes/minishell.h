#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>

# include "builtin.h"
# include "env.h"
# include "error.h"
# include "parsing.h"
# include "command.h"

#endif