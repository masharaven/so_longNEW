#include "so_long.h"

static int	check_len(t_map *map)
{
	int	real_l;
	int	must_be;
	int	place_l;
	int	cl;

	cl = 0;
	must_be = 0;
	place_l = 0;
	real_l = ft_strlen(map->src_data[0]);
	while (cl <= map->m_hight)
	{
		place_l += ft_strlen(map->src_data[(cl)]);
		must_be += real_l;
		cl++;
	}
	return (place_l == must_be);
}

static int	check_wall(t_map *map)
{
	int		boarder;
	int		i;
	char	*temp;

	i = 0;
	boarder = 1;
	if (!check_wall_board(map->src_data[0]))
		return (0);
	if (!check_wall_board(map->src_data[(map->m_hight)]))
		return (0);
	while (i <= map->m_hight)
	{
		temp = map->src_data[i];
		if (temp[0] != '1')
			boarder = 0;
		if (temp[ft_strlen(temp) - 1] != '1')
			boarder = 0;
		i++;
	}
	return (boarder);
}

static unsigned long	check_player(t_map *map)
{
	int		i;
	char	*buff;
	char	*place;
	char	*place2;

	i = 0;
	place = 0;
	place2 = 0;
	while (i < map->m_hight)
	{
		buff = ft_strdup(map->src_data[i]);
		if (place)
			place2 = ft_check_place('P', buff);
		if (!place)
			place = ft_check_place('P', buff);
		if (place2)
			return (0);
		i++;
		free(buff);
	}
	return (!!place);
}

static int	check_exit(t_map *map)
{
	int		i;
	char	*buff;
	int		exit;

	i = 0;
	exit = 0;
	while (i < map->m_hight)
	{
		buff = ft_strdup(map->src_data[i]);
		if (ft_strchr(buff, 'E'))
			exit++;
		i++;
		free(buff);
	}
	if (exit != 1)
		return (0);
	else
		return (1);
}

int	check_map_m(t_map **map)
{
	if (!check_len((*map)))
		return (0);
	if (!check_wall((*map)))
		return (0);
	if (!check_player((*map)))
		return (0);
	if (!check_exit(*map))
		return (0);
	if (!ft_score_game((*map)))
		return (0);
	if (!valid_symbol((*map)))
		return (0);
	return (1);
}
