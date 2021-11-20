#include "so_long.h"

int	open_map(int *h, int *l, t_map **map, char *mess)
{
	int		fd;
	int		hight;
	char	*line;

	line = NULL;
	hight = 0;
	fd = open(mess, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		free(line);
		line = NULL;
		hight++;
	}
	free(line);
	line = NULL;
	close(fd);
	if (gnl1(fd, mess, map, hight) == 0)
		return (0);
	(*map)->m_hight = hight;
	*h = hight;
	*l = ft_strlen((*map)->src_data[0]);
	return (1);
}

int	gnl1(int fd, char *mess, t_map **map, int hight)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	(*map)->src_data = (char **)malloc(sizeof(char *) * (hight + 1));
	fd = open(mess, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		(*map)->src_data[i] = ft_strdup(line);
		free(line);
		line = NULL;
		i++;
	}
	(*map)->src_data[i] = ft_strdup(line);
	free(line);
	line = NULL;
	close(fd);
	return (1);
}

int	valid_map(int argc, char **argv, t_map **map)
{
	int		h;
	int		len;
	char	**data;

	data = NULL;
	(*map) = (t_map *)malloc(sizeof(t_map));
	if (argc != 1 && (*map) && check_ber(argv[1]))
	{
		if (!open_map(&h, &len, map, argv[1]))
		{
			free((*map));
			(*map) = NULL;
			return (0);
		}
		(*map)->m_hight = h;
		(*map)->m_len = len;
		(*map)->score = ft_score_game((*map));
		if (check_map_m(map))
			return (1);
		free_lines(&((*map)->src_data), h);
	}
	(*map)->src_data = NULL;
	free((*map));
	(*map) = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (!valid_map(argc, argv, &map))
	{
		error_write();
		return (0);
	}
	coordinates(map);
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->m_len * 64, \
								(map->m_hight + 1) * 64, "the game");
	map_nulls(map);
	put_image(map);
	render_map(map);
	mlx_hook(map->mlx_win, 2, 1L << 1, keyb_move, map);
	mlx_loop(map->mlx);
}
