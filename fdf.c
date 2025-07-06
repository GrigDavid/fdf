#include "fdf.h"

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

void	draw_line(t_params *params, t_point *a, t_point *b)
{
	int	x;
	int	y;
	int	d;
	int	color = 0xffffff;

	x = a->x;
	y = a->y;//if both points are on the same x or y this crashes
	d = 2 * (b->y - a->y) - (b->x - a->x);
	ft_putnbr_fd(a->x, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(b->x, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(a->y, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(b->y, 1);
	write(1, "\n", 1);
	
	while (x <= b->x)
	{
		*(unsigned int *)(params->address + y * params->row_len + x * (params->pixel / 8)) = color;
		// ft_putnbr_fd(x, 1);
		// write(1, "\n", 1);
		// ft_putnbr_fd(y, 1);
		// write(1, "\n", 1);
		if (d > 0)
		{
			y++;
			d -= 2 * (b->x - a->x);
		}
		d += 2 * (b->y - a->y);
		x++;
	}ft_putstr_fd("hasa\n", 1);
	/*
	ft_putnbr_fd(a->x, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(a->y, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(b->x, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(b->y, 1);
	write(1, "\n", 1);*/
	// if (a->x > b->y)
	// {
	/*	x = a->x;
		while (x < b->x)
		{
			y = ceil((b->y - a->y) * (x - a->x) / (b->x - a->x)) + a->y;
			*(unsigned int *)(params->address + y * params->row_len + x * (params->pixel / 8)) = color;

			ft_putnbr_fd(x, 1);
			write(1, "\n", 1);

			ft_putnbr_fd(y, 1);
			write(1, "\n", 1);
			x++;
		}*/
	// }
	// else
	// {
	// 	x = b->x;
	// 	while (x < a->x)
	// 	{
	// 		y = (a->y - b->y) * (x - b->x) / (a->x - b->x) + b->y;
	// 		*(unsigned int *)(params->address + y * params->row_len + x * (params->pixel / 8)) = color;
	// 		x++;
	// 	}
	// }
	//*(unsigned int *)(params->address + y * params->row_len + x * (params->pixel / 8)) = color;
}

t_point	*get_point(t_params *params, int point[4])
{
	int	xo;
	int	yo;
	t_point	*dot;

	dot = (t_point *)malloc(sizeof(t_point));
	if (!dot)
		return (NULL);
	xo = params->width / 2;
	yo = params->height / 2;
	dot->x = floor(((point[1] - point[0]) * sqrt(3) / 2  + xo)); //sqrt3 / 2 = sin(PI / 3)
	dot->y = floor(-point[2] + (point[0] + point[1]) / 2 + yo); //  1/2 = cos(PI / 3)
	// ft_putnbr_fd(dot->x, 1);
	// write(1, "\n", 1);
	// ft_putnbr_fd(dot->y, 1);
	// write(1, "\n", 1);
	dot->color = point[3];
	return (dot);
	//mlx_put_image_to_window(params->mlx, params->win, params->img, 0, 0);
}


int	main(void) //use xev for keyboard codes
{
	t_params	*params;
	int	a[] = {210, 100, 50, 0xffffff};
	int	b[] = {0, 0, 0, 0xffffff};

	// a = (int *)malloc(sizeof(int) * 4);
	// b = (int *)malloc(sizeof(int) * 4);
	// a
	params = (t_params *)malloc(sizeof(t_params));
	if (!params)
		return (0);
	params->mlx = mlx_init();
	params->height = 1200;
	params->width = 1200;
    params->win = mlx_new_window(params->mlx, params->width, params->height, "FBI Kennedy assasination files");
	params->img = mlx_new_image(params->mlx, params->width, params->height);
	params->address = mlx_get_data_addr(params->img, &(params->pixel), &(params->row_len), &(params->endian));
    //gpt_wrote_this(mlx, win);
	// while (point[0] < 200)
	// {
	// 	draw_point(params, point);
	// 	point[0]++;
	// }
	draw_line(params, get_point(params, a), get_point(params, b));
	mlx_put_image_to_window(params->mlx, params->win, params->img, 0, 0);
    mlx_loop(params->mlx);
}






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