#include "fdf.h"

void	display_squares(t_img *img, t_map map)
{
	t_point		pt;

	(void)map;
	pt.x = 0;
	pt.y = 0;
	print_diamonds(img, pt, img->size_line);
/*	pt.y = 0;
	while (map.data[pt.y])
	{
		pt.x = 0;
		while (map.data[pt.y][pt.x])
		{
			if (map.data[pt.y][pt.x] >= 48)
				print_diamonds(img, pt, img->size_line);
			pt.x++;
		}
		pt.y++;
	}*/
}

void	print_cases(t_img *img, t_point pt, int size_line)
{
	int		pos;
	t_point		len_pix;
	t_point		offset;

	len_pix.x = 0;
	offset.x = img->coef_x * 4;
	offset.y = img->coef_y * 4;
	pt.x = (pt.x * img->coef_x) + offset.x;
	pt.y = (pt.y * img->coef_y) + offset.y;
	while (len_pix.x <= img->coef_x)
	{
		len_pix.y = 0;
		while (len_pix.y < img->coef_y)
		{
			pos = (pt.x + len_pix.x) * 4 +
					size_line * (pt.y + len_pix.y);
			img->data[pos] = 100;
			img->data[pos + 1] = 50;
			img->data[pos + 2] = 90;
			len_pix.y++;
		}
		len_pix.x += img->coef_x;
	}
	len_pix.y = 0;
	while (len_pix.y <= img->coef_y)
	{
		len_pix.x = 0;
		while (len_pix.x < img->coef_x)
		{
			pos = (pt.x + len_pix.x) * 4 +
					size_line * (pt.y + len_pix.y);
			img->data[pos] = 100;
			img->data[pos + 1] = 50;
			img->data[pos + 2] = 90;
			len_pix.x++;
		}
		len_pix.y += img->coef_y;
	}
}

void	print_diamonds(t_img *img, t_point pt, int size_line)
{
	int				pos;
	double			angle;
	t_point			offset;
	t_apex			apex;
	t_vect			vect;
	double			dist_2_pts;
	t_ptdouble		count;

	angle = 45;
	offset.x = img->coef_x * 4;
	offset.y = img->coef_y * 4;
	pt.x = (pt.x * img->coef_x) + offset.x;
	pt.y = (pt.y * img->coef_y) + offset.y;
	apex = get_apex_of_diamonds(pt, *img, angle);
	print_apex(apex);

	//Line from A' to B'
	dist_2_pts = get_dist_btw_2_pts(apex.a, apex.b);
	printf("dist : %f\n", dist_2_pts);
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
