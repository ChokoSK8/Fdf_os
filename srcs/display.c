#include "fdf.h"

void	display_squares(t_img *img, t_ptdouble **mat_pos)
{
	t_point		pt;
	t_display	disp;

	disp = init_display(*img);
	pt.y = 0;
	while (mat_pos[pt.y])
	{
		pt.x = 0;
		while (mat_pos[pt.y][pt.x].x != -1)
		{
			print_diamonds(img, mat_pos, pt, disp);
			pt.x++;
		}
		pt.y++;
	}
}

void	print_diamonds(t_img *img, t_ptdouble **mat_pos, t_point pt, t_display disp)
{
	t_apex	apex;

	if (mat_pos[pt.y + 1] && mat_pos[pt.y][pt.x + 1].x != -1)
	{
		apex.a = mat_pos[pt.y][pt.x];
		apex.b = mat_pos[pt.y][pt.x + 1];
		apex.c = mat_pos[pt.y + 1][pt.x];
		apex.d = mat_pos[pt.y + 1][pt.x + 1];
		apex = get_apex_of_diamonds(apex, disp);
		display_line(apex.a, apex.b, img->size_line, img);
		display_line(apex.b, apex.d, img->size_line, img);
		display_line(apex.a, apex.c, img->size_line, img);
		display_line(apex.c, apex.d, img->size_line, img);
//		if (pt.y == 0 && pt.x == 0)
		//	print_inside_diamonds(img, apex);
	}
}

void	print_inside_diamonds(t_img *img, t_apex apex)
{
	t_apex	new;
	t_vect	vect_h;
	t_vect	vect_v;
	int		pos;
	double	dist_h;
	double	dist_v;
	t_ptdouble	count;
	t_ptdouble	pt_a;

	new = get_apex_inside(apex);
//	print_apex(apex);
//	print_apex(new);
	dist_h = get_dist_btw_2_pts(new.a, new.b);
	dist_v = get_dist_btw_2_pts(new.a, new.c);
	vect_v = get_vect_btw_2_pts(new.a, new.c);
	vect_h = get_vect_btw_2_pts(new.a, new.b);
	pt_a.x = new.a.x;
	pt_a.y = new.a.y;
	while (get_dist_btw_2_pts(new.a, pt_a) < dist_v)
	{
		count.x = new.a.x;
		count.y = new.a.y;
		while (get_dist_btw_2_pts(new.a, count) < dist_h)
		{
		//	printf("count : (%f, %f)\n", count.x, count.y);
			pos = ((int)count.x * 4 + img->size_line * (int)count.y);
			img->data[pos] = 20;
			img->data[pos + 1] = 100;
			img->data[pos + 2] = 10;
			count = apply_vect(count, vect_h, 0.001);
		}
		new.a = apply_vect(new.a, vect_v, 0.001); 
	}
}
