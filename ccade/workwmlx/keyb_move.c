#include "../so_long.h"

int	keyb_move(int keyb, t_map *map)
{
	if (keyb == 53)
		exit(0);
	if (keyb == 13)
		move_pers(-1, 0, map);
	if (keyb == 0)
		move_pers(0, -1, map);
	if (keyb == 1)
		move_pers(1, 0, map);
	if (keyb == 2)
		move_pers(0, 1, map);
	return (0);
}
