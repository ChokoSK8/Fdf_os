#include "fdf.h"

t_apex		get_apex_of_diamonds(t_apex apex, t_display disp)
{
	apex.a = get_apex(disp, apex.a);
	apex.b = get_apex(disp, apex.b);
	apex.c = get_apex(disp, apex.c);
	apex.d = get_apex(disp, apex.d);
	return (apex);
}

t_ptdouble		get_apex(t_display disp, t_ptdouble pt)
{
	t_ptdouble	pt_a;

	pt_a.x = disp.origin.x + pt.x * disp.vect_x.x + pt.y * disp.vect_y.x;
	pt_a.y = disp.origin.y + pt.x * disp.vect_x.y + pt.y * disp.vect_y.y;
	return (pt_a);
}

t_vect		get_vect_btw_2_pts(t_ptdouble pt_a, t_ptdouble pt_b)
{
	t_vect		vect;

	vect.x = pt_b.x - pt_a.x;
	vect.y = pt_b.y - pt_a.y;
	return (vect);
}

double			convert(double degre)
{
	double rad;

	rad = degre / 57.2958;
	return (rad);
}

double			convert_inv(double rad)
{
	double degre;

	degre = 57.2958 * rad;
	return (degre);
}

double		get_dist_btw_2_pts(t_ptdouble pt_a, t_ptdouble pt_b)
{
	double		dist;

	dist = sqrt(pow(pt_a.x - pt_b.x, 2) + pow(pt_a.y - pt_b.y, 2));
	return (dist);
}

t_ptdouble	apply_vect(t_ptdouble pt, t_vect vect, double len)
{
	pt.x += (len * vect.x);
	pt.y += (len * vect.y);
	return (pt);
}

double		get_coefxy(int coef_x, int coef_y)
{
	double	dist;

	dist = sqrt(pow(coef_x, 2) + pow(coef_y, 2));
	return (dist);
}

void		print_apex(t_apex apex)
{
	printf("apex.a : (%f, %f)\n", apex.a.x, apex.a.y);
	printf("apex.b : (%f, %f)\n", apex.b.x, apex.b.y);
	printf("apex.c : (%f, %f)\n", apex.c.x, apex.c.y);
	printf("apex.d : (%f, %f)\n", apex.d.x, apex.d.y);
}

t_display		init_display(t_img img)
{
	t_display		disp;

	disp.origin.x = 500;
	disp.origin.y = 50;
	disp.angle = 45;
	disp.vect_x.x = cos(convert(disp.angle)) * img.coef_x;
	disp.vect_x.y = sin(convert(disp.angle)) * img.coef_x;
	disp.vect_y.x = -sin(convert(disp.angle)) * img.coef_y;
	disp.vect_y.y = cos(convert(disp.angle)) * img.coef_y;
	return (disp);
}

void		display_line(t_ptdouble apex_a, t_ptdouble apex_b, int size_line, t_img *img)
{
	t_vect		vect;
	t_ptdouble	count;
	t_ptdouble	witness;
	double		dist;
	int		pos;

	dist = get_dist_btw_2_pts(apex_a, apex_b);
	count.x = apex_a.x;
	count.y = apex_a.y;
	vect = get_vect_btw_2_pts(apex_a, apex_b);
	while (get_dist_btw_2_pts(count, apex_a) < dist)
	{
		pos = ((int)count.x * 4 + size_line * (int)count.y);
		img->data[pos] = 100;
		img->data[pos + 1] = 50;
		img->data[pos + 2] = 90;
		witness = count;
		while ((int)witness.x == (int)count.x && (int)witness.y == (int)count.y)
			count = apply_vect(count, vect, 0.001);
	}
}

t_apex		get_apex_inside(t_apex apex)
{
	t_apex		new;

	new.a = get_one_apex_inside(apex.a, apex.d);
	new.b = get_one_apex_inside(apex.b, apex.c);
	new.c = get_one_apex_inside(apex.c, apex.b);
	new.d = get_one_apex_inside(apex.d, apex.a);
	new = get_apex_biggest_line(new);
	return (new);
}

t_apex		get_apex_biggest_line(t_apex apex)
{
	t_apex	new;
	double	dist;
	double	dist_2;

	dist = get_dist_btw_2_pts(apex.a, apex.c);
	new.a = apex.a;
	new.b = apex.b;
	new.c = apex.c;
	new.d = apex.d;
	dist_2 = get_dist_btw_2_pts(apex.b, apex.d);
	if (dist < dist_2)
	{
		dist = dist_2;
		new.a = apex.d;
		new.b = apex.c;
		new.c = apex.b;
		new.d = apex.a;
	}
	dist_2 = get_dist_btw_2_pts(apex.c, apex.d);
	if (dist < dist_2)
	{
		dist = dist_2;
		new.a = apex.c;
		new.b = apex.a;
		new.c = apex.d;
		new.d = apex.b;
	}
	dist_2 = get_dist_btw_2_pts(apex.a, apex.b);
	if (dist < dist_2)
	{
		dist = dist_2;
		new.a = apex.b;
		new.b = apex.d;
		new.c = apex.a;
		new.d = apex.c;
	}
	return (new);
}

t_ptdouble	get_one_apex_inside(t_ptdouble pt_a, t_ptdouble pt_b)
{
	t_ptdouble		new;
	t_vect			vect;

	vect = get_vect_btw_2_pts(pt_a, pt_b);
	new.x= pt_a.x;
	new.y= pt_a.y;
	if (pt_a.x == pt_b.x && pt_a.y == pt_b.y)
		return (new);
	while (is_pts_equal(pt_a, new))
	{
		new = apply_vect(new, vect, 0.001);
	}
	return (new);
}

int		is_pts_equal(t_ptdouble pt_a, t_ptdouble pt_b)
{
	if (((int)pt_a.x != (int)pt_b.x &&
				(pt_a.y - pt_b.y > 0.2 || pt_a.y - pt_b.y < -0.2)) || 
				((int)pt_a.y != (int)pt_b.y && 
				(pt_a.x - pt_b.x > 0.2 || pt_a.x - pt_b.x < -0.2)))
		return (0);
	return (1);
}

t_ptdouble	get_pt_perpendiculare(t_lines lines, t_ptdouble pt)
{
	t_ptdouble	ab;
	t_ptdouble	bd;
	t_ptdouble	cd;
	t_line		perp;
	double		dist;
	t_ptdouble	res;

	perp.a = (-1) / lines.ac.a;
	perp.b = pt.y - pt.x * perp.a;
	ab.x = (perp.b - lines.ab.b) / (lines.ab.a - perp.a);
	ab.y = ab.x * perp.a + perp.b;
	bd.x = (perp.b - lines.bd.b) / (lines.bd.a - perp.a);
	bd.y = bd.x * perp.a + perp.b;
	cd.x = (perp.b - lines.cd.b) / (lines.cd.a - perp.a);
	cd.y = cd.x * perp.a + perp.b;
//	printf("pt : (%f, %f)\nab : (%f, %f)\nbd : (%f, %f)\ncd : (%f, %f)\n", pt.x, pt.y, ab.x, ab.y, bd.x, bd.y, cd.x, cd.y);
	dist = get_dist_btw_2_pts(pt, bd);
	res = bd;
	if ((lines.ab.a - perp.a > 0.1 || lines.ab.a - perp.a < -0.1)
			&& dist > get_dist_btw_2_pts(pt, ab))
	{
		dist = get_dist_btw_2_pts(pt, ab);
		res = ab;
	}
	if ((lines.cd.a - perp.a > 0.1 || lines.cd.a - perp.a < -0.1)
			&& dist > get_dist_btw_2_pts(pt, cd))
	{
		dist = get_dist_btw_2_pts(pt, cd);
		res = cd;
	}
	return (res);
}

t_lines		get_eq_lines(t_apex apex)
{
	t_lines		lines;

	lines.ac.a = (apex.a.y - apex.c.y) / (apex.a.x - apex.c.x);
	lines.ac.b = apex.a.y - lines.ac.a * apex.a.x;
	lines.ab.a = (apex.a.y - apex.b.y) / (apex.a.x - apex.b.x);
	lines.ab.b = apex.a.y - lines.ab.a * apex.a.x;
	lines.bd.a = (apex.b.y - apex.d.y) / (apex.b.x - apex.d.x);
	lines.bd.b = apex.b.y - lines.bd.a * apex.b.x;
	lines.cd.a = (apex.d.y - apex.c.y) / (apex.d.x - apex.c.x);
	lines.cd.b = apex.c.y - lines.cd.a * apex.c.x;
	return (lines);
}
