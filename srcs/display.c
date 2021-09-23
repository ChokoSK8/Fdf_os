#include "fdf.h"

void	display_squares(t_img *img, t_map map)
{
	t_point		pt;
	t_display	disp;

	(void)map;
	disp = init_display(*img);
/*	pt.x = 0;
	pt.y = 0;
	print_diamonds(img, pt, img->size_line, disp);
	pt.x = 1;
	pt.y = 0;
	print_diamonds(img, pt, img->size_line, disp);*/
	pt.y = 0;
	while (map.data[pt.y])
	{
		pt.x = 0;
		while (map.data[pt.y][pt.x])
		{
			if (map.data[pt.y][pt.x] >= 48)
				print_diamonds(img, pt, img->size_line, disp);
			pt.x++;
		}
		pt.y++;
	}
}

void	print_diamonds(t_img *img, t_point pt, int size_line, t_display disp)
{
	int				pos;
	t_apex			apex;
	t_vect			vect;
	double			dist_2_pts;
	t_ptdouble		count;

	apex = get_apex_of_diamonds(pt, *img, disp);
//	print_apex(apex);

	//Line from A' to B'
	dist_2_pts = get_dist_btw_2_pts(apex.a, apex.b);
	count.x = apex.a.x;
	count.y = apex.a.y;
	vect = get_vect_btw_2_pts(apex.a, apex.b);
	while (get_dist_btw_2_pts(count, apex.a) < dist_2_pts)
	{
		pos = ((int)count.x * 4 + size_line * (int)count.y);
		img->data[pos] = 100;
		img->data[pos + 1] = 50;
		img->data[pos + 2] = 90;
		count = apply_vect(count, vect, 0.00001);
	}

	//Line from B' to D'
	dist_2_pts = get_dist_btw_2_pts(apex.b, apex.d);
	count.x = apex.b.x;
	count.y = apex.b.y;
	vect = get_vect_btw_2_pts(apex.b, apex.d);
	while (get_dist_btw_2_pts(count, apex.b) < dist_2_pts)
	{
		pos = ((int)count.x * 4 + size_line * (int)count.y);
		img->data[pos] = 100;
		img->data[pos + 1] = 50;
		img->data[pos + 2] = 90;
		count = apply_vect(count, vect, 0.00001);
	}

	//Line from A' to C'
	dist_2_pts = get_dist_btw_2_pts(apex.a, apex.c);
	count.x = apex.a.x;
	count.y = apex.a.y;
	vect = get_vect_btw_2_pts(apex.a, apex.c);
	while (get_dist_btw_2_pts(count, apex.a) < dist_2_pts)
	{
		pos = ((int)count.x * 4 + size_line * (int)count.y);
		img->data[pos] = 100;
		img->data[pos + 1] = 50;
		img->data[pos + 2] = 90;
		count = apply_vect(count, vect, 0.00001);
	}

	//Line from C' to D'
	dist_2_pts = get_dist_btw_2_pts(apex.c, apex.d);
	count.x = apex.c.x;
	count.y = apex.c.y;
	vect = get_vect_btw_2_pts(apex.c, apex.d);
	while (get_dist_btw_2_pts(count, apex.c) < dist_2_pts)
	{
		pos = ((int)count.x * 4 + size_line * (int)count.y);
		img->data[pos] = 100;
		img->data[pos + 1] = 50;
		img->data[pos + 2] = 90;
		count = apply_vect(count, vect, 0.00001);
	}
}
