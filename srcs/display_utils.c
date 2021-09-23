#include "fdf.h"

t_apex		get_apex_of_diamonds(t_point pt, t_img img, double angle)
{
	t_apex	apex;

	apex.a.x = pt.x;
	apex.a.y = pt.y;
	apex.b.x = apex.a.x + cos(angle) * img.coef_x;
	apex.b.y = apex.a.y + sin(angle) * img.coef_x;
	apex.c.x = apex.a.x - sin(90 - angle) * img.coef_y;
	apex.c.y = apex.a.y + cos(90 - angle) * img.coef_y;
	apex.d.x = apex.c.x + cos(angle) * img.coef_x;
	apex.d.y = apex.c.y + sin(angle) * img.coef_x;
	return (apex);
}

t_vect		get_vect_btw_2_pts(t_ptdouble pt_a, t_ptdouble pt_b)
{
	t_vect		vect;

	vect.x = pt_b.x - pt_a.x;
	vect.y = pt_b.y - pt_a.y;
	return (vect);
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
