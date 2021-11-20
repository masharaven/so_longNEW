#include "../so_long.h"

void	*put_image(t_map *map)
{
	map->wall = mlx_xpm_file_to_image(map->mlx, "xpm_img/wall.xpm", \
												&map->img_w, &map->img_h);
	map->backround = mlx_xpm_file_to_image(map->mlx, "xpm_img/Mountains01.xpm", \
												&map->img_w, &map->img_h);
	map->coin = mlx_xpm_file_to_image(map->mlx, "xpm_img/coin.xpm", \
												&map->img_w, &map->img_h);
	map->person = mlx_xpm_file_to_image(map->mlx, "xpm_img/person.xpm", \
												&map->img_w, &map->img_h);
	map->exit = mlx_xpm_file_to_image(map->mlx, "xpm_img/exit.xpm", \
												&map->img_w, &map->img_h);
	if (!map->wall || !map->backround || !map->coin \
						|| !map->person || !map->exit)
		exit(1);
	return (0);
}

void	render_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i <= map->m_hight)
	{
		j = 0;
		while (j < map->m_len)
		{
			insert_xpm(map, j, i, map->backround);
			if (map->src_data[i][j] == '1')
				insert_xpm(map, j, i, map->wall);
			if (map->src_data[i][j] == 'C')
				insert_xpm(map, j, i, map->coin);
			if (map->src_data[i][j] == 'E')
				insert_xpm(map, j, i, map->exit);
			if (map->src_data[i][j] == 'P')
				insert_xpm(map, j, i, map->person);
			j++;
		}
		i++;
	}
}

void	insert_xpm(t_map *map, int row, int col, void *xpm)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, xpm, row * 64, col * 64);
}
