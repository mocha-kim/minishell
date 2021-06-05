#include "../../includes/parsing.h"

int		custom_putchar(int c)
{
	return (write(STD_OUT, &c, 1));
}