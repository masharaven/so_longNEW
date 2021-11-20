#include "so_long.h"

void	coordinates(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < map->m_hight)
	{
		x = 0;
		while (x < map->m_len)
		{
			if (map->src_data[y][x] == 'P')
			{
				map->y_player = y;
				map->x_player = x;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	put_img_again(t_map *map, int y, int x)
{
	insert_xpm(map, x, y, map->backround);
	if (map->src_data[y][x] == '1')
		insert_xpm(map, x, y, map->wall);
}
