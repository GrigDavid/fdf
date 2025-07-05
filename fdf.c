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

void	draw_point(t_params *params, int point[4])
{
	int	x;
	int	y;
	
	x = floor((point[1] - point[0]) * sqrt(3) / 2 * (params->pixel / 8)); //sqrt3 / 2 = sin(PI / 3)
	y = floor(-point[2] + (point[0] + point[1]) / 2) * params->row_len; //  1/2 = cos(PI / 3)
	*(unsigned int *)(params->address + y + x) = point[3];
	//mlx_put_image_to_window(params->mlx, params->win, params->img, 0, 0);
}


int	main(void) //use xev for keyboard codes
{
	t_params	*params;
	int	*point;

	point = (int *)malloc(sizeof(int) * 4);
	if (!point)
		return (0);
	point[0] = 100;
	point[1] = 500;
	point[2] = 100;
	point[3] = 0x00eaff;
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
	//did_I_cook(params.mlx, params.win);
	while (point[0] < 200)
	{
		draw_point(params, point);
		point[0]++;
	}
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