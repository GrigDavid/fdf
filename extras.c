/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:23:23 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/07/29 18:25:28 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	update_x(t_point p, int *xmin, int *xmax)
{
	if (p.x > *xmax)
		*xmax = p.x;
	if (p.x < *xmin)
		*xmin = p.x;
}

static void	update_y(t_point p, int *ymin, int *ymax, t_row **map)
{
	if (p.y > *ymax)
		*ymax = p.y;
	if (p.y < *ymin)
		*ymin = p.y;
	*map = (*map)->next;
}

int	get_size(t_params *params, t_row *map)
{
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;
	t_point	p;

	params->scale = 1;
	if (!map)
		return (0);
	p = get_point(*params, *map, 0);
	x_max = p.x;
	y_max = p.y;
	x_min = p.x;
	y_min = p.y;
	map = map->next;
	while (map)
	{
		p = get_point(*params, *map, 0);
		update_x(p, &x_min, &x_max);
		update_y(p, &y_min, &y_max, &map);
	}
	params->scale = 1800 / (x_max - x_min);
	params->x_mid = params->scale * (x_max + x_min) / 2;
	params->y_mid = params->scale * (y_max + y_min) / 2;
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
			draw_line(params, get_point(params, *tmp, 1),
				get_point(params, *point, 1));
	}
	tmp = *map;
	if (point->x)
	{
		while (tmp && (tmp->x != (point->x) - 1 || tmp->y != point->y))
			tmp = tmp->next;
		if (tmp)
			draw_line(params, get_point(params, *tmp, 1),
				get_point(params, *point, 1));
	}
}
