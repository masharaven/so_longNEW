#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilbx/mlx.h"
# define BUFFER_SIZE 50

typedef struct s_map{
	int		m_hight;
	int		m_len;
	char	**src_data;
	int		score;
	void	*mlx;
	void	*mlx_win;
	void	*backround;
	void	*wall;
	void	*exit;
	void	*person;
	void	*coin;
	int		img_w;
	int		img_h;
	int		x_player;
	int		y_player;
	int		steps;
}	t_map;

int		gnl1(int fd, char *mess, t_map **map, int hight);

//error_write
void	error_write(void);

//extra.c
char	*ft_check_place(char p, char *buff);
int		ft_score_game(t_map *map);
int		check_wall_board(char *line);
void	free_lines(char ***map, int h);
int		valid_symbol(t_map *map);

//extra_f1.c
void	coordinates(t_map *map);

//libft
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *str, int ch);
char	*ft_strdup(char *src);
void	*ft_realloc(void **src, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		find_symb(char c, const char *buff);

//workwmlx move_pers.c
void	move_pers(int y, int x, t_map *map);
void	re_render_map(int y, int x, t_map *map);
void	moving_in_src_data(int y, int x, t_map *map);
int		check_exit_src(int y, int x, t_map *map);

//workwmlx put_image.c
void	*put_image(t_map *map);
void	render_map(t_map *map);
//wasd_keys.c

int		close_win(int keyb, t_map *map);
int		keyb_move(int keyb, t_map *map);
//move_pers.c

void	move_pers(int x, int y, t_map *map);
void	re_render_after(t_map *map);
void	put_img_again(t_map *map, int y, int x);

//gnl
int		get_next_line(int fd, char **line);
int		has_return(char *str);
size_t	ft_strlen(const char *s);
char	*ft_join(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
int		free_buff(char *buff);
//maps.c
void	*map_nulls(t_map *map);
int		check_ber(char *argv);

//valid
int		check_map_m(t_map **map);
int		check_wall_board(char *wall);

void	insert_xpm(t_map *map, int row, int col, void *xpm);

#endif