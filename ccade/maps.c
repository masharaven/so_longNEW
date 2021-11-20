#include "so_long.h"

int	check_ber(char *argv)
{
	int		i;
	char	*begin;

	i = ft_strlen(argv);
	begin = (char *) &argv[(i - 4)];
	if (ft_strncmp(begin, ".ber", 4) == 0)
		return (1);
	return (0);
}

void	*map_nulls(t_map *map)
{
	map->img_w = 64;
	map->img_h = 64;
	map->backround = 0;
	map->wall = 0;
	map->exit = 0;
	map->person = 0;
	map->coin = 0;
	map->steps = 0;
	return (0);
}
