#ifndef PROGRAM_H
# define PROGRAM_H

# include "error.h"
# include "data.h"
# include "parsing.h"
# include "command.h"

/*
** program.c
*/

int						run_program(t_dlist **programs, char *line);

#endif