/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:05:44 by abrun             #+#    #+#             */
/*   Updated: 2021/10/08 16:47:45 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_pts_equal(t_ptdbl pt_a, t_ptdbl pt_b)
{
	if (ft_abs(pt_a.x - pt_b.x) < 0.001 && ft_abs(pt_a.y - pt_b.y) < 0.001)
		return (1);
	return (0);
}

t_lines	get_eq_lines(t_apex apex)
{
	t_lines	lines;

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

int	is_pt_between_x(long double x_a, long double x_b, long double x_c)
{
	long double		dist_ab;
	long double		dist_bc;
	long double		dist_ac;

	dist_ab = x_b - x_a;
	dist_bc = x_c - x_b;
	dist_ac = x_c - x_a;
	if (dist_ab < dist_ac && dist_bc < dist_ac)
		return (1);
	return (0);
}

int	is_line_equal_to_eraser(t_line line, t_line eraser)
{
	if (line.a - eraser.a == 0 && line.b - eraser.b == 0)
		return (1);
	return (0);
}

int	is_ptlong_double_equal(t_ptdbl pt_a, t_ptdbl pt_b)
{
	if (pt_a.x == pt_b.x && pt_a.y == pt_b.y)
		return (1);
	return (0);
}
