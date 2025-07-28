#include "fdf.h"

int	get_size(t_params *params, t_row *map)
{
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;
	t_point	p;

	p = get_point(*params, *map, 0);
	x_max = p.x;
	y_max = p.y;
	x_min = p.x;
	y_min = p.y;
	while (map)
	{
		p = get_point(*params, *map, 0);
		if (p.x > x_max)
			x_max = p.x;
		if (p.y > y_max)
			y_max = p.y;
		if (p.x < x_min)
			x_min = p.x;
		if (p.y < y_min)
			y_min = p.y;
		map = map->next;
	}
	params->x_mid = (x_max + x_min) / 2;
	params->y_mid = (y_max + y_min) / 2;
	return (1);
}

void	get_neighbours(t_params params, t_row **map, t_row *point)
{
	t_row	*tmp;

	tmp = *map;
	if (!point->x && !point->y)
		return ;
	if (point->y)
	{
		while (tmp && (tmp->y != (point->y) - 1 || tmp->x != point->x))
			tmp = tmp->next;
		if (tmp)
			draw_line(params, get_point(params, *tmp, 1), get_point(params, *point, 1));
	}
	tmp = *map;
	if (point->x)
	{
		while (tmp && (tmp->x != (point->x) - 1 || tmp->y != point->y))
			tmp = tmp->next;
		if (tmp)
			draw_line(params, get_point(params, *tmp, 1), get_point(params, *point, 1));
	}
}

int	thanos(t_params *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_destroy_window(params->mlx, params->win);
	mlx_destroy_display(params->mlx);
	free(params->mlx);
	exit(0);
	return (1);
}

int	press_esc(int keycode, t_params *params)
{
	if (keycode == XK_Escape)
		thanos(params);
	return (1);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_row		*map;
	t_row		*tmp;

	if (argc != 2)
		return (0);
	/*t_row	*map1 = ft_rownew(0, 0, 0, 0xffffff);
	t_row	*map2 = ft_rownew(0, 10, 17, 0xffffff);
	draw_line(params, get_point(params, map1), get_point(params, map2));*/
	params.mlx = mlx_init();
	if (!params.mlx)
	{
		ft_printf("mlx failed\n");
		return (0);
	}
	params.width = 1800;
	params.height = 1800;
	map = parser(argv[1]);
	if (!map)
		return (0);
	if (!get_size(&params, map))
	{
		return (1);
	}
	params.win = mlx_new_window(params.mlx, params.width, params.height, "fdf");
	if (!params.win)
	{
		ft_printf("window creation failed\n");
		return (0);
	}
	params.img = mlx_new_image(params.mlx, params.width, params.height);
	if (!params.img)
	{
		ft_printf("image creation failed\n");
		return (0);
	}
	params.address = mlx_get_data_addr(params.img, &(params.pixel), &(params.row_len), &(params.endian));
	if (!params.address)
	{
		ft_printf("address creation failed\n");
		return (0);
	}
	//write_points(params, map);
	tmp = map;
	while (tmp)
	{
		get_neighbours(params, &map, tmp);
		tmp = tmp->next;
	}
	ft_rowclear(&map);
	/*t_point	a = {100, 33, 0xffffff};
	t_point b = {457, 100, 0xffffff};
	draw_line(params, &a, &b);*/
	mlx_put_image_to_window(params.mlx, params.win, params.img, 0, 0);
	//ft_printf("qanak: %d", ft_rowsize(map));
	mlx_hook(params.win, 2, 1L << 0, press_esc, &params);
	mlx_hook(params.win, 17, 0, thanos, &params);
	//mlx_destroy_window(params.mlx, params.win);
	mlx_loop(params.mlx);
	return (0);
}
