/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codeur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:21:58 by codeur            #+#    #+#             */
/*   Updated: 2021/10/14 14:59:52 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_param(t_param *param, char *file)
{
	if (init_map(&param->map, file) < 1)
		return (0);
	param->z_min = 2147483647;
	param->z_max = -2147483648;
	param->map.mati = ft_char_to_long_mat(param->map.data,
			param->map.max_width, param);
	init_param_len_and_coef(param);
	param->map.mati = div_matl(param->map.mati, param, param->map.max_width);
//	ft_print_matl(param->map.mati, param->map.max_width);
	if (!param->map.mati)
	{
		free_matc(param->map.data);
		return (0);
	}
	param->z = assign_param_z(*param);
//	printf("param->z : %Lf\n", param->z);
	param->mat_pos = get_mat_pos(param->map, param->z);
	if (!param->mat_pos)
	{
		free_matc(param->map.data);
		return (0);
	}
	return (1);
}

void	init_param_len_and_coef(t_param *param)
{
	param->width = 1200;
	param->height = 750;
	param->img.coef_y = (param->height - 100) / (1 / sin(convert(45)) * param->map.height);
	param->img.coef_x = (param->width - 100) / (1 / cos(convert(45)) * param->map.max_width);
}

int	init_map(t_map *map, char *file)
{
	char		*line;
	int			fd;
	int			ret;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (0);
	ret = get_next_line(fd, &line);
	if (ret < 1 || !get_map_ready(map))
		ret = -1;
	while (ret > 0)
	{
		map->data = ft_add_line_fdf(map->data, line);
		if (!map->data)
			break ;
		increase_params(map, line);
		free(line);
		ret = get_next_line(fd, &line);
	}
	free(line);
	close(fd);
	if (!map->data || !check_map_content(map->data))
		return (0);
	return (1);
}
