#include "fdf.h"
/*
t_point	*get_point(t_params params, int x, int y, int z, int color)
{
	int	xo;
	int	yo;
	t_point	*dot;
	int	coef;

	coef = 50;
	dot = (t_point *)malloc(sizeof(t_point));
	if (!dot)
		return (NULL);
	xo = params.width / 2 - params.x_max / 2;
	yo = params.height / 2 - params.y_max / 2;
	dot->x = (-(y - x) * ((coef *  sqrt(3)) / 2))  + xo; //sqrt3 / 2 = sin(PI / 3)
	dot->y = coef * (-z + (x + y)) / 2 + yo; //  1/2 = cos(PI / 3)
	dot->color = color;
	dot->next = NULL;
	return (dot);
}*/

void	calibrate(t_params params, t_point *p)
{
	int	xo;
	int	yo;

	xo = params.width / 2 - params.x_mid;
	yo = params.height / 2 - params.y_mid;
	p->x += xo;
	p->y += yo;
}

t_point	get_point(t_params params, t_row p, int cal)
{
	t_point	dot;
	int		coef;

	//coef = (params.width - 400) / params.x_mid;
	coef = params.scale;
	dot.x = ((p.x - p.y) * ((coef * sqrt(3)) / 2));
	//dot.x = ((p.x - p.y) * ((coef * 866) / 200));
	dot.y = coef * (-p.z + (p.x + p.y)) / 2;
	dot.color = p.color;
	dot.next = NULL;
	if (cal){
		calibrate(params, &dot);
		if (dot.x >= params.width || dot.y >= params.height || dot.x < 0 || dot.y < 0)
		{
			dot.x = 0;
			dot.y = 0;
			dot.color = 0x000000;
		}
	}
	return (dot);
}

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
	close(fd);
*/