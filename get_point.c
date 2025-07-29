/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:57:27 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/07/29 16:00:32 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	coef = params.scale;
	dot.x = ((p.x - p.y) * ((coef * sqrt(3)) / 2));
	dot.y = coef * (-p.z + (p.x + p.y)) / 2;
	dot.color = p.color;
	if (cal)
	{
		calibrate(params, &dot);
		if (dot.x >= params.width || dot.x < 0)
		{
			dot.x = 0;
			dot.y = 0;
			dot.color = 0x000000;
		}
		if (dot.y >= params.height || dot.y < 0)
		{
			dot.x = 0;
			dot.y = 0;
			dot.color = 0x000000;
		}
	}
	return (dot);
}
