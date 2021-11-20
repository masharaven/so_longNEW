#include "../so_long.h"

int	close_win(int keyb, t_map *map)
{
	(void)keyb;
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(1);
	return (0);
}
