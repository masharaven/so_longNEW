#include "so_long.h"

void	error_write(void)
{
	write(1, "Error\n", 7);
	write(1, "Check your map, buddy. It's invalid.\n", 38);
}
