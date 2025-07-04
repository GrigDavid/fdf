#include "fdf.h"

int	main(void) //xev
{
	void *mlx;         // MLX instance
    void *win;         // Window
    void *img;         // Image buffer
    char *img_addr;    // Image data address
    int bits_per_pixel;
    int line_length;
    int endian;

    int width = 800;
    int height = 600;

    // Initialize MLX
    mlx = mlx_init();

    // Create a window
    win = mlx_new_window(mlx, width, height, "MiniLibX Window");

    // Create an image
    img = mlx_new_image(mlx, width, height);

    // Get the image data address
    img_addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);

    // Draw a red pixel at (400, 300)
    int x = 300;
    int y = 300;
    int color = 0xFFFFFF; // Red in hex (RRGGBB)
	while (x++ < 400)
    	*(unsigned int *)(img_addr + y * line_length + x * (bits_per_pixel / 8)) = color;

    // Put the image to the window
    mlx_put_image_to_window(mlx, win, img, 0, 0);

    // Start the event loop (waits until window is closed)
    mlx_loop(mlx);
}
