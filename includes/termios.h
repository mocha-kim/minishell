#ifndef TERMIOS_H
# define TERMIOS_H

# include <term.h>

# include "data.h"

void		init_term(void);
void		restore_term(void);

#endif