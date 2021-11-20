/////
#include "so_long.h"

char	*get_save(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	rtn = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1));
	if (!rtn)
		return (0);
	i++;
	while (save[i])
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	free(save);
	return (rtn);
}

char	*get_line(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	rtn = malloc(sizeof(char) * (i + 1));
	if (!rtn)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

static int	return_rs(char *buff, char *save, int reader)
{
	if (reader == -1 && save == NULL)
	{
		free(buff);
		return (-1);
	}
	if (reader == 0 && buff == NULL)
	{
		free(save);
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*save;
	int				reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	while (!has_return(save) && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
			return (return_rs(buff, NULL, -1));
		buff[reader] = '\0';
		save = ft_join(save, buff);
	}
	free(buff);
	*line = get_line(save);
	save = get_save(save);
	if (reader == 0)
		return (return_rs(NULL, save, 0));
	return (1);
}

// int	the_main_fig(int fd, char *buff, char **line, char *save)
// {
// 	int	reader;

// 	reader = 1;
// 	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buff)
// 		return (-1);
// 	while (!has_return(save) && reader != 0)
// 	{
// 		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
// 		{
// 			free(buff);
// 			return (-1);
// 		}
// 		buff[reader] = '\0';
// 		save = ft_join(save, buff);
// 	}
// 	free(buff);
// 	*line = get_line(save);
// 	save = get_save(save);
// 	if (reader == 0)
// 	{
// 		free(save);
// 		return (0);
// 	}
// }
