#include "so_long.h"

//checker for the symb, if not 1CE0P
int	valid_symbol(t_map *map)
{
	int		i;
	int		h;
	char	*buff;

	h = 0;
	i = 0;
	while (i < map->m_hight)
	{
		h = 0;
		buff = map->src_data[i];
		while (buff[h])
		{
			if (!find_symb(buff[h], (const char *)"1CE0P"))
				return (0);
			h++;
		}
		i++;
	}
	return (1);
}

int	check_wall_board(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] == '1')
		i++;
	return (ft_strlen(line) == i);
}

char	*ft_check_place(char p, char *buff)
{
	char	*line;
	char	*line2;

	line = ft_strchr(buff, p);
	line2 = ft_strrchr(buff, p);
	if (line == line2 && (line && line2))
		return (line);
	return (NULL);
}

int	ft_score_game(t_map *map)
{
	int	scr;
	int	y;
	int	x;

	scr = 0;
	y = 0;
	x = 0;
	while (y < map->m_hight)
	{
		x = 0;
		while (map->src_data[y] && map->src_data[y][x])
		{
			if (map->src_data[y][x] == 'C')
				scr++;
			x++;
		}
		y++;
	}
	return (scr);
}

void	free_lines(char ***map, int h)
{
	int	i;

	i = 0;
	while (i <= h)
	{
		free((*map)[i]);
		i++;
	}
	free((*map));
	(*map) = NULL;
}
