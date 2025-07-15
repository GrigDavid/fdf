#include "fdf.h"

void	plotLineLow(t_params params, t_point *a, t_point *b)
{
	int	dx;
	int	dy;
	int	i;
	int	x;
	int	y;
	int	d;

	dx = b->x - a->x;
	dy = b->y - a->y;
	i = 1;
	if (dy < 0)
	{
		i = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	y = a->y;
	x = a->x;
	while (x <= b->x)
	{
		*(unsigned int *)(params.address + y * params.row_len + x * (params.pixel / 8)) = a->color;
		if(d > 0)
		{
			y += i;
			d += 2 * (dy - dx);
		}
		else
			d += 2 * dy;
		x++;
	}

}

void	plotLineHigh(t_params params, t_point *a, t_point *b)
{
	int	dx;
	int	dy;
	int	i;
	int	x;
	int	y;
	int	d;

	dx = b->x - a->x;
	dy = b->y - a->y;
	i = 1;
	if (dx < 0)
	{
		i = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	y = a->y;
	x = a->x;
	while (y <= b->y)
	{
		*(unsigned int *)(params.address + y * params.row_len + x * (params.pixel / 8)) = a->color;
		if(d > 0)
		{
			x += i;
			d += 2 * (dx - dy);
		}
		else
			d += 2 * dx;
		y++;
	}
}

/*
plotLineHigh(x0, y0, x1, y1)
    dx = x1 - x0
    dy = y1 - y0
    xi = 1
    if dx < 0
        xi = -1
        dx = -dx
    end if
    D = (2 * dx) - dy
    x = x0

    for y from y0 to y1
        plot(x, y)
        if D > 0
            x = x + xi
            D = D + (2 * (dx - dy))
        else
            D = D + 2*dx
        end if
*/

void	draw_line(t_params params, t_point *a, t_point *b)
{
	if (abs(b->y - a->y) < abs(b->x - a->x))
	{
		if (a->x > b->x)
			plotLineLow(params, b, a);
		else
			plotLineLow(params, a, b);
	}
	else
	{
		if (a->y > b->y)
			plotLineHigh(params, b, a);
		else
			plotLineHigh(params, a, b);
	}
}
/*
plotLine(x0, y0, x1, y1)
    if abs(y1 - y0) < abs(x1 - x0)
        if x0 > x1
            plotLineLow(x1, y1, x0, y0)
        else
            plotLineLow(x0, y0, x1, y1)
        end if
    else
        if y0 > y1
            plotLineHigh(x1, y1, x0, y0)
        else
            plotLineHigh(x0, y0, x1, y1)
        end if
    end if
*/

