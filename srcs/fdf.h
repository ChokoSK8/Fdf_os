/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:10:50 by abrun             #+#    #+#             */
/*   Updated: 2021/10/14 14:31:53 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <limits.h>
# include <float.h>
# include "../Minilibx-os/mlx.h"
# include "../Libft/libft.h"
# include "../Gnl/get_next_line.h"

typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct s_dists
{
	long double	h;
	long double	v;
}				t_dists;

typedef struct s_ptlong_double
{
	long double		x;
	long double		y;
}				t_ptdbl;

typedef struct s_vect
{
	long double		x;
	long double		y;
}				t_vect;

typedef struct s_vects
{
	t_vect	h;
	t_vect	v;
}				t_vects;

typedef struct s_line
{
	long double	a;
	long double	b;
}				t_line;

typedef struct s_eraser
{
	t_line	line;
	t_ptdbl	pt_a;
	t_ptdbl	pt_b;
}				t_erase;

typedef struct s_line_perp
{
	long double		a;
	long double		b;
	long double		x_1;
	long double		x_2;
}				t_lperp;

typedef struct s_ptperp
{
	long double	x;
	long double	y;
	int	btw;
}				t_ptperp;

typedef struct s_param_perp
{
	t_lperp		l_1;
	t_lperp		l_2;
	t_lperp		l_3;
	t_lperp		l_4;
	t_ptdbl		pt_1;
	t_ptdbl		pt_2;
	t_ptdbl		pt_3;
	int		btw_1;
	int		btw_2;
	int		btw_3;
	long double		dist_1;
	long double		dist_2;
	long double		dist_3;
}				t_pperp;

typedef struct s_lines
{
	t_line	ab;
	t_line	ac;
	t_line	bd;
	t_line	cd;
}				t_lines;

typedef struct s_display
{
	t_point		origin;
	t_vect		vect_x;
	t_vect		vect_y;
	long double		angle;
	int		alt;
}				t_disp;

typedef struct s_apex
{
	t_ptdbl	a;
	t_ptdbl	b;
	t_ptdbl	c;
	t_ptdbl	d;
}				t_apex;

typedef struct s_map
{
	char		**data;
	long double	**mati;
	size_t		max_width;
	size_t		height;
}				t_map;

typedef struct s_img
{
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
	void	*image;
	long double	coef_x;
	long double	coef_y;
}				t_img;

typedef struct s_param
{
	void		*mlx;
	void		*win;
	size_t		width;
	size_t		height;
	t_img		img;
	t_map		map;
	t_ptdbl		**mat_pos;
	long double		z_max;
	long double		z_min;
	long double	z;
	long double	div;
}				t_param;

int		ft_close_window(int key, t_param *param);

void	free_param(t_param *param);

int		init_map(t_map *map, char *file);

int		get_map_ready(t_map *map);

void	increase_params(t_map *map, char *line);

int		init_param(t_param *param, char *file);

void	init_param_len_and_coef(t_param *param);

void	display_squares(t_img *img, t_ptdbl **mat_pos);

void	print_cases(t_img *img, t_point pt, int size_line);

void	print_diamonds(t_img *img, t_ptdbl **mat_pos,
			t_point pt, t_disp disp);

char	*ft_strdup_fdf(const char *s1);

char	**ft_add_line_fdf(char **mat, char *line);

t_apex	get_apex_of_diamonds(t_apex apex, t_disp disp);

t_vect	get_vect_btw_2_pts(t_ptdbl pt_a, t_ptdbl pt_b);

long double	get_dist_btw_2_pts(t_ptdbl pt_a, t_ptdbl pt_b);

t_ptdbl	apply_vect(t_ptdbl pt, t_vect vect, long double len);

long double	get_coefxy(int coef_x, int coef_y);

void	print_apex(t_apex apex);

t_ptdbl	get_apex(t_disp disp, t_ptdbl pt);

t_disp	init_disp(t_img img);

long double	convert(long double degre);

long double	convert_inv(long double rad);

void	display_line(t_ptdbl apex_a, t_ptdbl apex_b,
			int size_line, t_img *img);

t_ptdbl	**get_mat_pos(t_map map, long double z);

void	print_mat_pos(t_ptdbl **mat);

long double		**ft_char_to_long_mat(char **matc, int max_width, t_param *param);

long double		*fill_one_lign(char **matc, t_point pt, int max_width, t_param *param);

long double		assign_one_digit(char **matc, t_point pt);

size_t	get_digit_len(char *str, int count);

char	*get_digit_from_str(char *str, int count);

void	free_matc(char **matc);

void	free_mati(int **matc);

void	free_mat_pos(t_ptdbl **mat_pos);

t_apex	get_apex_inside(t_apex apex);

void	print_inside_diamonds(t_img *img, t_apex apex);

int		is_pts_equal(t_ptdbl pt_a, t_ptdbl pt_b);

t_ptdbl	get_one_apex_inside(t_ptdbl pt_a, t_ptdbl pt_b);

t_apex	get_apex_biggest_line(t_apex apex);

t_ptdbl	get_pt_perpendiculare(t_lines lines, t_ptdbl pt);

t_lines	get_eq_lines(t_apex apex);

t_erase	get_erases(t_lines lines, t_apex apex);

long double	get_angle_from_pts(t_ptdbl pt_a, t_ptdbl pt_b, t_ptdbl pt_c);

t_erase	init_erase(t_ptdbl pt_a, t_ptdbl pt_b, t_line line);

t_vect	get_vect_from_line(t_line line);

void	erase_inside(t_apex apex, t_lines lines, t_img *img);

void	erase_from_one_lign(t_erase eraser, t_lines lines,
			t_img *img, t_apex apex);

int		is_perp_ok(t_ptdbl perp);

t_ptdbl	get_next_ptdbl(t_ptdbl pt, t_vect vect);

void	put_pixels(t_img *img, t_ptdbl pt);

void	put_pxl(t_img *img, t_ptdbl pt);

t_ptdbl	get_pt_perp(t_lines lines, t_ptdbl count,
			t_line eraser, t_apex apex);

t_pperp	init_pperp(t_lines lines, t_line eraser, t_apex apex);

t_ptdbl	pick_perp(t_pperp param);

void	init_lines_perp(t_pperp *param);

void	organize_param_perp(t_pperp *param);

t_lperp	assign_line_perp(t_line line, t_ptdbl pt_a, t_ptdbl pt_b);

int		is_line_equal_to_eraser(t_line line, t_line eraser);

int		is_pt_between_x(long double x_a, long double x_b, long double x_c);

int		is_apex_equal(t_apex apex);

int		is_ptlong_double_equal(t_ptdbl pt_a, t_ptdbl pt_b);

int		*add_n_in_tab(int *tab, int n, int tab_len);

int		is_n_in_tab(int n, int *tab, int tab_len);

void	organize_in_order_tab(int **tab, int tab_len);

void	swap_in_tab(int *a, int *b);

void	init_param_btw(t_pperp *param);

int		check_digit_lint(char *digit);

long double	ft_abs(long double a);

void	assign_param_z_limits(t_param *param, long double n);

int		get_next_pt_x(char **matc, t_point pt, int config);

char	**assign_the_line_and_z(char **matc, char *line, int count);

long double	assign_param_z(t_param param);

void	free_matldb(long double **matl);

long double	**div_matl(long double **matl, t_param *param, int len);

int		check_map_content(char **matc);

void		ft_print_matl(long double **m, int len);
#endif
