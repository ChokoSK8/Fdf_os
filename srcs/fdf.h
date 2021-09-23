#ifndef FDF_H

# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../Minilibx-os/mlx.h"
# include "../Libft/libft.h"
# include "../Gnl/get_next_line.h"

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_ptdouble
{
	double		x;
	double		y;
}				t_ptdouble;

typedef struct	s_vect
{
	double		x;
	double		y;
}				t_vect;

typedef struct	s_apex
{
	t_ptdouble	a;
	t_ptdouble	b;
	t_ptdouble	c;
	t_ptdouble	d;
}				t_apex;

typedef struct	s_map
{
	char		**data;
	size_t		max_width;
	size_t		height;
}				t_map;

typedef struct	s_img
{
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
	void	*image;
	int		coef_x;
	int		coef_y;
}				t_img;

typedef struct	s_param
{
	void	*mlx;
	void	*win;
	size_t	width;
	size_t	height;
	t_img	img;
	t_map	map;
}				t_param;

int		ft_close_window(int key, t_param *param);

void	free_param(t_param *param);

int		init_map(t_map *map, char *file);

int		init_param(t_param *param, char *file);

void	init_param_len_and_coef(t_param *param);

void	display_squares(t_img *mg, t_map map);

void	print_cases(t_img *img, t_point pt, int size_line);

void	print_diamonds(t_img *img, t_point pt, int size_line);

char	*ft_strdup_fdf(const char *s1);

char	**ft_add_line_fdf(char **mat, char *line);

t_apex	get_apex_of_diamonds(t_point pt, t_img img, double angle);

t_vect		get_vect_btw_2_pts(t_ptdouble pt_a, t_ptdouble pt_b);

double		get_dist_btw_2_pts(t_ptdouble pt_a, t_ptdouble pt_b);

t_ptdouble	apply_vect(t_ptdouble pt, t_vect vect, double len);

double		get_coefxy(int coef_x, int coef_y);

void		print_apex(t_apex apex);
#endif
