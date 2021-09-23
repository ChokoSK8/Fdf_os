#include "fdf.h"

int		init_param(t_param *param, char *file)
{
	int		ret;

	ret = init_map(&param->map, file);
	if (ret < 1)
		return (ret);
	init_param_len_and_coef(param);
	return (1);
}

void	init_param_len_and_coef(t_param *param)
{
	printf("max_width : %zu\n", param->map.max_width);
	param->img.coef_x = 600 / param->map.max_width;
	param->width = param->img.coef_x * (param->map.max_width + 8);
	param->img.coef_y = 400 / param->map.height;
	param->height = param->img.coef_y * (param->map.height + 8);
}

int		init_map(t_map *map, char *file)
{
	char		*line;
	int			fd;
	int			ret;
	int			count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	ret = get_next_line(fd, &line);
	if (ret < 1)
		return (ret);
	map->data = malloc(sizeof(char *));
	if (!map->data)
		return (-1);
	map->data[0] = 0;
	map->height = 0;
	map->max_width = 0;
	while (ret)
	{
		map->data = ft_add_line_fdf(map->data, line);
		if (map->max_width < ft_strlen(map->data[count]))
			map->max_width = ft_strlen(map->data[count]);
		if (!map->data)
			return (-1);
		free(line);
		ret = get_next_line(fd, &line);
		count++;
		map->height++;
	}
	close(fd);
	return (1);
}
