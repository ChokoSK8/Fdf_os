#include "fdf.h"

t_apex		get_apex_of_diamonds(t_point pt, t_img img, t_display disp)
{
	t_apex	apex;

	apex.a = get_apex_a(disp, pt);
	apex.b.x = apex.a.x + sin(convert(90 - disp.angle)) * img.coef_x;
	apex.b.y = apex.a.y + cos(convert(90 - disp.angle)) * img.coef_x;
	apex.c.x = apex.a.x - cos(convert(90 - disp.angle)) * img.coef_y;
	apex.c.y = apex.a.y + sin(convert(90 - disp.angle)) * img.coef_y;
	apex.d.x = apex.c.x + sin(convert(90 - disp.angle)) * img.coef_x;
	apex.d.y = apex.c.y + cos(convert(90 - disp.angle)) * img.coef_x;
	return (apex);
}

t_ptdouble		get_apex_a(t_display disp, t_point pt)
{
	t_ptdouble	pt_a;

	pt_a.x = disp.origin.x + pt.x * disp.vect_x.x + pt.y * disp.vect_y.y;
	pt_a.y = disp.origin.y + pt.y * disp.vect_y.x + pt.x * disp.vect_x.y;
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

	disp.origin.x = 600;
	disp.origin.y = 100;
	disp.angle = 45;
	disp.vect_x.x = sin(convert(90 - disp.angle)) * img.coef_x;
	disp.vect_x.y = cos(convert(90 - disp.angle)) * img.coef_x;
	disp.vect_y.x = -cos(convert(90 - disp.angle)) * img.coef_y;
	disp.vect_y.y = sin(convert(90 - disp.angle)) * img.coef_y;
	return (disp);
}
