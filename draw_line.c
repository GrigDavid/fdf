/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:57:40 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/07/29 18:27:42 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	plot_line_low(t_params p, t_point a, t_point b)
{
	int	dy;
	int	i;
	int	x;
	int	y;
	int	d;

	dy = (b.y - a.y);
	i = 1;
	if ((b.y - a.y) < 0)
		i = -1;
	d = 2 * i * dy - (b.x - a.x);
	y = a.y;
	x = a.x;
	while (x <= b.x)
	{
		*(unsigned int *)(p.add + y * p.row_len + x * (p.pixel / 8)) = a.color;
		if (d > 0)
		{
			y += i;
			d += 2 * (i * dy - (b.x - a.x));
		}
		else
			d += 2 * i * dy;
		x++;
	}
}

static void	plot_line_high(t_params p, t_point a, t_point b)
{
	int	dy;
	int	i;
	int	x;
	int	y;
	int	d;

	dy = b.y - a.y;
	i = 1;
	if ((b.x - a.x) < 0)
		i = -1;
	d = 2 * (b.x - a.x) - dy;
	y = a.y;
	x = a.x;
	while (y <= b.y)
	{
		*(unsigned int *)(p.add + y * p.row_len + x * (p.pixel / 8)) = a.color;
		if (d > 0)
		{
			x += i;
			d += 2 * (i * (b.x - a.x) - dy);
		}
		else
			d += 2 * (b.x - a.x) * i;
		y++;
	}
}

void	draw_line(t_params params, t_point a, t_point b)
{
	if (abs(b.y - a.y) < abs(b.x - a.x))
	{
		if (a.x > b.x)
			plot_line_low(params, b, a);
		else
			plot_line_low(params, a, b);
	}
	else
	{
		if (a.y > b.y)
			plot_line_high(params, b, a);
		else
			plot_line_high(params, a, b);
	}
}
