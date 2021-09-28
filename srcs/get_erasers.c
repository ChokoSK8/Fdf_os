#include "fdf.h"

t_eraser	get_erasers(t_lines lines)
{
	t_eraser	eraser;
	double		angle;
	double		tmp;

	angle = get_angle_from_pts(lines.ac, lines.ab);
	eraser = init_eraser(lines.ac, lines.ab);
	tmp = get_angle_from_pts(lines.ab, lines.bd);
	printf("angle A : %f\n", angle);
	if (angle < tmp)
	{
		eraser = init_eraser(lines.ab, lines.bd);
		angle = tmp;
	printf("angle B : %f\n", angle);
	}
	tmp = get_angle_from_pts(lines.bd, lines.cd);
	if (angle < tmp)
	{
		eraser = init_eraser(lines.bd, lines.cd);
		angle = tmp;
	printf("angle D : %f\n", angle);
	}
	tmp = get_angle_from_pts(lines.cd, lines.ac);
	if (angle < tmp)
	{
		eraser = init_eraser(lines.cd, lines.ac);
		angle = tmp;
	printf("angle C : %f\n", angle);
	}
	printf("angle : %f\n", angle);
	return (eraser);
}

double		get_angle_from_pts(t_line line_a, t_line line_b)
{
	double	angle;
	double	num;
	double	den;
	t_vect	vect_a;
	t_vect	vect_b;

	vect_a = get_vect_from_line(line_a);
	vect_b = get_vect_from_line(line_b);
	num = vect_a.x * vect_b.x + vect_a.y * vect_b.y;
	den = sqrt(pow(vect_a.x, 2) + pow(vect_a.y, 2)) + sqrt(pow(vect_b.x, 2) + pow(vect_b.y, 2));
	angle = convert_inv(acos(num / den));
	return (angle);
}

t_eraser	init_eraser(t_line line_a, t_line line_b)
{
	t_eraser	eraser;

	eraser.a = line_a;
	eraser.b = line_b;
	return (eraser);
}
