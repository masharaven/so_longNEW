#include "../so_long.h"
void	move_pers(int y, int x, t_map *map)
{
	if (map->src_data[map->y_player + y][map->x_player + x] != '1')
	{
		if (map->src_data[map->y_player + y][map->x_player + x] == 'C')
		{
			moving_in_src_data(y, x, map);
			map->score--;
			if (map->score == 0)
			{
				map->exit = mlx_xpm_file_to_image(map->mlx, "xpm_img/exit.xpm", \
												 &map->img_w, &map->img_h);
				render_map(map);
			}
		}
		else if (check_exit_src(y, x, map) == 1)
		{
			printf("%s", "you won\n");
			exit(0);
		}
		else if (map->src_data[map->y_player + y][map->x_player + x] == '0')
			moving_in_src_data(y, x, map);
		render_map(map);
		map->steps++;
		printf("steps: %d\n", map->steps);
	}
}

int	check_exit_src(int y, int x, t_map *map)
{
	if (map->score == 0 && \
		map->src_data[map->y_player + y][map->x_player + x] == 'E')
		return (1);
	return (0);
}

void	moving_in_src_data(int y, int x, t_map *map)
{
	map->src_data[map->y_player][map->x_player] = '0';
	map->src_data[map->y_player + y][map->x_player + x] = 'P';
	map->y_player = map->y_player + y;
	map->x_player = map->x_player + x;
}

void	re_render_map(int y, int x, t_map *map)
{
	map->src_data[map->y_player + y][map->x_player + x] = 'P';
	map->src_data[map->y_player + y][map->x_player + x] = '0';
}

void	re_render_after(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->m_hight)
	{
		x = 0;
		while (x < map->m_len)
		{
			put_img_again(map, y, x);
		}
		x++;
	}
	y++;
	insert_xpm(map, map->y_player, map->x_player, map->backround);
}
