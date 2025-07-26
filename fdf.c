#include "fdf.h"

void	get_size(t_params *params, t_row *map)
{
	int	x_max;
	int	y_max;
	
	x_max = map->x;
	y_max = map->y;
	while (map)
	{
		if (map->x > x_max)
			x_max = map->x;
		if (map->y > y_max)
			y_max = map->y;
		map = map->next;
	}
	params->width = x_max + 200;
	params->width = y_max + 200;

}

t_point	*get_point(t_params params, t_row *point)
{
	int	xo;
	int	yo;
	t_point	*dot;
	int	coef;

	coef = 50;
	dot = (t_point *)malloc(sizeof(t_point));
	if (!dot)
		return (NULL);
	xo = params.width / 2;
	yo = params.height / 2;
	dot->x = (-(point->y - point->x) * ((coef *  sqrt(3)) / 2))  + xo; //sqrt3 / 2 = sin(PI / 3)
	dot->y = coef * (-point->z + (point->x + point->y)) / 2 + yo; //  1/2 = cos(PI / 3)
	// dot->x = fma(point->y - point->x, sqrt(3) / 2, params.width / 2);
	// dot->y = fma(point->x + point->y, 2, params.height / 2 - point->z);
	/*ft_putnbr_fd(dot->x, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(dot->y, 1);
	write(1, "\n\n", 2);*/
	/*int fd = open("dots", O_WRONLY | O_APPEND);
	write (fd, "(", 1);
	ft_putnbr_fd(dot->x, fd);
	write(fd, ", ", 2);
	ft_putnbr_fd(dot->y, fd);
	write(fd, "), ", 3);
	close(fd);*/
	dot->color = point->color;
	return (dot);
}

void	write_points(t_params params, t_row *map)
{
	int fd = open("dots", O_WRONLY | O_TRUNC);
	t_point	*dot;

	while (map)
	{
		dot = get_point(params, map);
		write (fd, "(", 1);
		ft_putnbr_fd(dot->x, fd);
		write(fd, ", ", 2);
		ft_putnbr_fd(dot->y, fd);
		write(fd, ")", 1);
		if (map->next)
			write(fd, ", ", 2);
		map = map->next;
	}
	close(fd);

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
			draw_line(params, get_point(params, tmp), get_point(params, point));
	}
	tmp = *map;
	if (point->x)
	{
		while (tmp && (tmp->x != (point->x) - 1 || tmp->y != point->y))
			tmp = tmp->next;
		if (tmp)
			draw_line(params, get_point(params, tmp), get_point(params, point));
	}
}


int	press_x(t_params *params)
{
	mlx_destroy_window(params->mlx, params->win);
	exit(0);
	return (1);
}


int	press_q(int keycode, t_params *params)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(params->mlx, params->win);
		exit(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_row	*map;

	if (argc != 2)
		return (0);
	// int	a[] = {210, 100, 50, 0xffffff};
	// int	b[] = {0, 0, 0, 0xffffff};

	// a = (int *)malloc(sizeof(int) * 4);
	// b = (int *)malloc(sizeof(int) * 4);
	// a
		/*t_row	*map1 = ft_rownew(0, 0, 0, 0xffffff);
	t_row	*map2 = ft_rownew(0, 10, 17, 0xffffff);
	draw_line(params, get_point(params, map1), get_point(params, map2));*/
	map = parser(argv[1]);
	if (!map)
		return (0);
	params.mlx = mlx_init();
	if (!params.mlx)
	{
		ft_printf("mlx failed\n");
		return (0);
	}
	params.win = mlx_new_window(params.mlx, params.width, params.height, "FBI Kennedy assasination files");
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
	t_row	*tmp = map;
	while (tmp)
	{
		get_neighbours(params, &map, tmp);
		tmp = tmp->next;
	}
	/*t_point	a = {100, 33, 0xffffff};
	t_point b = {457, 100, 0xffffff};
	draw_line(params, &a, &b);*/
	mlx_put_image_to_window(params.mlx, params.win, params.img, 0, 0);
	//ft_printf("qanak: %d", ft_rowsize(map));
	mlx_hook(params.win, 2, 1L<<0, press_q, &params);
	mlx_hook(params.win, 17, 0, press_x, &params);
	mlx_loop(params.mlx);
	return (0);
}

//gpt_wrote_this(mlx, win);
	// while (point[0] < 200)
	// {
	// 	draw_point(params, point);
	// 	point[0]++;
	// }




/*
void	did_I_cook(void *mlx, void *win)
{
	void	*img;
	char	*address;
	int		pixel;
	int		row_len;
	int		endian;

	img = mlx_new_image(mlx, 1200, 1200);
	address = mlx_get_data_addr(img, &pixel, &row_len, &endian);

	int	xo = 0;
	int	yo = 0;
	int	zo = 0;
	int	x;
	int	y;

	while (yo < 100)
	{
		x = floor((yo - xo) * sqrt(3) / 2 * (pixel / 8)); //sqrt3 / 2 = sin(PI / 3)
		y = floor(-zo + (xo + yo) / 2) * row_len; //  1/2 = cos(PI / 3)
		yo++;
		ft_putnbr_fd(y / row_len, 1);
		write(1, "\n", 1);
		ft_putnbr_fd(x, 1);
		write(1, "\n", 1);

	}
	*(unsigned int *)(address + y + x) = 0x00eaff;
	mlx_put_image_to_window(mlx, win, img, 0, 0);
}


int	main(void) //use xev for keyboard codes
{
	void *mlx;         // MLX instance
    void *win;         // Window

	int	height = 1200;
	int	width = 1200;
    mlx = mlx_init();
    win = mlx_new_window(mlx, width, height, "FBI Kennedy assasination files");
    //gpt_wrote_this(mlx, win);
	did_I_cook(mlx, win);
    mlx_loop(mlx);
}

*/

/*
void	gpt_wrote_this(void *mlx, void *win)
{
	void *img;         // Image buffer
    char *img_addr;    // Image data address
    int bits_per_pixel;
    int line_length;
    int endian;

    int width = 800;
    int height = 600;
	// Create an image
    img = mlx_new_image(mlx, width, height);

    // Get the image data address
    img_addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);

    // Draw a red pixel at (400, 300)
    int x = 0;
    int y = 0;
    int color = 0x00eaff; // Red in hex (RRGGBB)
	while (x++ < 400)
    	*(unsigned int *)(img_addr + y * line_length + x * (bits_per_pixel / 8)) = color;

    // Put the image to the window
    mlx_put_image_to_window(mlx, win, img, 0, 0);

}
*/

/*
void	draw_line(t_params params, t_point *a, t_point *b)
{
	int	dx = b->x - a->x;
	int	dy = b->y - a->y;
	int	i;
	int	x;
	int	y;
	int	p;

	if (dx < 0)
	{
		draw_line(params, b, a);
		return ;
	}
	if (dx)
	{
		ft_printf("now we rollin %d\n", dx);
		x = a->x;
		y = a->y;
		p = 2 * dy - dx;
		i = 0;
		while (i < dx)
		{
			*(unsigned int *)(params.address + y * params.row_len + (x + i) * (params.pixel / 8)) = 0xffffff;
			ft_printf("x is %d\ny in %d\n\n", x + i, y);
			p += 2 * dy;
			if (p > 0)
			{
				if (dy > 0)
					y++;
				else
					y--;
				p -=  2 * dx;
			}
			i++;
		}
	}
	
}*/

